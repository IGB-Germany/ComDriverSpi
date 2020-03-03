#ifndef TEST_COM_DRIVER_SPI_H
#define TEST_COM_DRIVER_SPI_H
/*uint8_t*/
#include "stdint.h"

void testSequence(uint8_t slaveSelectPin, uint32_t frequency);

void test_frequency(uint8_t slaveSelectPin, uint32_t frequency);

void test_writeBytes(uint8_t slaveSelectPin, uint32_t frequency);

void test_clockBytes(uint8_t slaveSelectPin, uint32_t frequency);


#endif /*TEST_COM_DRIVER_SPI_H*/
