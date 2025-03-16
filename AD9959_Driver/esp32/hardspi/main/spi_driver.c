#include"spi_driver.h"
//enable spi driver
#ifdef SPI_DRIVER_H

//config
#define COM SPI2_HOST
#define SCLK 12
#define MOSI 11
#define MISO 13

//spi init
void spi_init();

//spi init
void spi_init()
{
    spi_bus_config_t config={0};
    config.mosi_io_num=MOSI;
    config.miso_io_num=MISO;
    config.sclk_io_num=SCLK;
    config.quadwp_io_num=-1;
    config.quadhd_io_num=-1;
    spi_bus_initialize(COM,&config,SPI_DMA_CH_AUTO);
}

#endif//#ifdef SPI_DRIVER_H
