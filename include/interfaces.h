#include <pin_definitions.h>

#include "driver/gpio.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"

#include <driver/i2c.h>
#include <driver/spi_master.h>
#include <driver/uart.h>
#include <esp_vfs_dev.h>



void init_gpios()
{
    gpio_config_t output_config;
    gpio_config_t input_config;  

    // configure input pin
    input_config.pin_bit_mask   = GPIO_INPUTS;
    input_config.mode           = GPIO_MODE_INPUT;
    input_config.intr_type      = GPIO_INTR_DISABLE;
    gpio_config(&input_config);    // set configuration for input pins

    // configure output pin
    output_config.pin_bit_mask  = GPIO_OUTPUTS;
    output_config.mode          = GPIO_MODE_OUTPUT;
    output_config.intr_type     = GPIO_INTR_DISABLE;
    gpio_config(&output_config);    // set configuration for output pins
}
/* END GPIOS */


/* UART */
#define UART_RX_BUFFER_SIZE (1024 * 2)
#define UART_TX_BUFFER_SIZE (1024 * 2)

const uart_port_t uart_port = UART_NUM_1;   // default port
QueueHandle_t uart_event_queue;             // creates event que

/**
 * @brief Initializes UART 0 peripheral.
 */
void init_uart()
{
    uart_config_t conf = {
        .baud_rate = 115200,
        .data_bits = 8,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .rx_flow_ctrl_thresh = 122,
        .source_clk = UART_SCLK_APB,
    };

    uart_param_config(uart_port, &conf);                        // setup uart communication parameters
    uart_set_pin(uart_port, UART_TX_PIN, UART_RX_PIN, -1, -1);  // configuring the rx and tx pins used, rts and cts disabled with -1
    uart_driver_install(uart_port, UART_RX_BUFFER_SIZE, UART_TX_BUFFER_SIZE, 10, &uart_event_queue, 0);

    //esp_vfs_dev_uart_use_driver(uart_port); // set uart port to be used by printf function
}

/**
 * @brief Write bytes via UART_PORT_0
 * 
 * @param buffer        Pointer to the data to be send
 * @param buffer_len    Length of the data to be send
*/
void serial_write(char *buffer, uint8_t buffer_len)
{
    uart_write_bytes(uart_port, buffer, buffer_len);
}

/**
 * @brief Read bytes from UART_PORT_0
 * 
 * @param buffer    Pointer to data buffer read data shall be stored in
 * @param length    The number of bytes to read
 * @param flush     00 -> dont flush rx_buffer, 01 -> flush rx_buffer after bytes have been read
 */
void serial_read(uint8_t *buffer, uint16_t length, uint8_t flush)
{
    size_t rx_len;
    uart_get_buffered_data_len(uart_port, &rx_len);                                     // check if any data present in rx_buffer
    // printf("data len in rx buffer: %d\n", rx_len);
    if (rx_len > 0)
    {
        uart_read_bytes(uart_port,(void *) buffer, length, 100/portTICK_PERIOD_MS);     // read data into given buffer
        if (flush)
        {
            uart_flush(uart_port);                                                      // flush rx_buffer
        }
    }
}
/* END UART */

/* I2C */
#define I2C_FREQUENCY_HZ            100000      // 100khz freq.

void init_i2c() {
    i2c_config_t i2c_conf = {
        .mode               = I2C_MODE_MASTER,
        .sda_io_num         = I2C_SDA_PIN,
        .scl_io_num         = I2C_SCL_PIN,
        .sda_pullup_en      = GPIO_PULLUP_ENABLE,
        .scl_pullup_en      = GPIO_PULLUP_ENABLE,
        // .master.clk_speed   = I2C_FREQUENCY_HZ,
    };

    i2c_conf.master.clk_speed = I2C_FREQUENCY_HZ;   // extracted from former initialization due to: "chained designators are non standard in c" error

    ESP_ERROR_CHECK(i2c_param_config(I2C_NUM_0, &i2c_conf));
    ESP_ERROR_CHECK(i2c_driver_install(I2C_NUM_0, i2c_conf.mode, 0, 0, 0));
}
/* END I2C */
