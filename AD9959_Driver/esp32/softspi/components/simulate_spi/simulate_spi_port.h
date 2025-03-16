#include"simulate_spi.h"
#ifdef SIMULATE_SPI_H
#ifndef SIMULATE_SPI_PORT_H
#define SIMULATE_SPI_PORT_H
//inculde
#include<stdint.h>
#include"driver/gpio.h"

//port init
void port_init();
//cs write
void cs_write(uint8_t bit);
//mosi write
void mosi_write(uint8_t bit);
//miso read
uint8_t miso_read();
//sck write
void sck_write(uint8_t bit);

#endif//#ifndef SIMULATE_SPI_PORT_H
#endif//#ifdef SIMULATE_SPI_H
