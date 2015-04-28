/*  Example playing a sinewave at a set frequency,
 using Mozzi sonification library.
 
 Demonstrates the use of Oscil to play a wavetable.
 
 Circuit: Audio output on digital pin 9 on a Uno or similar, or
 DAC/A14 on Teensy 3.0/3.1, or 
 check the README or http://sensorium.github.com/Mozzi/
 
 Mozzi help/discussion/announcements:
 https://groups.google.com/forum/#!forum/mozzi-users
 
 Tim Barrass 2012, CC by-nc-sa.
 */
#include <Encoder.h>
#include <LiquidCrystalFast.h>
#include <i2c_t3.h>
#include "Adafruit_TPA2016.h"
#include <ADC.h>  // Teensy 3.0/3.1 uncomment this line and install http://github.com/pedvide/ADC
#include <MozziGuts.h>
#include <Oscil.h> // oscillator template
#include <tables/sin2048_int8.h> // sine table for oscillator

// use: Oscil <table_size, update_rate> oscilName (wavetable), look in .h file of table #included above
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin(SIN2048_DATA);

LiquidCrystalFast lcd(14, 15, 16, 20, 21, 22, 23);
// LCD pins: RS  RW  EN  D4  D5  D6  D7

Encoder knob1(2, 3);
Adafruit_TPA2016 audioamp = Adafruit_TPA2016();


// use #define for CONTROL_RATE, not a constant
#define CONTROL_RATE 64 // powers of 2 please



void LCD_progress_bar (int row, int var, int minVal, int maxVal)
{
  int block = map(var, minVal, maxVal, 0, 16);   // Block represent the current LCD space (modify the map setting to fit your LCD)
  int line = map(var, minVal, maxVal, 0, 80);     // Line represent the theoretical lines that should be printed 
  int bar = (line-(block*5));                             // Bar represent the actual lines that will be printed

  /* LCD Progress Bar Characters, create your custom bars */

  byte bar1[8] = { 
    0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10  };
  byte bar2[8] = { 
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18  };
  byte bar3[8] = { 
    0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C  };
  byte bar4[8] = { 
    0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E  };
  byte bar5[8] = { 
    0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F  };
  lcd.createChar(1, bar1);
  lcd.createChar(2, bar2);
  lcd.createChar(3, bar3);
  lcd.createChar(4, bar4);
  lcd.createChar(5, bar5);

  for (int x = 0; x < block; x++)                        // Print all the filled blocks
  {
    lcd.setCursor (x, row);
    lcd.write (1023);
  }

  lcd.setCursor (block, row);                            // Set the cursor at the current block and print the numbers of line needed
  if (bar != 0) lcd.write (bar);
  if (block == 0 && line == 0) lcd.write (1022);   // Unless there is nothing to print, in this case show blank

  for (int x = 16; x > block; x--)                       // Print all the blank blocks
  {
    lcd.setCursor (x, row);
    lcd.write (1022);
  }
}



void setup(){
  lcd.begin(16, 2);
  lcd.write("Volumez");
  startMozzi(CONTROL_RATE); // set a control rate of 64 (powers of 2 please)
  aSin.setFreq(440); // set the frequency
  audioamp.begin();
  // Turn off AGC for the gain test
  audioamp.setAGCCompression(TPA2016_AGC_OFF);
  // we also have to turn off the release to really turn off AGC
  audioamp.setReleaseControl(0);
  Serial.begin(9600);
}

long position1  = -999;

void updateControl(){
  long new1;
//   set the cursor to column 0, line 1
//  (note: line 1 is the second row, since counting begins with 0):
 new1 = knob1.read();
  if (new1 != position1) {
//    LCD_progress_bar(1, new1, 100, -100);
    position1 = new1;
  }
  double volume = map(new1, 100, -100, -28, 30);
  
  if (millis() % 1024 == 0) {
    Serial.println("i ran");
  }
//      audioamp.setGain(volume);
//  lcd.setCursor(8, 0);
//  lcd.write((int)volume);
//  Serial.print("volume: ");
//  Serial.print(volume);
//  Serial.print("\n");
//  
}


int updateAudio(){
  return amplitude * aSin.next(); // return an int signal centred around 0
}


void loop(){
  audioHook(); // required here


}




