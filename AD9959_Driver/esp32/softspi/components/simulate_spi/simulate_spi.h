#pragma once

//enable simulate_spi
#if 1
#ifndef SIMULATE_SPI_H
#define SIMULATE_SPI_H
//inculde
#include<stdint.h>
#include"simulate_spi_port.h"

//simulate spi init
void simulate_spi_init();
//simulate spi swap
void simulate_spi_swap(uint8_t*send,uint8_t*receive,uint32_t length);
//simulate spi send data with addr
void simulate_send_addr_data(uint8_t addr,uint8_t*data,uint16_t len);

#endif//#ifndef SIMULATE_SPI_H
#endif//#if 1
