#include "spi.h"
#include <avr/io.h>



///////////////////////////////////////////////////////////////////////////////////////////////////
#define SPI_SPCR		SPCR0	// SPI Control Register.

#define SPI_SPIE		SPIE0	// SPI Interrupt Enable.
// This bit causes the SPI interrupt to be executed if SPIF bit in
// the SPSR Register is set and the if the Global Interrupt Enable
// bit in SREG is set.

#define SPI_SPE			SPE0		// SPI Enable.
// When the SPE bit is written to one, the SPI is enabled. This bit
// must be set to enable any SPI operations.

#define SPI_DORD		DORD0	// Data Order.
// When the DORD bit is written to one, the LSB of the data word is
// transmitted first. When the DORD bit is written to zero, the MSB
// of the data word is transmitted first.

#define SPI_MSTR		MSTR0	// Master/Slave Select.
// This bit selects Master SPI mode when written to one, and Slave
// SPI mode when written logic zero. If SSis configured as an input
// and is driven low while MSTR is set, MSTR will be cleared, and
// SPIF in SPSR will become set. The user will then have to set
// MSTR to re-enable SPI Master mode.

#define SPI_CPOL		CPOL0	// Clock Polarity.
// When this bit is written to one, SCK is high when idle. When
// CPOL is written to zero, SCK is low when idle.

#define SPI_CPHA		CPHA0	// Clock Phase.
// The settings of the Clock Phase bit (CPHA) determine if data is
// sampled on the leading (first) or trailing (last) edge of SCK.

#define SPI_SPR0		SPR00	// SPI Clock Rate Select.
#define SPI_SPR1		SPR10	// These two bits control the SCK rate of the device configured
// as a Master. SPR1 and SPR0 have no effect on the Slave.
/* Relationship Between SCK andthe Oscillator Frequency
SPI2X	SPR1	SPR0	SCK Frequency
0		0		0		fosc/4
0		0		1		fosc/16
0		1		0		fosc/64
0		1		1		fosc/128
1		0		0		fosc/2
1		0		1		fosc/8
1		1		0		fosc/32
1		1		1		fosc/64
*/

/////////////////////////////////////////////////
#define SPI_SPSR		SPSR0	// SPI Status Register.

#define SPI_SPIF		SPIF0	// SPI Interrupt Flag.
// When a serial transfer is complete, the SPIF Flag is set. An
// interrupt is generated if SPIE in SPCR is set and global
// interrupts are enabled. If SSis an input and is driven low when
// the SPI is in Master mode, this will also set the SPIF Flag.
// SPIF is cleared by hardware when executing the corresponding
// interrupt handling vector. Alternatively, the SPIF bit is
// cleared by first reading the SPI Status Register with SPIF set,
// then accessing the SPI Data Register (SPDR).

#define SPI_WCOL		WCOL0	// Write COLlision Flag.
// The WCOL bit is set if the SPI Data Register (SPDR) is written
// during a data transfer. The WCOL bit (and the SPIF bit) are
// cleared by first reading the SPI Status Register with WCOL set,
// and then accessing the SPI Data Register.

#define SPI_SPI2X		SPI2X0	// Double SPI Speed Bit.
// When this bit is written logic one the SPI speed (SCK Frequency)
// will be doubled when the SPI is inMaster mode. This means that
// the minimum SCK period will be two CPU clock periods. When the
// SPI is configured as Slave, the SPI is only guaranteed to work
// at fosc/4 or lower.

/////////////////////////////////////////////////
#define SPI_SPDR		SPDR0	// SPI Data Register

///////////////////////////////////////////////////////////////////////////////////////////////////

// Loop until any current SPI transmissions have completed
#define spi_wait()	while (!(SPI_SPSR & (1 << SPI_SPIF)));

void spi_init(void)
{
	// make the MOSI, SCK, and SS pins outputs
	SPI_DDRX |= ( 1 << SPI_MOSI ) | ( 1 << SPI_SCK ) | ( 1<< SPI_SS );
	// make sure the MISO pin is input
	SPI_DDRX &= ~( 1 << SPI_MISO );
	// set up the SPI module: SPI enabled, MSB first, master mode,
	//  clock polarity and phase = 0, F_osc/8
	SPI_SPCR = ( 1 << SPI_SPE ) | ( 1 << SPI_MSTR ) | ( 0 << SPI_SPR1 )| ( 0 << SPI_SPR0 );
	SPI_SPSR = 0;     // set double SPI speed for F_osc/8
	SPI_PORTX |= ( 1 << SPI_SS );
}

/*�������� ���� ������ �� SPI*/
void spi_write(uint8_t data)
{
	SPI_SPDR = data;
	while(!(SPI_SPSR & (1<<SPI_SPIF)));
}

void spi_select()
{
	//���������� SS � 0
	SPI_PORTX &= ~(1 << SPI_SS );        
}

void spi_unselect()
{
	//���������� SS � 1
	SPI_PORTX |= ( 1 << SPI_SS );        
}

/*�������� � �������� ���� ������ �� SPI*/
uint8_t spi_read(uint8_t data)
{
	unsigned char ret;
	//������������ ������
	SPI_SPDR = data;
	//���� ��������� ��������
	while( !( SPI_SPSR & ( 1 << SPI_SPIF ) ) ); 
	//��������� �������� ������
	ret = SPI_SPDR;                         
	return ret;
}

/*��������� ��������� ���� ������ �� SPI*/
void spi_write_array(uint8_t num, uint8_t *data)
{
	while(num--){
		SPI_SPDR = *data++;
		while(!(SPI_SPSR & (1<<SPI_SPIF)));
	}
}

/*��������� � �������� ��������� ���� ������ �� SPI*/
void spi_read_array(uint8_t num, uint8_t *data)
{
	while(num--){
		SPI_SPDR = *data;
		while(!(SPI_SPSR & (1<<SPI_SPIF)));
		*data++ = SPI_SPDR;
	}
}

