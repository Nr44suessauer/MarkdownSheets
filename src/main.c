#include <pin_definitions.h>
#include <interfaces.h>

void app_main() 
{
    init_gpios(); // pin definition in peripherals.h
    init_uart();    

    uint8_t flag = false;

    while (1)
    {
        if (flag)
        {
            flag = false;
            gpio_set_level(STATUS_LED,true);
        }
        else
        {
            flag = true;
            gpio_set_level(STATUS_LED, false);
        }

        char benis = 5;

        printf("Benis gesendet mit printf und der uint %d\n", benis);

        char benis_mes[] = "Benis gesendet mit serial_write und der uint ";

            serial_write(benis_mes, sizeof(benis_mes));
            serial_write(&benis, sizeof(benis));
            char end[] = "\nEnde\n";
            serial_write(end, sizeof(end));

        vTaskDelay(500 / portTICK_PERIOD_MS);
    } 
}