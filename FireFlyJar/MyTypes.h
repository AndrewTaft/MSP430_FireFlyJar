/*
 * BITHandlers.h
 *
 *  Created on: Nov 18, 2013
 *      Author: ataft
 */

#ifndef MY_TYPES_H_
#define MY_TYPES_H_

#define bit_get(p,m) ((p) & (m))
#define bit_set(p,m) ((p) |= (m))
#define bit_clear(p,m) ((p) &= ~(m))
#define bit_flip(p,m) ((p) ^= (m))
#define bit_write(c,p,m) (c ? bit_set(p,m) : bit_clear(p,m))
#define BIT(x) (0x01 << (x))

typedef void ( * PFN_STATE_VOID_VOID ) (void);

#endif /* MY_TYPES_H_ */
