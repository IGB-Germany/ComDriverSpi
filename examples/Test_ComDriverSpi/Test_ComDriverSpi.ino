/*Test Functions*/
#include "testComDriverSpi.h"

void setup() {
  //put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("SPI Test"));
  
  //Stop watch
  unsigned long time = 0;
  unsigned long start = micros();
  testSequence(2,2000000);
  time = micros() - start;
  
  Serial.print(F("Time in microsec:\t"));
  Serial.println(time); 
}

void loop() {
  // put your main code here, to run repeatedly:

 //delay(1);
}
