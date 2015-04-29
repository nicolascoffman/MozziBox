/*************************************************** 
  This is an implementation of the game Lights Out for 4 Trellises
  Press a key to turn on/off the adjacent buttons, try to turn all
  the LEDs off!

  Designed specifically to work with the Adafruit Trellis 
  ----> https://www.adafruit.com/products/1616
  ----> https://www.adafruit.com/products/1611

  These displays use I2C to communicate, 2 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Tony Sherwood for Adafruit Industries.  
  MIT license, all text above must be included in any redistribution
 ****************************************************/

#include <i2c_t3.h>
#include "Adafruit_Trellis.h"

Adafruit_Trellis matrix = Adafruit_Trellis();
Adafruit_TrellisSet trellis = Adafruit_TrellisSet(&matrix);

#define NUMTRELLIS 1

#define numKeys (NUMTRELLIS * 16)

/*
  In order for this layout to work, you will have to have soldered your 4 boards
  together in the same order that I did.  Below is the top view of the circuit, with
  each board's address, and lines indicating which boards are connected to each other.
  If you soldered your boards together differently, you will need to edit the chessboard
  array below until the LED wipe when you start up your sketch turns on all of the LEDs
  in order.

             [0x73]--[0x72]
                       |
  [ARDUINO]--[0x70]--[0x71]
 
*/

// Connect Trellis Vin to 5V and Ground to ground.
// Connect the INT wire to pin #5 (can change later
#define INTPIN 31
// Connect I2C SDA pin to your Arduino SDA line
// Connect I2C SCL pin to your Arduino SCL line
// All Trellises share the SDA, SCL and INT pin! 
// Even 8 tiles use only 3 wires max


void setup() {
  Serial.begin(9600);

  // INT pin requires a pullup
  pinMode(INTPIN, INPUT);
  digitalWrite(INTPIN, HIGH);
  
  trellis.begin(0x70);
  
  for (uint8_t i=0; i<4; i++) {
    for (uint8_t j=0; j<4; j++) {
      trellis.writeDisplay();
      delay(50);
    }
  }  

  
  for (uint8_t i=0; i<numKeys; i++) {
    trellis.clrLED(i);
  }
  trellis.writeDisplay();
  
}

void toggle(int placeVal) {
 if (trellis.isLED(placeVal))
    trellis.clrLED(placeVal);
  else
    trellis.setLED(placeVal);
}


void loop() {
  delay(30); // 30ms delay is required, dont remove me!
  
    // If a button was just pressed or released...
    if (trellis.readSwitches()) {
      // go through every button
      for (uint8_t i=0; i<numKeys; i++) {
	// if it was pressed, make your move
        if (trellis.justPressed(i)) {
          Serial.print("key");
          Serial.print(i);
          Serial.println(" is pressed.");
        }
      }
      // tell the trellis to set the LEDs we requested
      trellis.writeDisplay();
    }
}

