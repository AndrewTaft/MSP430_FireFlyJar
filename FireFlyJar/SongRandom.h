//***************************************************************************************
//  Andrew Taft
//  Nov 2013
//  Built with Code Composer Studio v5
//***************************************************************************************


#ifndef SONGRANDOM_H_
#define SONGRANDOM_H_

typedef void ( * PFN_PLAYSONG_CALLBACK_ON_EXIT_VOID_VOID )( void );
//example:
//void Main_OnExit(void);

void PlaySong_InitializeHW(void);
void PlaySong_InitializeApps(void);
void PlaySong_Entry(SPlaySongInfo const * ptPlaySongInfo);
void PlaySong_SetPlayMode(uint8_t);
void PlaySong_Stop();


#endif /* SONGRANDOM_H_ */
