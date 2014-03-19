/*
 * BCM.h
 *
 *  Created on: Nov 10, 2013
 *      Author: ataft
 */

#ifndef BCM_H_
#define BCM_H_

#define BCM_RESOLUTION 8
#define BCM_TIMER_OFFSET 7 //shifting 8 positions for now but that gets us ~122 Hz.  might try shifting 7(245Hz) or 6(490Hz)

#define PORT1  0
#define	PORT2  1
#define PORT3  2

void BCM_InitializeHW(void);
void BCM_InitializeApp(void);

void BCM_Stop(void);

void BCM_EncodeTimeSliceAllPins(uint8_t port, uint8_t *);

#endif /* BCM_H_ */
