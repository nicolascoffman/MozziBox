/*************************************************** 
  This is an example for our Adafruit TPA2016 Class D Amplifier Breakout

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/1712

  This amplifier uses I2C to communicate, 2 pins are required to  
  interface

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/


#include <i2c_t3.h>
#include "Adafruit_TPA2016.h"

Adafruit_TPA2016 audioamp = Adafruit_TPA2016();

void setup() {
 Serial.begin(9600);
 

 audioamp.begin();
 

  // Turn off AGC 
  audioamp.setAGCCompression(TPA2016_AGC_OFF);
  // we also have to turn off the release to really turn off AGC
  audioamp.setReleaseControl(0);
  

    audioamp.setGain(30);
}


void loop() {

}
