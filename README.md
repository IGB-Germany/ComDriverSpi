# ComDriverSpi     
Library for a SPI wrapper 
created by IGB
================================================

This library allows the user to:

* Create an object to open a spi communication channel with underlying complexity encapsulated
* Use the object and its methods to transfer data with automatically setting slave select pins
* Configure for different data sizes arrays, 8bit, 16bit, 32bit
* Configure the other SPI options like frequency

An example is included to get you started.

* **/examples** - Example sketches for the library (.ino). Run these from the Arduino IDE
* **/src** - Source files for the library (.cpp, .h)
* **keywords.txt** - Keywords from this library that will be highlighted in the Arduino IDE
* **library.properties** - General library properties for the Arduino package manager

Documentation
--------------
The library enables the following functions:

#### General methods for class
	ComDriverSpi();
    ComDriverSpi(uint8_t slaveSelectPin);
    ComDriverSpi(uint8_t slaveSelectPin, uint32_t frequency);

#### Write and read to SPI bus
    bool writeSpi(uint8_t data[], uint32_t sizeToWrite, transferOption_t transferOption = transferStartEnd);
    bool readSpi(uint8_t data[], uint32_t sizeToRead, transferOption_t transferOption = transferStartEnd);
    bool writeReadSpi(uint8_t dataWrite[], uint32_t sizeToWrite, uint8_t dataRead[], uint32_t sizeToRead, transferOption_t transferOption = transferStartEnd);

    void writeSpiManual(uint8_t dataWrite[], uint32_t sizeToWrite);
    void readSpiManual(uint8_t dataRead[], uint32_t sizeToRead);
    
    void writeSpiManual8(uint8_t data);
    uint8_t readSpiManual8(void);
    void writeSpiManual16(uint16_t data);
    uint16_t readSpiManual16(void);
    void writeSpiManual32(uint32_t data);
    uint32_t readSpiManual32(void);

#### Configuration
    void startWriteSpiManual(void);
    void endWriteSpiManual(void);
    void setSlaveSelectPin(uint8_t slaveSelectPin);
    uint8_t getSlaveSelectPin();
    void setFrequency(uint32_t frequency);
    uint32_t getFrequency();
    void setDataMode(uint8_t dataMode);
    uint8_t getDataMode();
    void setDataOrder(uint8_t dataOrder);
    uint8_t getDataOrder();
    void setTransferOption(transferOption_t transferOption);
    transferOption_t getTransferOption();

## Installation

To install, use the Arduino Library Manager and search for "ComDriverSpi" and install the library.

OR

Download the zip file and copy the contence in to your Arduino's contributed libraries folder found in your sketchbook folder.


License Information
-------------------
This product is _**open source**_! 

Please review the LICENSE.md file for license information. 

If you have any questions or concerns on licensing, please contact igb@posteo.de.

Distributed as-is; no warranty is given.
