/*
 * BCM.c
 *
 *  Created on: Nov 10, 2013
 *      Author: ataft
 */
#include <msp430.h>
#include <stdint.h>

#include "MyTypes.h"
#include "BCM.h"




//this is a 2 dimensional array, the first dimmension is the port number
//the second is the time slice in decending order with the 0 index = lsb and 7 = msb of each pwm value
static uint8_t mBCM_uiTimeSlices[3][BCM_RESOLUTION];
static volatile uint8_t mBCM_uiBitPosition = 0;

static PFN_STATE_VOID_VOID mBCM_pfnMode;

static union BCM_PinOn
{
	uint32_t fullFlag;
	uint8_t port[4];
} mBCM_uiPinOn;


void BCM_Mode_On( void );
void BCM_Mode_Off( void );
void BCM_UpdateMode(void);


void BCM_InitializeHW( void )
{
	//set up the timer
	TA1CTL = TASSEL_2 + ID_0;         // Setup timer, SMCLK/1
}

void BCM_InitializeApp( void )
{
	mBCM_uiPinOn.fullFlag = 0;
	mBCM_pfnMode = BCM_Mode_Off;
}

void BCM_Stop(void)
{
	mBCM_uiPinOn.fullFlag = 0;
	mBCM_pfnMode = BCM_Mode_On;
	BCM_UpdateMode();
}

void BCM_UpdateMode(void)
{
	mBCM_pfnMode();
}

void BCM_Mode_On( void )
{
	if(!mBCM_uiPinOn.fullFlag)
	//no pins on so turn off
	{
		TA1CCTL1 &= ~CCIE;                         // Disable timer interrupt
		TA1CTL &= ~((MC0)&(MC1));						//turn off timer
		P1OUT = 0x00;							//set all ports to 0
		P2OUT = 0x00;
		P3OUT = 0x00;

		mBCM_pfnMode = BCM_Mode_Off;
	}

	//some pin on so do nothing

}

void BCM_Mode_Off( void )
{
	if(mBCM_uiPinOn.fullFlag)
	//some pin on so turn on
	{
		TA1CTL |= MC1;					//continuous mode
		TA1CTL &= ~(MC0);				//continuous mode

		TA1CCTL1 |= CCIE;                         // Enable timer interrupt
		TA1CCR1 = 1 << BCM_TIMER_OFFSET;		//set first stop

		mBCM_pfnMode = BCM_Mode_On;
	}

	//all pins off so do nothing
}

//void BCM_ClearTimeSlice(gBCM_tPort port)
//{
//	uint8_t i;
//	//set all the time slices to 0
//	for(i = 0; i<BCM_RESOLUTION; i++)
//	{
//		mBCM_uiTimeSlices[port][i] = 0x00;
//	}
//}

//void BCM_EncodeTimeSlice(gBCM_tPort port, uint8_t pin, uint8_t value)
//{
//	//loop through each timeslice value
//	uint8_t i;
//	for(i = BCM_RESOLUTION-1; i==0; i--)
//	{
//		//set the pin on or off in the timeslice
//		(value & (1 << i)) ? (mBCM_uiTimeSlices[port][i] |= (1 << i)) :  (mBCM_uiTimeSlices[port][i] &= ~(1 << i));
//	}
//}

extern void BCM_BytePivot(uint8_t * src, uint8_t * dest, uint8_t * pinFlag);
void BCM_EncodeTimeSliceAllPins(uint8_t port, uint8_t * values)
{
	//uint16_t isInterruptState = __get_SR_register();
	//__disable_interrupt();
	BCM_BytePivot(values, mBCM_uiTimeSlices[port], &mBCM_uiPinOn.port[port]);
	mBCM_pfnMode();
	//_bis_SR_register(isInterruptState);
//	uint8_t portbits = 0;
//	uint8_t bitvalue;
//
//	uint8_t bitpos;
//	for(bitpos = 0; bitpos < BCM_RESOLUTION; bitpos++)
//	{
//		portbits = 0;
//		bitvalue = 1;
//		uint8_t pin;
//		for( pin = 0; pin < 8; pin++)
//		{
//			if(values[pin] & (1 << bitpos)) portbits |= bitvalue;
//			bitvalue = bitvalue << 1;
//		}
//		mBCM_uiTimeSlices[port][bitpos] = portbits;
//	}
}

//BCM interupt on TIMER1_A0
#pragma vector = TIMER1_A1_VECTOR
__interrupt void Timer1_A1 (void)
{
	//clear interrupt flag
	volatile unsigned x = TA1IV;             // Clear interrupt flag
	mBCM_uiBitPosition++;
	mBCM_uiBitPosition &= 7; //keep values of 0-7
	//update the port values
	P1OUT = mBCM_uiTimeSlices[PORT1][mBCM_uiBitPosition];
	P2OUT = mBCM_uiTimeSlices[PORT2][mBCM_uiBitPosition];
	P3OUT = mBCM_uiTimeSlices[PORT3][mBCM_uiBitPosition];
	//update the timer compare
	TA1CCR1 = BIT(mBCM_uiBitPosition) << BCM_TIMER_OFFSET;
	TA1CTL |= TACLR;
}
