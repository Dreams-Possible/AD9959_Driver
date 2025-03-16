//enable ad9959 driver
#if 1
#ifndef AD9959_DRIVER_H
#define AD9959_DRIVER_H

//include
#include<stdio.h>
#include<stdint.h>
#include"driver/gpio.h"
#include"simulate_spi.h"
#include"freertos/FreeRTOS.h"

//ad9959 init
void ad9959_init();
//ad9959 set frequency
void ad9959_fre(uint8_t ch,uint32_t fre);
//ad9959 set phase
void ad9959_pha(uint8_t ch, uint16_t pha);
//ad9959 set amplitude
void ad9959_amp(uint8_t ch, uint16_t amp);

#endif//#ifndef AD9959_DRIVER_H
#endif//#if 1
