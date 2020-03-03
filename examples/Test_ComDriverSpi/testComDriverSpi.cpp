/*Test Functions*/
#include "testComDriverSpi.h"

/*Functions*/
#include "ComDriverSpi.h"

void testSequence(uint8_t slaveSelectPin, uint32_t frequency)
{
  test_frequency(slaveSelectPin, frequency);
  test_writeBytes(slaveSelectPin, frequency);
  test_clockBytes(slaveSelectPin, frequency);
}

void test_frequency(uint8_t slaveSelectPin, uint32_t frequency)
{
  //Create object
  ComDriverSpi channel1(slaveSelectPin, frequency);
  for(uint32_t freq = 100000; freq<=8000000; freq= freq+100000)
  {
    channel1.setFrequency(freq);
    Serial.println(channel1.getFrequency());  
  }  
}

void test_writeBytes(uint8_t slaveSelectPin, uint32_t frequency)
{
  /*Create object*/
  ComDriverSpi channel1(slaveSelectPin, frequency);

  uint32_t sizeToWrite = 16;
  uint8_t dataWrite[sizeToWrite] = {1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0};
  uint32_t sizeToRead = 16;

  uint8_t dataRead[sizeToRead];
  for (uint8_t i = 0; i < sizeToRead; i++)
  {
    dataRead[i] = 0xff;
  }

  channel1.writeReadSpi(dataWrite, sizeToWrite, dataRead, sizeToRead);
  channel1.writeSpi(dataWrite, sizeToWrite);
  channel1.readSpi(dataRead, sizeToRead);
}

void test_clockBytes(uint8_t slaveSelectPin, uint32_t frequency)
{
  /*Create object*/
  ComDriverSpi channel1(slaveSelectPin, frequency);

  uint32_t sizeToWrite = 16;
  uint8_t dataWrite[sizeToWrite] = {1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0};
  uint32_t sizeToRead = 16;

  uint8_t dataRead[sizeToRead];
  for (uint8_t i = 0; i < sizeToRead; i++)
  {
    dataRead[i] = 0xff;
  }
  channel1.readSpi(dataRead, sizeToRead, ComDriverSpi::transferEnd);
  channel1.writeSpi(dataWrite, sizeToWrite, ComDriverSpi::transferEnd);
  channel1.readSpi(dataRead, sizeToRead);
  channel1.writeSpi(dataWrite, sizeToWrite);
}
