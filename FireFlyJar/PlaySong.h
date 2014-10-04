//***************************************************************************************
//  Andrew Taft
//  Nov 2013
//  Built with Code Composer Studio v5
//***************************************************************************************


#ifndef PLAYSONG_H_
#define PLAYSONG_H_

typedef void ( * PFN_PLAYSONG_CALLBACK_ON_EXIT_VOID_VOID )( void );
//example:
//void Main_OnExit(void);
typedef void ( * PFN_PLAYSONG_CALLBACK_BUTTON_DISABLE_VOID_VOID )( void );
typedef void ( * PFN_PLAYSONG_CALLBACK_BUTTON_ENABLE_VOID_VOID )( void );

typedef struct StructPlaySongInfo
//defines paramertes required to run the Playsong app
{
	//Point to the main state pointer
	PFN_STATE_VOID_VOID * ppfnHostState;

	//the callback to execute on exit
	PFN_PLAYSONG_CALLBACK_ON_EXIT_VOID_VOID pfnCallback_OnExit;

	//the callback to notify that buttons will be effected
	PFN_PLAYSONG_CALLBACK_BUTTON_DISABLE_VOID_VOID pfnCallback_ButtonDisable;
	PFN_PLAYSONG_CALLBACK_BUTTON_ENABLE_VOID_VOID pfnCallback_ButtonEnable;
} SPlaySongInfo;

void PlaySong_InitializeHW(void);
void PlaySong_InitializeApps(void);
void PlaySong_Entry(SPlaySongInfo const * ptPlaySongInfo);
void PlaySong_SetPlayMode(uint8_t);


#endif /* PLAYSONG_H_ */
