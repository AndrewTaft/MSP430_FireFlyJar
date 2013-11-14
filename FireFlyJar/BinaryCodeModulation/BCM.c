/*
 * BCM.c
 *
 *  Created on: Nov 10, 2013
 *      Author: ataft
 */
#include <msp430.h>
#include <stdint.h>

#include "BCM.h"


void bcmInit( void )
{
	//set up the timer
	TA1CTL = TASSEL_2 + MC_2 + ID_0;         // Setup timer, continuous mode, SMCLK/1
	TA1CCTL1 = CCIE;                         // Enable timer interrupt
	TA1CCR1 = 1 << BCM_TIMER_OFFSET;
}

void pauseBCM( void )
{
	//disable timer interrupt
	//turn off timer
	//set all ports to 0
}

void clearTimeSlice(uint8_t * timeSlice)
{
	uint8_t i;
	//set all the time slices to 0
	for(i = 0; i<BCM_RESOLUTION; i++)
	{
		timeSlice[i] = 0x00;
	}
}

void encodeTimeSlice(uint8_t * timeSlice, uint8_t pin, uint8_t value)
{
	//loop through each timeslice value
	uint8_t i;
	for(i = 0; i<BCM_RESOLUTION; i++)
	{
		//set the pin on or off in the timeslice
		(value & (1 << i)) ? (timeSlice[i] |= (1 << i)) :  (timeSlice[i] &= ~(1 << i));
	}
}

void encodeTimeSliceAllPins(uint8_t * timeSlice, uint8_t values[])
{
	uint8_t portbits = 0;
	uint8_t bitvalue;

	uint8_t bitpos;
	for(bitpos = 0; bitpos < BCM_RESOLUTION; bitpos++)
	{
		portbits = 0;
		bitvalue = 1;
		uint8_t pin;
		for( pin = 0; pin < 8; pin++)
		{
			if(values[pin] & (1 << bitpos)) portbits |= bitvalue;
			bitvalue = bitvalue << 1;
		}
		timeSlice[bitpos] = portbits;
	}
}

