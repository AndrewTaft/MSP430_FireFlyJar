/*
 * I2CMaster.c
 */

#define I2CMaster

#ifdef I2CMaster

#include "I2CMaster.h"

volatile uint16_t     I2CNumBytes;
volatile uint16_t    Ack;
volatile uint8_t    *I2CRxBuffer, *I2CTxBuffer;

volatile uint16_t    I2CStop;

void I2CInit( void )
{
    P1SEL |= BIT6 + BIT7;                    // Assign I2C pins to USCI_B0
    P1SEL2|= BIT6 + BIT7;

    //P1OUT |= BIT6 + BIT7;                    // We can enable internal pull-ups
    //P1REN |= BIT6 + BIT7;

    UCB0CTL1 |= UCSWRST;                    // Enable SW reset
    UCB0CTL0 = UCMST + UCMODE_3 + UCSYNC;    // 7-bit addressing, single-master environment, I2C Master, synchronous mode
    UCB0CTL1 = UCSSEL_2 + UCSWRST;            // Use SMCLK, keep SW reset
    UCB0BR0 = 10;                    // fSCL = SMCLK/UCB0BR1
    UCB0BR1 = 0;
    UCB0I2CIE = UCNACKIE;                    // Enable not-acknowledge interrupt
    UCB0CTL1 &= ~UCSWRST;                    // Clear SW reset, resume operation
    IE2 |= UCB0TXIE + UCB0RXIE;                // Enable TX&RX interrupts
}

uint16_t I2CWrite( uint8_t sladdr , uint8_t *data , uint16_t n )
{
    //
    Ack = 1;                            // Return value
    //
    I2CTxBuffer = data;                    // TX array start address
    I2CNumBytes = n;                      // Update counter
    UCB0I2CSA = sladdr;                  // Slave address (Right justified, bits6-0)
    //
    UCB0CTL1 |= UCTR + UCTXSTT;            // Send I2C start condition, I2C TX mode
    LPM0;                                // Enter LPM0
    //
    while( UCB0CTL1 & UCTXSTP );        // I2C stop condition sent?
    //
    return Ack;
}

uint16_t I2CRead( uint8_t sladdr , uint8_t *data , uint16_t n )
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
        __disable_interrupt();
        UCB0CTL1 |= UCTXSTT;            // Send I2C start condition, I2C RX mode
        while( UCB0CTL1 & UCTXSTT );    // I2C start condition sent?
        UCB0CTL1 |= UCTXSTP;            // Send I2C stop condition
        I2CStop = 1;                    // I2C stop condition sent
      __enable_interrupt();
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
uint16_t I2CPing( uint8_t sladdr )
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

#endif
