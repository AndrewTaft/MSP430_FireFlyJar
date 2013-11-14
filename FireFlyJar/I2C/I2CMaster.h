/*
 * I2CMaster.h
 */

#ifndef I2C_MASTER_H_

#define I2C_MASTER_H_

#include <msp430.h>
#include <stdint.h>


// Device addresses, right justified
#define 	MAXIM_SLV_ADDR			0x4A

#define 	INT_STATUS_REG			0x00
#define 	INT_ENABLE_REG			0x01
#define 	CONFIGURATION_REG		0x02
#define		LUX_HIGH_REG	 		0x03
#define 	LUX_LOW_REG				0x04
#define 	HIGH_THRESH_REG			0x05
#define 	LOW_THRESH_REG			0x06
#define 	THRESH_TIMER_REG		0x07


// I have named just dummy function, use the functions in .c file
void I2CInit( void );
uint16_t I2CWrite( uint8_t , uint8_t * , uint16_t );
uint16_t I2CRead( uint8_t , uint8_t * , uint16_t );


#endif /* I2C_MASTER_H_ */
