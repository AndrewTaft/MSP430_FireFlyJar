/*
 * I2CMaster.h
 */

#ifndef I2C_MASTER_H_

#define I2C_MASTER_H_

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

#define		THRESH_FULL_LUX			0xFF
#define		THRESH_40_LUX			0x37
#define		THRESH_30_LUX			0x35
#define		THRESH_20_LUX			0x27
#define		THRESH_10_LUX			0x17
#define		THRESH_6_48_LUX			0x09
#define		THRESH_5_76_LUX			0x08
#define		THRESH_5_LUX			0x07
#define		THRESH_4_32_LUX			0x06
#define		THRESH_3_60_LUX			0x05
#define		THRESH_2_88_LUX			0x04
#define		THRESH_2_16_LUX			0x03
#define		THRESH_1_44_LUX			0x02
#define		THRESH_0_72_LUX			0x01
#define		THRESH_0_LUX			0x00

void I2C_Init( void );
uint8_t I2C_Maxim44009_SetTreshhold(uint8_t lowThreshhold, uint8_t highThreshhold);
double I2C_Maxim44009_GetLux(void);
uint8_t I2C_Maxim44009_GetLuxHighByte(void);

#endif /* I2C_MASTER_H_ */
