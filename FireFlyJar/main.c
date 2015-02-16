//***************************************************************************************
//  Andrew Taft
//  Nov 2013
//  Built with Code Composer Studio v5
//***************************************************************************************




//TODO:  large button controls on off
//TODO:  refactor Play Song into multiple classes.  One always one, One on when dark
//TODO:  small button switches play states
//TODO:  add storage of current play state to infomem on state change so restart enters correct one
//TODO:  check that PWM is off and timer is off when main type is off
//TODO:  add ability to change main WDT state calling times when system off and when in song that does not require a new open
//TODO:  how to record light threshold?  what UI?
//TODO:  create new song that syncros
//TODO:  new song types?




#include <msp430.h>
#include <stdint.h>

#include "MyTypes.h"
#include "system.h"
#include "SongRandom.h"

#include "CapTouchLib.h"


PFN_STATE_VOID_VOID g_pfnCurrentState;

//0 = false
uint8_t mSystemOn = 1;
uint8_t mPlayMode = 1;

void InitializeHW( void );
void InitializeApps( void );

void State_Default(void);

void LargeButtonPressed(void);
void LargeButtonReleased(void);

void SmallButtonPressed(void);
void SmallButtonReleased(void);


void OnDisableButtons(void);
void OnEnableButtons(void);

static const SPlaySongInfo mMain_tPlaySongInfo =
{
	&g_pfnCurrentState,
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

	//call turn on
	PlaySong_Entry(&mMain_tPlaySongInfo);

	CapTouchLib_RegisterLargeButtonPressSink(LargeButtonPressed);
	CapTouchLib_RegisterLargeButtonReleaseSink(LargeButtonReleased);


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
	//turn off all songs not full off
	//TODO:  this will be replaced by a function on Main not playsong
	PlaySong_Stop();

	//turn on some leds
	//TODO:  put this in a function
	P2OUT |= BIT4;
	P3OUT |= BIT0;
	P3OUT |= BIT2;

}

void LargeButtonReleased(void)
{
	//Turn off leds
	//TODO:  put this in a function like the above button press
	P2OUT &= ~(BIT4);
	P3OUT &= ~(BIT0+BIT2);

	//update system on/off and then respond
	mSystemOn = ~mSystemOn;

	if(mSystemOn)
	{
		//turn stuff on
	}
	else
	{
		//add stuff here to turn off further if needed
	}
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
