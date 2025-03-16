#include"ad9959_driver.h"
//enable ad9959 driver
#ifdef AD9959_DRIVER_H

//config
#define RST_IO 47
#define PW_IO 14
#define UPDATE_IO 9
#define D1_IO 38
#define D2_IO 39
#define D3_IO 40
#define P0_IO 4
#define P1_IO 5
#define P2_IO 6
#define P3_IO 7

//define
#define CH0 0x10//channel 0
#define CH1 0x20//channel 1
#define CH2 0x40//channel 2
#define CH3 0x80//channel 3
#define FRE_ACT 8.589934592//frequency factor
#define CSR_ADDR 0x00//channel choose register
#define FR1_ADDR 0x01//funtion register 1
#define FR2_ADDR 0x02//funtion register 2
#define CFTW0_ADDR 0x04//channel frequency register
#define CPOW0_ADDR 0x05//channel phase register
#define ACR_ADDR 0x06//channel amplitude register
static uint8_t FR1_DATA[3]={0xD0,0x00,0x00};//funtion register 1 init data
static uint8_t FR2_DATA[2]={0x00,0x00};//funtion register 1 init data

//delay ms
static void delay(uint32_t ms);
//io set
static void io(uint16_t pin,uint8_t level);
//init gpio
static void init_gpio();
//init spi
static void init_spi();
//send cmd
static void send(uint8_t addr,uint8_t*data,uint16_t len);
//reset
static void reset();
//set up date
static void update();
//init software
static void init_soft();
//ad9959 init
void ad9959_init();
//ad9959 set frequency
void ad9959_fre(uint8_t ch,uint32_t fre);
//ad9959 set phase
void ad9959_pha(uint8_t ch, uint16_t pha);
//ad9959 set amplitude
void ad9959_amp(uint8_t ch, uint16_t amp);

//delay ms
static void delay(uint32_t ms)
{

    return;
}

//io set
static void io(uint16_t pin,uint8_t level)
{

    return;
}

//init gpio
static void init_gpio()
{

    return;
}

//init spi
static void init_spi()
{

    return;
}

//send cmd
static void send(uint8_t addr,uint8_t*data,uint16_t len)
{

    return;
}

//reset
static void reset()
{
	io(RST_IO,0);
	delay(1);
	io(RST_IO,1);
	delay(1);
	io(RST_IO,0);
    delay(10);
    return;
}

//set up date
static void update()
{
	io(UPDATE_IO,0);
	delay(1);
	io(UPDATE_IO,1);
	delay(1);
	io(UPDATE_IO,0);
    return;
}

//init software
static void init_soft()
{
    reset();
    send(FR1_ADDR,FR1_DATA,3);
    send(FR2_ADDR,FR2_DATA,2);
}

//ad9959 init
void ad9959_init()
{
    init_gpio();
    init_spi();
    init_soft();
    return;
}

//ad9959 set frequency
void ad9959_fre(uint8_t ch,uint32_t fre)
{
    //choose channel
    uint8_t ch_tmp=0;
    switch(ch)
    {
        case 0:
            ch_tmp=CH0;
        break;
        case 1:
            ch_tmp=CH1;
        break;
        case 2:
            ch_tmp=CH2;
        break;
        case 3:
            ch_tmp=CH3;
        break;
        default:
            ch_tmp=CH0;
        break;
    }
	send(CSR_ADDR,&ch_tmp,1);
    //set frequency
    uint8_t fre_data[4]={0};
    uint32_t fre_data_tmp=(uint32_t)(fre*FRE_ACT);
    fre_data[0]=(uint8_t)(fre_data_tmp>>24);
    fre_data[1]=(uint8_t)(fre_data_tmp>>16);
    fre_data[2]=(uint8_t)(fre_data_tmp>>8);
    fre_data[3]=(uint8_t)fre_data_tmp;
    send(CFTW0_ADDR,fre_data,4);
    update();
}

//ad9959 set phase
void ad9959_pha(uint8_t ch, uint16_t pha)
{ 
    //choose channel
    uint8_t ch_tmp=0;
    switch(ch)
    {
        case 0:
            ch_tmp=CH0;
        break;
        case 1:
            ch_tmp=CH1;
        break;
        case 2:
            ch_tmp=CH2;
        break;
        case 3:
            ch_tmp=CH3;
        break;
        default:
            ch_tmp=CH0;
        break;
    }
	send(CSR_ADDR,&ch_tmp,1);
    //set phase
    uint8_t pha_data[2]={0};
    uint32_t pha_data_tmp=(uint32_t)pha;
    pha_data[0]=(uint8_t)(pha_data_tmp>>8);
    pha_data[1]=(uint8_t)pha_data_tmp;
    send(CPOW0_ADDR,pha_data,2);
    update();
}

//ad9959 set amplitude
void ad9959_amp(uint8_t ch, uint16_t amp)
{ 
    //choose channel
    uint8_t ch_tmp=0;
    switch(ch)
    {
        case 0:
            ch_tmp=CH0;
        break;
        case 1:
            ch_tmp=CH1;
        break;
        case 2:
            ch_tmp=CH2;
        break;
        case 3:
            ch_tmp=CH3;
        break;
        default:
            ch_tmp=CH0;
        break;
    }
	send(CSR_ADDR,&ch_tmp,1);
    //set amplitude
    uint8_t amp_data[3]={0};
    uint32_t amp_data_tmp=(uint32_t)amp;
    amp_data[0]=(uint8_t)(amp_data_tmp>>16);
    amp_data[1]=(uint8_t)(amp_data_tmp>>8);
    amp_data[2]=(uint8_t)amp_data_tmp;
    send(ACR_ADDR,amp_data,3);
    update();
}

#endif//#ifdef AD9959_DRIVER_H
