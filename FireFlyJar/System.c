//***************************************************************************************
//  Andrew Taft
//  Nov 2013
//  Built with Code Composer Studio v5
//***************************************************************************************

#include <msp430.h>
#include <stdint.h>
#include <stdlib.h>
#include "System.h"

int adcGenRand8(void);


void System_InitializeHW(void)
{
	//set clock
	DCOCTL = 0;                           // Run at 16 MHz
	BCSCTL1 = CALBC1_16MHZ;                //
	DCOCTL = CALDCO_16MHZ;                 //
	BCSCTL3 |= LFXT1S1;					  // Set ACLK = Internal Osc

	//set up all the ports
	P1OUT = 0x00;
	P1SEL = (BIT6)+(BIT7);
	P1SEL2 = (BIT6)+(BIT7);
	P1DIR = 0xFF;	//p1.1 is captouch 1(large button). p1.6,p1.7 is used by I2C data and clk

	//p2.3 as cap touch (enabled by Lib)
	P2OUT = 0x00;
	P2SEL = 0x00;
	P2SEL2 = 0x00;
	P2DIR = 0xFF;

	//p3.7 as in for I2C Interrupt
	P3OUT = 0x00;
	P3SEL = 0x00;
	P3SEL2 = 0x00;
	P3DIR = 0x7F;


	//initialize random num gen
	srand(adcGenRand8());
}

int System_Random()
{
	return rand();
}

int adcGenRand8(){
  char bit;
  unsigned char random;

  for(bit = 0; bit < 8; bit++){
    ADC10CTL1 |= FLOATING_ADC_FOR_RAND;
    ADC10CTL0 |= SREF_1 + ADC10SHT_1 + REFON + ADC10ON;
    ADC10CTL0 |= ENC + ADC10SC;
    while(ADC10CTL1 & ADC10BUSY);
    random <<= 1;
    random |= (ADC10MEM & 0x01);
  }
  return random;
}
