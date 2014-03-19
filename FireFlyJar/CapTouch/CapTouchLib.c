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
	PFN_CAP_TOUCH_LIB_EVENT_SINK_VOID_VOID pfnEventSink;
	uint16_t uiBaseSenseLevel;
	uint8_t uiPortSel2Address; //can be removed if both are on the same port
	uint8_t uiPin;
} SButtonInfo;

static SButtonInfo* mCapTouchLib_ptCurrentButton;
static SButtonInfo mCapTouchLib_tLargeButton;
static SButtonInfo mCapTouchLib_tSmallButton;


#define CAPTOUCHLIB_KEY_COMPARE     500 // Defines the min count for a "key press"
                                        // Set to ~ half the max delta expected
static uint16_t mCapTouchLib_uiMeasurementCount;
static uint16_t mCapTouchLib_uiDeltaCount;

//static PFN_STATE_VOID_VOID mCapTouchLib_pfnCurrentState;

void CapTouchLib_DefaultEventSink(void);

//states
void CapTouchLib_State_InitButton(void);
void CapTouchLib_State_WaitForPress(void);
void CapTouchLib_State_PressDelay(void);
void CapTouchLib_State_WaitForRelease(void);
void CapTouchLib_State_ReleaseDelay(void);

//Helpers
void CapTouchLib_EnterInitButton(void);
void CapTouchLib_EnterWaitForPress(void);
void CapTouchLib_EnterWaitForRelease(void);

void CapTouchLib_SetButtonForRead(void);

void CapTouchLib_InitializeHW( void )
{
	//set up the timer
	//TA0CTL = TASSEL_3 + MC_2;              // TACLK, cont mode
	TA0CTL = TASSEL_3 + ID_3 + MC_2;              // TACLK, cont mode, Divide input by 8 to deal with slower wdt
	TA0CCTL1 = CM_3+CCIS_2+CAP;            // Pos&Neg,GND,Cap

	//watchdog timer controlled externally
}

void CapTouchLib_InitializeApp( void )
{
	//set defaults with just LargeButton on
	mCapTouchLib_tLargeButton.uiPortSel2Address = &P2SEL2;
	mCapTouchLib_tLargeButton.uiPin = 0x20; //pin 5
	mCapTouchLib_tLargeButton.tNextButton = &mCapTouchLib_tLargeButton;

	mCapTouchLib_tSmallButton.uiPortSel2Address = &P3SEL2;
	mCapTouchLib_tSmallButton.uiPin = 0x08; //pin 3
	mCapTouchLib_tSmallButton.tNextButton = &mCapTouchLib_tLargeButton;

	mCapTouchLib_ptCurrentButton = &mCapTouchLib_tLargeButton;
	CapTouchLib_EnterInitButton();
}

void CapTouchLib_Tick(void)
{
	mCapTouchLib_ptCurrentButton->pfnCurrentState();
}

void CapTouchLib_RegisterLargeButtonSink(PFN_CAP_TOUCH_LIB_EVENT_SINK_VOID_VOID pfnEventSink)
{
	if(0 == pfnEventSink)
	{
		mCapTouchLib_tLargeButton.pfnEventSink = CapTouchLib_DefaultEventSink;
	}
	else
	{
		mCapTouchLib_tLargeButton.pfnEventSink = pfnEventSink;
	}
}

void CapTouchLib_RegisterSmallButtonSink(PFN_CAP_TOUCH_LIB_EVENT_SINK_VOID_VOID pfnEventSink)
{
	if(0 == pfnEventSink)
	{
		mCapTouchLib_tSmallButton.pfnEventSink = CapTouchLib_DefaultEventSink;
	}
	else
	{
		mCapTouchLib_tSmallButton.pfnEventSink = pfnEventSink;
	}
}

uint8_t CapTouchLib_EnableSmallButton(void)
{

	if((mCapTouchLib_ptCurrentButton == &mCapTouchLib_tLargeButton) && (mCapTouchLib_tLargeButton.pfnCurrentState == CapTouchLib_State_InitButton))
	{//large button is currently initing so we can not switch to the new button
		return 1;
	}
	mCapTouchLib_tLargeButton.tNextButton = &mCapTouchLib_tSmallButton;
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
	CapTouchLib_SetButtonForRead();
	mCapTouchLib_ptCurrentButton->pfnCurrentState = CapTouchLib_State_InitButton;
}

void CapTouchLib_State_InitButton(void)
{
	//get a reading to set on the current button value
	TA0CCTL1 ^= CCIS0;                   // Create SW capture of CCR1
	mCapTouchLib_ptCurrentButton->uiBaseSenseLevel = TA0CCR1;

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
	TA0CCTL1 ^= CCIS0;                   // Create SW capture of CCR1
	mCapTouchLib_uiMeasurementCount = TA0CCR1;

	if(mCapTouchLib_ptCurrentButton->uiBaseSenseLevel < mCapTouchLib_uiMeasurementCount)
	// Handle baseline measurment for a base C decrease
	{                                 // beyond baseline, i.e. cap decreased
		mCapTouchLib_ptCurrentButton->uiBaseSenseLevel = (mCapTouchLib_ptCurrentButton->uiBaseSenseLevel + mCapTouchLib_uiMeasurementCount) >> 1; // Re-average baseline up quickly
		mCapTouchLib_uiDeltaCount = 0;             // Zero out delta for position determination
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

	mCapTouchLib_ptCurrentButton = mCapTouchLib_ptCurrentButton->tNextButton;
	CapTouchLib_SetButtonForRead();
}


void CapTouchLib_State_PressDelay(void)
{
	//get a reading on the current button
	TA0CCTL1 ^= CCIS0;                   // Create SW capture of CCR1
	mCapTouchLib_uiMeasurementCount = TA0CCR1;

	if(mCapTouchLib_ptCurrentButton->uiBaseSenseLevel < mCapTouchLib_uiMeasurementCount)
	// Handle baseline measurment for a base C decrease
	{                                 // beyond baseline, i.e. cap decreased
		mCapTouchLib_ptCurrentButton->uiBaseSenseLevel = (mCapTouchLib_ptCurrentButton->uiBaseSenseLevel + mCapTouchLib_uiMeasurementCount) >> 1; // Re-average baseline up quickly
		mCapTouchLib_uiDeltaCount = 0;             // Zero out delta for position determination
	}
	else
	{
		mCapTouchLib_uiDeltaCount = mCapTouchLib_ptCurrentButton->uiBaseSenseLevel - mCapTouchLib_uiMeasurementCount;  // Calculate delta: c_change
	}

	if (mCapTouchLib_uiDeltaCount > CAPTOUCHLIB_KEY_COMPARE)       // Determine if each key is pressed per a preset threshold
	{
		//key pressed call event sink
		mCapTouchLib_ptCurrentButton->pfnEventSink();
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
	TA0CCTL1 ^= CCIS0;                   // Create SW capture of CCR1
	mCapTouchLib_uiMeasurementCount = TA0CCR1;

	if(mCapTouchLib_ptCurrentButton->uiBaseSenseLevel < mCapTouchLib_uiMeasurementCount)
	// Handle baseline measurment for a base C decrease
	{                                 // beyond baseline, i.e. cap decreased
		mCapTouchLib_ptCurrentButton->uiBaseSenseLevel = (mCapTouchLib_ptCurrentButton->uiBaseSenseLevel + mCapTouchLib_uiMeasurementCount) >> 1; // Re-average baseline up quickly
		mCapTouchLib_uiDeltaCount = 0;             // Zero out delta for position determination
	}
	else
	{
		mCapTouchLib_uiDeltaCount = mCapTouchLib_ptCurrentButton->uiBaseSenseLevel - mCapTouchLib_uiMeasurementCount;  // Calculate delta: c_change
	}

	if (mCapTouchLib_uiDeltaCount > CAPTOUCHLIB_KEY_COMPARE)       // Determine if each key is pressed per a preset threshold
	{
	}
	else
	{
		mCapTouchLib_ptCurrentButton->uiBaseSenseLevel -= 1;  // Adjust baseline down, should be slow to
		mCapTouchLib_ptCurrentButton->pfnCurrentState = CapTouchLib_State_ReleaseDelay;
	}

	mCapTouchLib_ptCurrentButton = mCapTouchLib_ptCurrentButton->tNextButton;
	CapTouchLib_SetButtonForRead();
}


void CapTouchLib_State_ReleaseDelay(void)
{
	//get a reading on the current button
	TA0CCTL1 ^= CCIS0;                   // Create SW capture of CCR1
	mCapTouchLib_uiMeasurementCount = TA0CCR1;

	if(mCapTouchLib_ptCurrentButton->uiBaseSenseLevel < mCapTouchLib_uiMeasurementCount)
	// Handle baseline measurment for a base C decrease
	{                                 // beyond baseline, i.e. cap decreased
		mCapTouchLib_ptCurrentButton->uiBaseSenseLevel = (mCapTouchLib_ptCurrentButton->uiBaseSenseLevel + mCapTouchLib_uiMeasurementCount) >> 1; // Re-average baseline up quickly
		mCapTouchLib_uiDeltaCount = 0;             // Zero out delta for position determination
	}
	else
	{
		mCapTouchLib_uiDeltaCount = mCapTouchLib_ptCurrentButton->uiBaseSenseLevel - mCapTouchLib_uiMeasurementCount;  // Calculate delta: c_change
	}

	if (mCapTouchLib_uiDeltaCount > CAPTOUCHLIB_KEY_COMPARE)       // Determine if each key is pressed per a preset threshold
	{
		//invalid release set back
		mCapTouchLib_ptCurrentButton->pfnCurrentState = CapTouchLib_State_WaitForRelease;
	}
	else
	{
		mCapTouchLib_ptCurrentButton->uiBaseSenseLevel -= 1;  // Adjust baseline down, should be slow to
		mCapTouchLib_ptCurrentButton->pfnEventSink();
		CapTouchLib_EnterWaitForPress();
		return;
	}

	mCapTouchLib_ptCurrentButton = mCapTouchLib_ptCurrentButton->tNextButton;
	CapTouchLib_SetButtonForRead();
}


void CapTouchLib_SetButtonForRead(void)
{
	//set up a read on the current button pins
	P2SEL2 = 0x00;  //these can be updated if all on one port
	P3SEL2 = 0x00;
	mCapTouchLib_ptCurrentButton->uiPortSel2Address |= mCapTouchLib_ptCurrentButton->uiPin;
	TA0CTL |= TACLR;                     // Clear Timer_A TAR
}

