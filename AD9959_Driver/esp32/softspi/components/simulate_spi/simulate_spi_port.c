#include"simulate_spi.h"
#ifdef SIMULATE_SPI_H

//config
#define CS 10//cs pin
#define MOSI 11//mosi pin
#define MISO 13//miso pin
#define SCK 12//sck pin

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

//port init
void port_init()
{
    gpio_config_t config={0};
    //cs
    config.intr_type=GPIO_INTR_DISABLE;
    config.mode=GPIO_MODE_OUTPUT;
    config.pin_bit_mask=(1ULL<<CS);
    config.pull_down_en=0;
    config.pull_up_en=0;
    gpio_config(&config);
    //mosi
    config.intr_type=GPIO_INTR_DISABLE;
    config.mode=GPIO_MODE_OUTPUT;
    config.pin_bit_mask=(1ULL<<MOSI);
    config.pull_down_en=0;
    config.pull_up_en=0;
    gpio_config(&config);
    //miso
    config.intr_type=GPIO_INTR_DISABLE;
    config.mode=GPIO_MODE_INPUT;
    config.pin_bit_mask=(1ULL<<MISO);
    config.pull_down_en=0;
    config.pull_up_en=0;
    gpio_config(&config);
    //sck
    config.intr_type=GPIO_INTR_DISABLE;
    config.mode=GPIO_MODE_OUTPUT;
    config.pin_bit_mask=(1ULL<<SCK);
    config.pull_down_en=0;
    config.pull_up_en=0;
    gpio_config(&config);
    return;
}

//cs write
void cs_write(uint8_t bit)
{
    gpio_set_level(CS,bit);
    return;
}

//mosi write
void mosi_write(uint8_t bit)
{
    gpio_set_level(MOSI,bit);
    return;
}

//miso read
uint8_t  miso_read()
{
    return gpio_get_level(MISO);
}

//sck write
void sck_write(uint8_t bit)
{
    gpio_set_level(SCK,bit);
    return;
}

#endif//#ifdef SIMULATE_SPI_H
