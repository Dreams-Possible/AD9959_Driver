#include"simulate_spi.h"
#ifdef SIMULATE_SPI_H

//config
#define CSMD 0//device select level:0select,1select
#define CPOL 0//clock idle level:0negative,1negative
#define CPHA 0//data capture level:0up,1down

//soft init
static void init();
//start connection
static void start();
//end connection
static void end();
//swap 1 bit
static uint8_t swap_bit(uint8_t bit);
//swap data
static void swap_data(uint8_t*send,uint8_t*receive,uint32_t length);
//simulate spi init
void simulate_spi_init();
//simulate spi swap
void simulate_spi_swap(uint8_t*send,uint8_t*receive,uint32_t length);
//simulate spi send data with addr
void simulate_send_addr_data(uint8_t addr,uint8_t*data,uint16_t len);

//soft init
static void init()
{
	cs_write(1-CSMD);
	sck_write(CPOL);
	return;
}

//start connection
static void start()
{
	cs_write(CSMD);
	return;
}

//end connection
static void end()
{
	cs_write(1-CSMD);
	return;
}

//swap 1 bit
static uint8_t swap_bit(uint8_t bit)
{
    for(uint8_t f=0;f<8;++f)
    {
		sck_write(CPOL);
    	mosi_write(bit&0x80);
    	sck_write(1-CPOL);
		bit<<=1;
		if(miso_read())
		{
			bit|=0x01;
		}
		sck_write(CPOL);
    }
    return bit;
}

//swap data
static void swap_data(uint8_t*send,uint8_t*receive,uint32_t length)
{
	start();
	for(uint8_t f=0;f<length;++f)
	{
		*receive=swap_bit(*send);
		++send;
		++receive;
	}
    end();
	return;
}

//simulate spi init
void simulate_spi_init()
{
	port_init();
	init();
	return;
}

//simulate spi swap
void simulate_spi_swap(uint8_t*send,uint8_t*receive,uint32_t length)
{
	swap_data(send,receive,length);
	return;
}


//simulate spi send data with addr
void simulate_send_addr_data(uint8_t addr,uint8_t*data,uint16_t len)
{
	start();
	swap_bit(addr);
	for(uint8_t f=0;f<len;++f)
	{
		swap_bit(*data);
		++data;
	}
    end();
	return;
}

#endif//#ifdef SIMULATE_SPI_H

