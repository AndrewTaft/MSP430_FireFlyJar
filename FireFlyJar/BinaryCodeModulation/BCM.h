/*
 * BCM.h
 *
 *  Created on: Nov 10, 2013
 *      Author: ataft
 */

#ifndef BCM_H_
#define BCM_H_

#define BCM_RESOLUTION 8
#define BCM_TIMER_OFFSET 8 //shifting 8 positions for now but that gets us ~122 Hz.  might try shifting 7(245Hz) or 6(490Hz)

void bcmInit(void);
void encodeTimeSliceAllPins(uint8_t *, uint8_t a[]);
void encodeTimeSlice(uint8_t *, uint8_t, uint8_t);
void clearTimeSlice(uint8_t *);
void pauseBCM(void);

#endif /* BCM_H_ */
