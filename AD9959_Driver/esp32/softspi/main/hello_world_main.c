#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"

#include"simulate_spi.h"
#include"ad9959_driver.h"

void app_main(void)
{
    //simulate spi init
    simulate_spi_init();

    //ad9959 init all
    ad9959_init();

    //simple test
    while(1)
    {
        //set frequency
        ad9959_fre(0,100000);
        ad9959_fre(1,100000);
        ad9959_fre(2,100000);
        ad9959_fre(3,100000);
        //set phase
        ad9959_pha(0,0);
        ad9959_pha(1,4096);
        ad9959_pha(2,8192);
        ad9959_pha(3,12288);
        //set amplitude
        ad9959_amp(0,1023);
        ad9959_amp(1,1023);
        ad9959_amp(2,1023);
        ad9959_amp(3,1023);
        vTaskDelay(pdMS_TO_TICKS(1000));
        printf("ok\n");
    }
}
