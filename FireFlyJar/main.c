//***************************************************************************************
//  Andrew Taft
//  Nov 2013
//  Built with Code Composer Studio v5
//***************************************************************************************

#include <msp430.h>
#include <stdint.h>
#include <stdlib.h>

//*************************
// BIT SET FUNCTIONS
//*************************
#define bit_get(p,m) ((p) & (m))
#define bit_set(p,m) ((p) |= (m))
#define bit_clear(p,m) ((p) &= ~(m))
#define bit_flip(p,m) ((p) ^= (m))
#define bit_write(c,p,m) (c ? bit_set(p,m) : bit_clear(p,m))
#define BIT(x) (0x01 << (x))

#define FLOATING_ADC_FOR_RAND	INCH_10  	//temp sensor

#include "BCM.h"
#include "I2CMaster.h"
#include "CTS_Layer.h"

int adcGenRand8(void);

extern void bytePivot(uint8_t * src, uint8_t * dest);

uint8_t g_P1TimeSlice[BCM_RESOLUTION];
uint8_t g_P2TimeSlice[BCM_RESOLUTION];
uint8_t g_P3TimeSlice[BCM_RESOLUTION];

volatile uint8_t g_bitPosition = 0;

void main(void) {
	
	WDTCTL = WDTPW + WDTHOLD;             // Stop watchdog timer

	DCOCTL = 0;                           // Run at 8 MHz
	BCSCTL1 = CALBC1_8MHZ;                //
	DCOCTL = CALDCO_8MHZ;                 //
	BCSCTL3 |= LFXT1S1;					  // Set ACLK = Internal Osc

	__delay_cycles(100000);     // Wait ~100ms at default DCO of ~1MHz

	volatile unsigned int t1;
	volatile unsigned int t2;
	volatile unsigned int t3;
	volatile unsigned int t4;

	//get random
	srand(adcGenRand8());
t1 = rand();
	TA1CTL = TASSEL_2 + MC_2 + ID_0;         // Setup timer, continuous mode, SMCLK/1

	while(1)
	{

	uint8_t src[8];
	src[0] = 0xAA;
	src[1] = 0xFF;
	src[2] = 0x00;
	src[3] = 0x55;
	src[4] = 0xFF;
	src[5] = 0x00;
	src[6] = 0xFF;
	src[7] = 0x00;

	TA1CTL |= TACLR;
	t1 = TA1R;
	encodeTimeSliceAllPins(g_P1TimeSlice, src);
	t2 = TA1R;

	TA1CTL |= TACLR;
	t3 = TA1R;
	bytePivot(src, g_P1TimeSlice);
	t4 = TA1R;

	//set up all the ports
	P1OUT = 0x00;
	P2OUT = 0x00;
	P3OUT = 0x00;
	P2SEL = 0x00;
	P2SEL2 = 0x00;
	P1DIR = 0xFF;	//p1.6,p1.7 will be used by I2C data and clk
	P2DIR = 0x7F;	//p2.5 as cap touch, p2.7 as in for I2C Interrupt
	P3DIR = 0xFB;   //p3.3 as cap touch
	}
}


//BCM interupt on TIMER1_A0
#pragma vector = TIMER1_A1_VECTOR
__interrupt void Timer1_A1 (void)
{
	//clear interrupt flag
	volatile unsigned x = TA1IV;             // Clear interrupt flag
	g_bitPosition++;
	g_bitPosition &= 7; //keep values of 0-7
	//update the port values
	P1OUT = g_P1TimeSlice[g_bitPosition];
	//update the timer compare
	TA1CCR1 = BIT(g_bitPosition) << BCM_TIMER_OFFSET;
	TA1CTL |= TACLR;
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
