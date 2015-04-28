# MozziBox

bug - Changing Trellis library to pull from i2c_t3 (I2C for Teensy 3.0/3.1) using Wire1 enables trellis to work
HOWEVER, it also changes Wire0 for the amp at the same time :/


// initialize the library with the numbers of the interface pins
LiquidCrystalFast lcd(14, 15, 16, 20, 21, 22, 23);
         // LCD pins: RS  RW  EN  D4  D5  D6  D7


// Change these pin numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder knob1(2, 3);
Encoder knob2(5, 6);
Encoder knob3(8, 9);
Encoder knob4(11, 12);
