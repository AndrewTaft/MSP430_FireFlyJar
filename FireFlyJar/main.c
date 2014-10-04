//***************************************************************************************
//  Andrew Taft
//  Nov 2013
//  Built with Code Composer Studio v5
//***************************************************************************************

#include <msp430.h>
#include <stdint.h>

#include "MyTypes.h"
#include "system.h"
#include "PlaySong.h"

#include "CapTouchLib.h"


PFN_STATE_VOID_VOID g_pfnCurrentState;

uint8_t mPlayMode = 0;


void InitializeHW( void );
void InitializeApps( void );

void State_Default(void);

void LargeButtonPressed(void);
void OnPlaySongExit(void);
void OnDisableButtons(void);
void OnEnableButtons(void);

static const SPlaySongInfo mMain_tPlaySongInfo =
{
	&g_pfnCurrentState,
	OnPlaySongExit,
	OnDisableButtons,
	OnEnableButtons
};



void main(void) {
	
	WDTCTL = WDTPW + WDTHOLD;             // Stop watchdog timer

	g_pfnCurrentState = State_Default;

	InitializeHW();
	InitializeApps();

	//set watchdog on timer move to somewhere else
	WDTCTL = WDT_ADLY_16;
	IFG1 &= ~(WDTIFG);
	IE1 |= (WDTIE);

	__enable_interrupt();

	PlaySong_Entry(&mMain_tPlaySongInfo);
	PlaySong_SetPlayMode(mPlayMode);

	CapTouchLib_RegisterLargeButtonSink(LargeButtonPressed);

	while(1)
	{
		__low_power_mode_0();
		CapTouchLib_Tick();
		g_pfnCurrentState();
	}
}

void InitializeHW(void)
{
	System_InitializeHW();
	PlaySong_InitializeHW();
	CapTouchLib_InitializeHW();
}

void InitializeApps(void)
{
	PlaySong_InitializeApps();
	CapTouchLib_InitializeApp();
}

void State_Default(void)
{
}

void LargeButtonPressed(void)
{
	mPlayMode = (mPlayMode + 1) % 3;
	PlaySong_SetPlayMode(mPlayMode);
}

void OnPlaySongExit(void)
{
}

void OnDisableButtons(void)
{
	CapTouchLib_Disable();
}

void OnEnableButtons(void)
{
	CapTouchLib_Enable();
}

// Watchdog Timer interrupt service routine
#pragma vector=WDT_VECTOR
__interrupt void watchdog_timer(void)
{
	//uint8_t tmp = __get_SR_register_on_exit();
	//if(!(tmp & CPUOFF))
	//		mTimerMissed = 1;

	__low_power_mode_off_on_exit();
}
