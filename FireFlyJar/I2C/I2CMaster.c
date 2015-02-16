/*
 * I2CMaster.c
 */

#include <msp430.h>
#include <stdint.h>

#include "I2CMaster.h"

static volatile uint16_t I2CNumBytes;
static volatile uint8_t Ack;
static volatile uint8_t * I2CRxBuffer;
static volatile uint8_t * I2CTxBuffer;
static volatile uint16_t I2CStop;

uint8_t I2C_Write( uint8_t , uint8_t * , uint16_t );
uint8_t I2C_Read( uint8_t , uint8_t * , uint16_t );

#ifdef MAXIM

uint8_t I2C_Device_SetTreshhold(uint8_t lowThreshhold, uint8_t highThreshold)
{
	uint8_t writeVal[2];
	//set up to go from light to dark
	//turn off INT to clear value
	writeVal[0] = INT_ENABLE_REG;
	writeVal[1] = 0x00;
	if (!I2C_Write(DEVICE_SLV_ADDR, writeVal, 2))
	{
		return 0;
	}

	writeVal[0] = LOW_THRESH_REG;
	writeVal[1] = lowThreshhold;
	if (!I2C_Write(DEVICE_SLV_ADDR, writeVal, 2))
	{
		return 0;
	}

	writeVal[0] = HIGH_THRESH_REG;
	writeVal[1] = highThreshold;
	if (! I2C_Write(DEVICE_SLV_ADDR, writeVal, 2))
	{
		return 0;
	}

	writeVal[0] = THRESH_TIMER_REG;
	writeVal[1] = 0x05;
	if (!I2C_Write(DEVICE_SLV_ADDR, writeVal, 2))
	{
		return 0;
	}

	writeVal[0] = INT_ENABLE_REG;
	writeVal[1] = 0x01;
	if (!I2C_Write(DEVICE_SLV_ADDR, writeVal, 2))
	{
		return 0;
	}

	return 1;

}

double I2C_Device_GetLux(void)
{
	uint8_t high;
	uint8_t low;

	uint8_t writeVal[2];
	uint8_t retVal;

	//__enable_interrupt();


	//read from MAXIM CHIP
	writeVal[0] = INT_STATUS_REG;
	//retVal = I2C_Write(DEVICE_SLV_ADDR, writeVal, 1);
	//retVal = I2C_Read(DEVICE_SLV_ADDR, &val, 1);

	//read lux value
	writeVal[0] = LUX_HIGH_REG;
	retVal = I2C_Write(DEVICE_SLV_ADDR, writeVal, 1);
	retVal = I2C_Read(DEVICE_SLV_ADDR, &high, 1);

	writeVal[0] = LUX_LOW_REG;
	retVal = I2C_Write(DEVICE_SLV_ADDR, writeVal, 1);
	retVal = I2C_Read(DEVICE_SLV_ADDR, &low, 1);

	volatile uint8_t e = (high >> 4) & 0x0F;

	volatile uint16_t lux = 1;
	while(e>0)
	{
	  lux *= 2;
	  e--;
	}
	volatile uint8_t m = high & 0x0F;
	volatile double lowLux = lux * m * 0.72;


	m = m << 4;
	m = m | (0x0F & low);

	volatile double highLux = lux * m * 0.045;

	return highLux;
}

uint8_t I2C_Device_GetLuxHighByte(void)
{
	uint8_t high;
	uint8_t reg = LUX_HIGH_REG;
	//read lux value
	I2C_Write(DEVICE_SLV_ADDR, &reg, 1);
	I2C_Read(DEVICE_SLV_ADDR, &high, 1);

	return high;
}

#endif


#ifdef INTERSIL

uint8_t I2C_Device_SetTreshhold(uint8_t lowThreshhold, uint8_t highThreshold)
{
	return 0;
}

double I2C_Device_GetLux(void)
{
	uint8_t writeVal[2];
	//set up to go from light to dark
	//turn off INT to clear value
	writeVal[0] = COMMANDI_REG;
	writeVal[1] = COMMAND_ALS_CONTINUOUS;
	if (!I2C_Write(DEVICE_SLV_ADDR, writeVal, 2))
	{
		return 0;
	}

	uint8_t reg = DATA_LSB_REG;
	//read lux value
	I2C_Write(DEVICE_SLV_ADDR, &reg, 1);
	I2C_Read(DEVICE_SLV_ADDR, &writeVal, 2);

	return 0;
}

uint8_t I2C_Device_GetLuxHighByte(void)
{
	return 0;
}

#endif


void I2C_Init( void )
{
    UCB0CTL1 |= UCSWRST;                    // Enable SW reset
    UCB0CTL0 = UCMST + UCMODE_3 + UCSYNC;    // 7-bit addressing, single-master environment, I2C Master, synchronous mode
    UCB0CTL1 = UCSSEL_2 + UCSWRST;            // Use SMCLK, keep SW reset
    UCB0BR0 = 80;                   		 // fSCL = SMCLK/UCB0BR1
    UCB0BR1 = 0;
    UCB0I2CIE = UCNACKIE;                    // Enable not-acknowledge interrupt
    UCB0CTL1 &= ~UCSWRST;                    // Clear SW reset, resume operation
    IE2 |= UCB0TXIE + UCB0RXIE;                // Enable TX&RX interrupts
}

uint8_t I2C_Write( uint8_t sladdr , uint8_t *data , uint16_t n )
{
    //
    Ack = 1;                            // Return value
    //
    I2CTxBuffer = data;                    // TX array start address
    I2CNumBytes = n;                      // Update counter
    UCB0I2CSA = sladdr;                  // Slave address (Right justified, bits6-0)
    //
    //uint16_t uiInterruptState = __get_SR_register();
    //_enable_interrupts();
    //
    UCB0CTL1 |= UCTR + UCTXSTT;            // Send I2C start condition, I2C TX mode
    LPM0;                                // Enter LPM0
    //
    while( UCB0CTL1 & UCTXSTP );        // I2C stop condition sent?
    //
    //_bis_SR_register(uiInterruptState);
    return Ack;
}

uint8_t I2C_Read( uint8_t sladdr , uint8_t *data , uint16_t n )
{
    //
    Ack = 1;                        // Return value
    //
    I2CRxBuffer = data;                // Start of RX buffer
    UCB0I2CSA = sladdr;                // Slave address (Right justified, bits6-0)
    //
    UCB0CTL1 &= ~UCTR;                // I2C RX mode
    //
    if( n == 1 )
    {
        I2CNumBytes = 0;                // Update counter
        //
        //__disable_interrupt();
        UCB0CTL1 |= UCTXSTT;            // Send I2C start condition, I2C RX mode
        while( UCB0CTL1 & UCTXSTT );    // I2C start condition sent?
        UCB0CTL1 |= UCTXSTP;            // Send I2C stop condition
        I2CStop = 1;                    // I2C stop condition sent
      //__enable_interrupt();
    }
    else if( n > 1 )
    {
        I2CStop = 0;                    // I2C stop condition not sent yet
        I2CNumBytes = n - 2;            // Update counter
        UCB0CTL1 |= UCTXSTT;            // Send I2C start condition
    }
    LPM0;                                // Enter LPM0
    //
    while( UCB0CTL1 & UCTXSTP );        // I2C stop condition sent?
    //
    return Ack;
}

#ifdef    I2C_PING
uint16_t I2C_Ping( uint8_t sladdr )
{
    //
    UCB0I2CSA = sladdr;                      // Slave address (Right justified, bits6-0)
    //
    __disable_interrupt();
    UCB0CTL1 |= UCTR + UCTXSTT + UCTXSTP;    // I2C start condition, I2C TX mode, I2C stop condition
    while( UCB0CTL1 & UCTXSTP );            // I2C stop condition sent?
    Ack = !(UCB0STAT & UCNACKIFG);            // I2C start condition akd'd or not?
    __enable_interrupt();
    //
    return Ack;
}
#endif    /* !I2C_PING */

#pragma vector = USCIAB0TX_VECTOR
__interrupt void USCIAB0TX_ISR(void)
{
     if( IFG2 & UCB0RXIFG )        // RX mode
     {
        if( I2CNumBytes == 0 )
        {
            // I2CStop is used just to make sure that we leave LPM0 at the right time and not
            // before
            if( I2CStop )
            {
                _low_power_mode_off_on_exit( );        // Exit LPM0
            }
            else
            {
                UCB0CTL1 |= UCTXSTP;                // I2C stop condition
                I2CStop = 1;                        // I2C stop condition sent
            }
        }
        else
        {
            I2CNumBytes--;                            // Decrement counter
        }
        *I2CRxBuffer++ = UCB0RXBUF;                    // Read RX data. This automatically clears UCB0RXIFG
     }
     else                        // TX mode
     {
        if( I2CNumBytes )                            // Check counter
        {
            UCB0TXBUF = *I2CTxBuffer++;             // Load TX buffer. This automatically clears UCB0TXIFG
            I2CNumBytes--;                            // Decrement counter
        }
        else
        {
            UCB0CTL1 |= UCTXSTP;                    // I2C stop condition
            IFG2 &= ~UCB0TXIFG;                     // Clear USCI_B0 TX int flag
            _low_power_mode_off_on_exit( );            // Exit LPM0
        }
     }
}

#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCIAB0RX_ISR(void)
{
    // Not-acknowledge interrupt. This flag is set when an acknowledge is expected
    // but is not received. UCNACKIFG is automatically cleared when a START condition
    // is received.
    if( UCB0STAT & UCNACKIFG )
    {
        UCB0CTL1 |= UCTXSTP;            // I2C stop condition
        Ack = 0;                        // Return value
        UCB0STAT &= ~UCNACKIFG;            // Clear interrupt flag
    }

    // Arbitration-lost. When UCALIFG is set the UCMST bit is cleared and the I2C
    // controller becomes a slave. This can only happen in a multimaster environment

    // Start condition detected interrupt. UCSTTIFG only used in slave mode.

    // Stop condition detected interrupt. UCSTPIFG only used in slave mode.

    _low_power_mode_off_on_exit( );        // Exit LPM0
}

