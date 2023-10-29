#ifndef PIN_DEFINITIONS_H
#define PIN_DEFINITIONS_H

// // GPIO
#define IO_BTN                      GPIO_NUM_0
#define STATUS_LED                  GPIO_NUM_1

#define GPIO_INPUTS                 (1ULL << IO_BTN)
#define GPIO_OUTPUTS                (1ULL << STATUS_LED)

// I2C
#define I2C_SCL_PIN                 GPIO_NUM_12
#define I2C_SDA_PIN                 GPIO_NUM_11


// SPI
#define SPI_MOSI_PIN                GPIO_NUM_13
#define SPI_MISO_PIN                GPIO_NUM_12
#define SPI_CLK_PIN                 GPIO_NUM_14
#define SPI_DEFAULT                 -1

// UART
#define UART_TX_PIN                 GPIO_NUM_2
#define UART_RX_PIN                 GPIO_NUM_4

#endif /* PIN_DEFINITIONS_H */