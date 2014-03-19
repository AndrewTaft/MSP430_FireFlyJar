/*
 * CapTouchLib.h
 *
 *  Created on: Dec 15, 2013
 *      Author: ataft
 */

#ifndef CAPTOUCHLIB_H_
#define CAPTOUCHLIB_H_

typedef void ( * PFN_CAP_TOUCH_LIB_EVENT_SINK_VOID_VOID)(void);


void CapTouchLib_InitializeHW(void);
void CapTouchLib_InitializeApp(void);

void CapTouchLib_Tick(void);

//resets current button read.
//returns 1 when successfuly able to start button is sequence.  If 0 then try again next tick
uint8_t CapTouchLib_EnableSmallButton(void);
void CapTouchLib_DisableSmallButton(void);

void CapTouchLib_RegisterLargeButtonSink(PFN_CAP_TOUCH_LIB_EVENT_SINK_VOID_VOID pfnEventSink);
void CapTouchLib_RegisterSmallButtonSink(PFN_CAP_TOUCH_LIB_EVENT_SINK_VOID_VOID pfnEventSink);



#endif /*CAPTOUCHLIB_H_ */
