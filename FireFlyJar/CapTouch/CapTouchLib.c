/*
 * CapTouchLib.c
 *
 *  Created on: Dec 15, 2013
 *      Author: ataft
 */

#include <msp430.h>
#include <stdint.h>

#include "MyTypes.h"
#include "CapTouchLib.h"



typedef struct StructButtonInfo
//defines the needs for a cap button
{
	PFN_STATE_VOID_VOID pfnCurrentState;
	struct StructButtonInfo* tNextButton;
	PFN_CAP_TOUCH_LIB_EVENT_SINK_VOID_VOID pfnPressEventSink;
	PFN_CAP_TOUCH_LIB_EVENT_SINK_VOID_VOID pfnReleaseEventSink;
	uint16_t uiBaseSenseLevel;
	uint8_t *uiPortSelAddress; //can be removed if both are on the same port
	uint8_t *uiPortSel2Address; //can be removed if both are on the same port
	uint8_t uiPin;
} SButtonInfo;

static SButtonInfo* mCapTouchLib_ptCurrentButton;
static SButtonInfo mCapTouchLib_tLargeButton;
static SButtonInfo mCapTouchLib_tSmallButton;


#define CAPTOUCHLIB_KEY_COMPARE     2500 // Defines the min count for a "key press"
                                        // Set to ~ half the max delta expected
static uint16_t mCapTouchLib_uiMeasurementCount;
static uint16_t mCapTouchLib_uiDeltaCount;
static uint8_t mCapTouchLib_ubContextSaveSel;
static uint8_t mCapTouchLib_ubContextSaveSel2;

//static PFN_STATE_VOID_VOID mCapTouchLib_pfnCurrentState;

void CapTouchLib_DefaultEventSink(void);

//states
void CapTouchLib_State_InitButton(void);
void CapTouchLib_State_WaitForPress(void);
void CapTouchLib_State_PressDelay(void);
void CapTouchLib_State_WaitForRelease(void);
void CapTouchLib_State_ReleaseDelay(void);
void CapTouchLib_State_Disabled(void);

//Helpers
void CapTouchLib_EnterInitButton(void);
void CapTouchLib_EnterWaitForPress(void);
void CapTouchLib_EnterWaitForRelease(void);

void CapTouchLib_SetButtonForRead(void);
void CapTouchLib_ReadButtonValue(void);


void CapTouchLib_InitializeHW( void )
{
	//set up the timer
	TA0CTL = TASSEL_3 + ID_3 + MC_2;              // TACLK, cont mode, Divide input by 8 to deal with slower wdt
	TA0CCTL1 = CM_3+CCIS_2+CAP;            // Pos&Neg,GND,Cap

	//watchdog timer controlled externally
}

void CapTouchLib_InitializeApp( void )
{
	//set defaults with just LargeButton on
	mCapTouchLib_tLargeButton.uiPortSelAddress = (uint8_t *)&P1SEL;
	mCapTouchLib_tLargeButton.uiPortSel2Address = (uint8_t *)&P1SEL2;
	mCapTouchLib_tLargeButton.uiPin = BIT1; //pin 1
	mCapTouchLib_tLargeButton.pfnPressEventSink = CapTouchLib_DefaultEventSink;
	mCapTouchLib_tLargeButton.pfnReleaseEventSink = CapTouchLib_DefaultEventSink;
	mCapTouchLib_tLargeButton.tNextButton = &mCapTouchLib_tLargeButton;

	mCapTouchLib_tSmallButton.uiPortSelAddress = (uint8_t *)&P2SEL;
	mCapTouchLib_tSmallButton.uiPortSel2Address = (uint8_t *)&P2SEL2;
	mCapTouchLib_tSmallButton.uiPin = BIT3; //pin 3
	mCapTouchLib_tSmallButton.pfnPressEventSink = CapTouchLib_DefaultEventSink;
	mCapTouchLib_tSmallButton.pfnReleaseEventSink = CapTouchLib_DefaultEventSink;
	mCapTouchLib_tSmallButton.tNextButton = &mCapTouchLib_tLargeButton;

	mCapTouchLib_ptCurrentButton = &mCapTouchLib_tLargeButton;
	CapTouchLib_EnterInitButton();
}

void CapTouchLib_Tick(void)
{
	mCapTouchLib_ptCurrentButton->pfnCurrentState();
}

void CapTouchLib_RegisterLargeButtonPressSink(PFN_CAP_TOUCH_LIB_EVENT_SINK_VOID_VOID pfnEventSink)
{
	if(0 == pfnEventSink)
	{
		mCapTouchLib_tLargeButton.pfnPressEventSink = CapTouchLib_DefaultEventSink;
	}
	else
	{
		mCapTouchLib_tLargeButton.pfnPressEventSink = pfnEventSink;
	}
}

void CapTouchLib_RegisterLargeButtonReleaseSink(PFN_CAP_TOUCH_LIB_EVENT_SINK_VOID_VOID pfnEventSink)
{
	if(0 == pfnEventSink)
	{
		mCapTouchLib_tLargeButton.pfnReleaseEventSink = CapTouchLib_DefaultEventSink;
	}
	else
	{
		mCapTouchLib_tLargeButton.pfnReleaseEventSink = pfnEventSink;
	}
}

void CapTouchLib_RegisterSmallButtonPressSink(PFN_CAP_TOUCH_LIB_EVENT_SINK_VOID_VOID pfnEventSink)
{
	if(0 == pfnEventSink)
	{
		mCapTouchLib_tSmallButton.pfnPressEventSink = CapTouchLib_DefaultEventSink;
	}
	else
	{
		mCapTouchLib_tSmallButton.pfnPressEventSink = pfnEventSink;
	}
}

void CapTouchLib_RegisterSmallButtonReleaseSink(PFN_CAP_TOUCH_LIB_EVENT_SINK_VOID_VOID pfnEventSink)
{
	if(0 == pfnEventSink)
	{
		mCapTouchLib_tSmallButton.pfnReleaseEventSink = CapTouchLib_DefaultEventSink;
	}
	else
	{
		mCapTouchLib_tSmallButton.pfnReleaseEventSink = pfnEventSink;
	}
}

uint8_t CapTouchLib_EnableSmallButton(void)
{

	if((mCapTouchLib_ptCurrentButton == &mCapTouchLib_tLargeButton) && (mCapTouchLib_tLargeButton.pfnCurrentState == CapTouchLib_State_InitButton))
	{//large button is currently initing so we can not switch to the new button
		return 1;
	}
	mCapTouchLib_tLargeButton.tNextButton = &mCapTouchLib_tSmallButton;
	CapTouchLib_ReadButtonValue();//close out the current read
	mCapTouchLib_ptCurrentButton = &mCapTouchLib_tSmallButton;
	CapTouchLib_EnterInitButton();

	return 0;
}

void CapTouchLib_DisableSmallButton(void)
{
	mCapTouchLib_tLargeButton.tNextButton = &mCapTouchLib_tLargeButton;
}

//do nothing when not registered
void CapTouchLib_DefaultEventSink(void)
{
}


void CapTouchLib_EnterInitButton(void)
{
	mCapTouchLib_ptCurrentButton->pfnCurrentState = CapTouchLib_State_InitButton;
}

void CapTouchLib_State_InitButton(void)
{
	mCapTouchLib_ptCurrentButton->uiBaseSenseLevel = 0;
	//go to next state on this button
	CapTouchLib_EnterWaitForPress();
}


void CapTouchLib_EnterWaitForPress(void)
{
	mCapTouchLib_ptCurrentButton->pfnCurrentState = CapTouchLib_State_WaitForPress;

	mCapTouchLib_ptCurrentButton = mCapTouchLib_ptCurrentButton->tNextButton;
	CapTouchLib_SetButtonForRead();
}

void CapTouchLib_State_WaitForPress(void)
{
	//get a reading on the current button
	CapTouchLib_ReadButtonValue();

	if(mCapTouchLib_ptCurrentButton->uiBaseSenseLevel == 0)
	{
		mCapTouchLib_ptCurrentButton->uiBaseSenseLevel = mCapTouchLib_uiMeasurementCount;
	}
	else
	{
		if(mCapTouchLib_ptCurrentButton->uiBaseSenseLevel < mCapTouchLib_uiMeasurementCount)
		// Handle baseline measurment for a base C decrease
		{                                 // beyond baseline, i.e. cap decreased
			mCapTouchLib_uiDeltaCount = 0;             // Zero out delta for position determination
			if(mCapTouchLib_ptCurrentButton->uiBaseSenseLevel+CAPTOUCHLIB_KEY_COMPARE < mCapTouchLib_uiMeasurementCount)
			{
				mCapTouchLib_uiMeasurementCount = mCapTouchLib_ptCurrentButton->uiBaseSenseLevel+CAPTOUCHLIB_KEY_COMPARE;
			}
			mCapTouchLib_ptCurrentButton->uiBaseSenseLevel = (mCapTouchLib_ptCurrentButton->uiBaseSenseLevel >> 1) + (mCapTouchLib_uiMeasurementCount >> 1); // Re-average baseline up quickly
		}
		else
		{
			mCapTouchLib_uiDeltaCount = mCapTouchLib_ptCurrentButton->uiBaseSenseLevel - mCapTouchLib_uiMeasurementCount;  // Calculate delta: c_change
		}

		if (mCapTouchLib_uiDeltaCount > CAPTOUCHLIB_KEY_COMPARE)       // Determine if each key is pressed per a preset threshold
		{
			//key pressed move to second check
			mCapTouchLib_ptCurrentButton->pfnCurrentState = CapTouchLib_State_PressDelay;
		}
		else
		{
			mCapTouchLib_ptCurrentButton->uiBaseSenseLevel -= 1;  // Adjust baseline down, should be slow to
		}
	}

	mCapTouchLib_ptCurrentButton = mCapTouchLib_ptCurrentButton->tNextButton;
	CapTouchLib_SetButtonForRead();
}


void CapTouchLib_State_PressDelay(void)
{
	//get a reading on the current button
	CapTouchLib_ReadButtonValue();

	if(mCapTouchLib_ptCurrentButton->uiBaseSenseLevel < mCapTouchLib_uiMeasurementCount)
	// Handle baseline measurment for a base C decrease
	{                                 // beyond baseline, i.e. cap decreased
		mCapTouchLib_uiDeltaCount = 0;             // Zero out delta for position determination
		if(mCapTouchLib_ptCurrentButton->uiBaseSenseLevel+CAPTOUCHLIB_KEY_COMPARE < mCapTouchLib_uiMeasurementCount)
		{
			mCapTouchLib_uiMeasurementCount = mCapTouchLib_ptCurrentButton->uiBaseSenseLevel+CAPTOUCHLIB_KEY_COMPARE;
		}
		mCapTouchLib_ptCurrentButton->uiBaseSenseLevel = (mCapTouchLib_ptCurrentButton->uiBaseSenseLevel >> 1) + (mCapTouchLib_uiMeasurementCount >> 1); // Re-average baseline up quickly
	}
	else
	{
		mCapTouchLib_uiDeltaCount = mCapTouchLib_ptCurrentButton->uiBaseSenseLevel - mCapTouchLib_uiMeasurementCount;  // Calculate delta: c_change
	}

	if (mCapTouchLib_uiDeltaCount > CAPTOUCHLIB_KEY_COMPARE)       // Determine if each key is pressed per a preset threshold
	{
		//key pressed call event sink
		mCapTouchLib_ptCurrentButton->pfnPressEventSink();
		CapTouchLib_EnterWaitForRelease();
	}
	else
	{
		//invalid press set back
		mCapTouchLib_ptCurrentButton->pfnCurrentState = CapTouchLib_State_WaitForPress;
	}

	mCapTouchLib_ptCurrentButton = mCapTouchLib_ptCurrentButton->tNextButton;
	CapTouchLib_SetButtonForRead();
}


void CapTouchLib_EnterWaitForRelease(void)
{
	mCapTouchLib_ptCurrentButton->pfnCurrentState = CapTouchLib_State_WaitForRelease;

	mCapTouchLib_ptCurrentButton = mCapTouchLib_ptCurrentButton->tNextButton;
	CapTouchLib_SetButtonForRead();
}

void CapTouchLib_State_WaitForRelease(void)
{
	//get a reading on the current button
	CapTouchLib_ReadButtonValue();

	if(mCapTouchLib_ptCurrentButton->uiBaseSenseLevel > mCapTouchLib_uiMeasurementCount)
	// Handle baseline measurment for a base C decrease
	{                                 // beyond baseline, i.e. cap decreased
		mCapTouchLib_uiDeltaCount = 0;             // Zero out delta for position determination
		if(mCapTouchLib_ptCurrentButton->uiBaseSenseLevel > CAPTOUCHLIB_KEY_COMPARE + mCapTouchLib_uiMeasurementCount)
		{
			mCapTouchLib_uiMeasurementCount = mCapTouchLib_ptCurrentButton->uiBaseSenseLevel-CAPTOUCHLIB_KEY_COMPARE;
		}
		mCapTouchLib_ptCurrentButton->uiBaseSenseLevel = (mCapTouchLib_ptCurrentButton->uiBaseSenseLevel >> 1) + (mCapTouchLib_uiMeasurementCount >> 1); // Re-average baseline up quickly
	}
	else
	{
		mCapTouchLib_uiDeltaCount = mCapTouchLib_ptCurrentButton->uiBaseSenseLevel - mCapTouchLib_uiMeasurementCount;  // Calculate delta: c_change
	}

	if (mCapTouchLib_uiDeltaCount > CAPTOUCHLIB_KEY_COMPARE)       // Determine if each key is pressed per a preset threshold
	{
		mCapTouchLib_ptCurrentButton->pfnCurrentState = CapTouchLib_State_ReleaseDelay;
	}
	else
	{
		mCapTouchLib_ptCurrentButton->uiBaseSenseLevel -= 1;  // Adjust baseline down, should be slow to
	}

	mCapTouchLib_ptCurrentButton = mCapTouchLib_ptCurrentButton->tNextButton;
	CapTouchLib_SetButtonForRead();
}


void CapTouchLib_State_ReleaseDelay(void)
{
	//get a reading on the current button
	CapTouchLib_ReadButtonValue();

	if(mCapTouchLib_ptCurrentButton->uiBaseSenseLevel > mCapTouchLib_uiMeasurementCount)
	// Handle baseline measurment for a base C decrease
	{                                 // beyond baseline, i.e. cap decreased
		mCapTouchLib_uiDeltaCount = 0;             // Zero out delta for position determination
		if(mCapTouchLib_ptCurrentButton->uiBaseSenseLevel > CAPTOUCHLIB_KEY_COMPARE + mCapTouchLib_uiMeasurementCount)
		{
			mCapTouchLib_uiMeasurementCount = mCapTouchLib_ptCurrentButton->uiBaseSenseLevel-CAPTOUCHLIB_KEY_COMPARE;
		}
		mCapTouchLib_ptCurrentButton->uiBaseSenseLevel = (mCapTouchLib_ptCurrentButton->uiBaseSenseLevel >> 1) + (mCapTouchLib_uiMeasurementCount >> 1); // Re-average baseline up quickly
	}
	else
	{
		mCapTouchLib_uiDeltaCount = mCapTouchLib_ptCurrentButton->uiBaseSenseLevel - mCapTouchLib_uiMeasurementCount;  // Calculate delta: c_change
	}

	if (mCapTouchLib_uiDeltaCount > CAPTOUCHLIB_KEY_COMPARE)       // Determine if each key is pressed per a preset threshold
	{
		//key released call event sink
		mCapTouchLib_ptCurrentButton->pfnReleaseEventSink();
		CapTouchLib_EnterWaitForPress();
	}
	else
	{
		//invalid release set back
		mCapTouchLib_ptCurrentButton->pfnCurrentState = CapTouchLib_State_WaitForRelease;
		mCapTouchLib_ptCurrentButton->uiBaseSenseLevel -= 1;  // Adjust baseline down, should be slow to
	}

	mCapTouchLib_ptCurrentButton = mCapTouchLib_ptCurrentButton->tNextButton;
	CapTouchLib_SetButtonForRead();
}

void CapTouchLib_State_Disabled(void)
{
	//do nothing
}


void CapTouchLib_SetButtonForRead(void)
{
	// Context Save
	mCapTouchLib_ubContextSaveSel = *(mCapTouchLib_ptCurrentButton->uiPortSelAddress);
	mCapTouchLib_ubContextSaveSel2 = *(mCapTouchLib_ptCurrentButton->uiPortSel2Address);
	// Configure Ports for relaxation oscillator
	*(mCapTouchLib_ptCurrentButton->uiPortSelAddress) &= ~(mCapTouchLib_ptCurrentButton->uiPin);
	*(mCapTouchLib_ptCurrentButton->uiPortSel2Address) |= (mCapTouchLib_ptCurrentButton->uiPin);

	TA0CTL |= TACLR;                     // Clear Timer_A TAR
}

void CapTouchLib_ReadButtonValue(void)
{
	//get a reading on the current button
	TA0CCTL1 ^= CCIS0;                   // Create SW capture of CCR1
	mCapTouchLib_uiMeasurementCount = TA0CCR1;

	// Context Restore
	*(mCapTouchLib_ptCurrentButton->uiPortSelAddress) = mCapTouchLib_ubContextSaveSel;
	*(mCapTouchLib_ptCurrentButton->uiPortSel2Address) = mCapTouchLib_ubContextSaveSel2;
}

void CapTouchLib_Disable(void)
{
	//set states to default
	mCapTouchLib_tLargeButton.pfnCurrentState = CapTouchLib_State_Disabled;
	mCapTouchLib_tSmallButton.pfnCurrentState = CapTouchLib_State_Disabled;
}

void CapTouchLib_Enable(void)
{
	//set states to init
	mCapTouchLib_tLargeButton.pfnCurrentState = CapTouchLib_State_InitButton;
	mCapTouchLib_tSmallButton.pfnCurrentState = CapTouchLib_State_InitButton;
}
