//***************************************************************************************
//  Andrew Taft
//  Nov 2013
//  Built with Code Composer Studio v5
//***************************************************************************************


#include <msp430.h>
#include <stdint.h>
#include <stdlib.h>

#include "MyTypes.h"
#include "PlaySong.h"
#include "BCM.h"
#include "I2CMaster.h"

static PFN_STATE_VOID_VOID * mPlaySong_ppfnHostState;

typedef struct {
	int16_t FlashPoint;
	int16_t FlashReset;
} PlaySong_FireflyMem;

typedef struct {
	uint8_t Port;
	uint8_t Pin;
} PlaySong_FireflyConst;

const uint8_t mPlaySong_auiMalePulse[50] = { /* pulse based on y=t*exp(t^2) */
0,37,74,107,140,168,194,215,230,244,251,254,255,254,251,246,236,224,210,195,178,162,146,130,
114,100,86,75,63,53,45,37,30,25,20,15,12,10,8,6,4,3,2,2,2,1,1,1,1,0
};

const uint8_t mPlaySong_auiFemalePulse[41] = { /* pulse based on y=t*exp(t^2) */
0,4,7,11,14,17,19,22,23,24,25,25,26,25,25,25,24,22,21,20,18,16,15,13,11,10,9,8,
6,5,5,4,3,3,2,2,1,1,1,1,0
};

static uint8_t mPlaySong_auiPortLevel[3][8] = {{0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0},
												{0,0,0,0,0,0,0,0}};

static PlaySong_FireflyMem mPlaySong_affFireflyMem[19];
static const PlaySong_FireflyConst mPlaySong_affFireflyConst[] = {
		{PORT1,0},
		{PORT1,1},
		{PORT1,2},
		{PORT1,3},
		{PORT1,4},
		{PORT1,5},
		{PORT2,0},
		{PORT2,1},
		{PORT2,2},
		{PORT2,3},
		{PORT2,4},
		{PORT2,6},
		{PORT3,0},
		{PORT3,1},
		{PORT3,2},
		{PORT3,4},
		{PORT3,5},
		{PORT3,6},
		{PORT3,7},
};

void PlaySong_State_WaitForDark(void);
void PlaySong_State_Playing_Synchronizing(void);
void PlaySong_State_Playing_RandomFlashers(void);

void PlaySong_Enter_WaitForDark(void);
void PlaySong_Enter_Playing(void);


void PlaySong_Synchronizing_Initialize(void);
void PlaySong_RandomFlashers_Initialize(void);


void PlaySong_InitializeHW(void)
{
	//set up the i2c light sensor
	I2C_Init();
	BCM_InitializeHW();
}

void PlaySong_InitializeApps(void)
{
	BCM_InitializeApp();
}

void PlaySong_Entry(PFN_STATE_VOID_VOID * ppfnHostState)
{
	mPlaySong_ppfnHostState = ppfnHostState;
	PlaySong_Enter_Playing();
}

void PlaySong_Enter_WaitForDark(void)
{
	//stop the BCM
	BCM_Stop();

	//check current lux level
	uint8_t luxHighByte = I2C_Maxim44009_GetLuxHighByte();

	//pull this value from somewhere else next
	if(THRESH_10_LUX > luxHighByte)
	{
		I2C_Maxim44009_SetTreshhold(THRESH_20_LUX, THRESH_FULL_LUX);

		//enable the p2.7 interrupts
		P2IES |= (BIT7);
		P2IFG &= ~(BIT7);
		P2IE |= (BIT7);

		//transition to new state
		*mPlaySong_ppfnHostState = PlaySong_State_WaitForDark;
	}
	else
	{
		PlaySong_Enter_Playing();
	}
}

void PlaySong_State_WaitForDark(void)
{
	//do nothing for now
}


void PlaySong_Enter_Playing(void)
{
	//set the on light alert
	//pull this value from somewhere else next
	I2C_Maxim44009_SetTreshhold(THRESH_0_LUX, THRESH_20_LUX);

	//enable the p2.7 interrupts
	P2IES |= (BIT7);
	P2IFG &= ~(BIT7);
	P2IE |= (BIT7);

	//init current song
	PlaySong_RandomFlashers_Initialize();

	BCM_EncodeTimeSliceAllPins(PORT1, mPlaySong_auiPortLevel[PORT1]);
	BCM_EncodeTimeSliceAllPins(PORT2, mPlaySong_auiPortLevel[PORT2]);
	BCM_EncodeTimeSliceAllPins(PORT3, mPlaySong_auiPortLevel[PORT3]);

	//transition to new state
	*mPlaySong_ppfnHostState = PlaySong_State_Playing_RandomFlashers;
}

void PlaySong_State_Playing_Synchronizing(void)
{

}

void PlaySong_Synchronizing_Initialize(void)
{

}

void PlaySong_State_Playing_RandomFlashers(void)
{
	uint8_t i;
	for(i = 0; i < 19; i++)
	{
		if(mPlaySong_affFireflyMem[i].FlashPoint++ < 0)
		{
			continue;
		}
		if(mPlaySong_affFireflyMem[i].FlashPoint >= 0)
		{
			mPlaySong_auiPortLevel[mPlaySong_affFireflyConst[i].Port][mPlaySong_affFireflyConst[i].Pin] = mPlaySong_auiMalePulse[mPlaySong_affFireflyMem[i].FlashPoint];
		}
		if(49 == mPlaySong_affFireflyMem[i].FlashPoint)
		{
			mPlaySong_affFireflyMem[i].FlashPoint = mPlaySong_affFireflyMem[i].FlashReset;
		}
	}

	BCM_EncodeTimeSliceAllPins(PORT1, mPlaySong_auiPortLevel[PORT1]);
	BCM_EncodeTimeSliceAllPins(PORT2, mPlaySong_auiPortLevel[PORT2]);
	BCM_EncodeTimeSliceAllPins(PORT3, mPlaySong_auiPortLevel[PORT3]);
}

#define BASE_RANDOM_FLASH_PERIOD -600

void PlaySong_RandomFlashers_Initialize(void)
{
	uint8_t i;
	for(i = 0; i < 19; i++)
	{
		//set the period for this fly
		mPlaySong_affFireflyMem[i].FlashReset = BASE_RANDOM_FLASH_PERIOD - rand() % 100;
		//set the start point for this fly
		mPlaySong_affFireflyMem[i].FlashPoint = 0-(rand() % mPlaySong_affFireflyMem[i].FlashReset);
		//clear the pin for this fly
		mPlaySong_auiPortLevel[mPlaySong_affFireflyConst[i].Port][mPlaySong_affFireflyConst[i].Pin] = 0;
	}
}


// Port 2 interrupt service routine
#pragma vector=PORT2_VECTOR
__interrupt void Port_2(void)
{
	//check if p2.7 was triggered
	if(P2IE & BIT7)
	{
		if(P2IFG & BIT7)
		{
			P2IE &= ~(BIT7);                           // P2.7 Interrupt disabled
		    P2IFG &= ~(BIT7);                           // P2.7 IFG cleared
		    if(*mPlaySong_ppfnHostState == PlaySong_State_WaitForDark)
		    {
		    	PlaySong_Enter_Playing();
		    	return;
		    }
		    if(*mPlaySong_ppfnHostState == PlaySong_State_Playing_Synchronizing)
		    {
		    	PlaySong_Enter_WaitForDark();
		    	return;
		    }
		    if(*mPlaySong_ppfnHostState == PlaySong_State_Playing_RandomFlashers)
		    {
		    	PlaySong_Enter_WaitForDark();
		    	return;
		    }
		}
	}
}
