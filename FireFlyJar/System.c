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
	DCOCTL = 0;                           // Run at 8 MHz
	BCSCTL1 = CALBC1_8MHZ;                //
	DCOCTL = CALDCO_8MHZ;                 //
	BCSCTL3 |= LFXT1S1;					  // Set ACLK = Internal Osc

	//set up all the ports
	P1OUT = 0x00;
	P1SEL = (BIT6)+(BIT7);
	P1SEL2 = (BIT6)+(BIT7);
	P1DIR = 0xFF;	//p1.6,p1.7 will be used by I2C data and clk

//	//tmp changes to see clock rates
//	//set p1.0 to aclk
//	P1DIR |= (BIT0);
//	P1SEL |= (BIT0);
//	//set p1.4 for smclk
//	P1DIR |= (BIT4);
//	P1SEL |= (BIT4);


	//p2.5 as cap touch (enabled by Lib), p2.7 as in for I2C Interrupt
	P2OUT = 0x00;
	P2SEL = 0x00;
	P2SEL2 = 0x00;
	P2DIR = 0x7F;

	//p3.3 as cap touch (enabled by Lib)
	P3OUT = 0x00;
	P3SEL = 0x00;
	P3SEL2 = 0x00;
	P3DIR = 0xFB;


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
