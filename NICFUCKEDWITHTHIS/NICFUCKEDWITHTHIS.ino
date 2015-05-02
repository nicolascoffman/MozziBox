/*
           Example using a piezo to trigger an audio sample to play,
 and a knob to set the playback pitch,
 with Mozzi sonification library.
 
 Demonstrates one-shot samples and analog input for control.
 
 This example goes with a tutorial on the Mozzi site:
 http://sensorium.github.io/Mozzi/learn/introductory-tutorial/
 
 The circuit:
 Audio output on digital pin 9 on a Uno or similar, or
 DAC/A14 on Teensy 3.0/3.1, or 
 check the README or http://sensorium.github.com/Mozzi/
 
 Potentiometer connected to analog pin 0.
 Center pin of the potentiometer goes to the analog pin.
 Side pins of the potentiometer go to +5V and ground
 
 Piezo on analog pin 3:
 + connection of the piezo attached to the analog pin
 - connection of the piezo attached to ground
 1-megohm resistor between the analog pin and ground
 
 Mozzi help/discussion/announcements:
 https://groups.google.com/forum/#!forum/mozzi-users
 
 Tim Barrass 2013.
 CC by-nc-sa
 */

#include <ADC.h>  // Teensy 3.0/3.1 uncomment this line and install http://github.com/pedvide/ADC
#include <MozziGuts.h>
#include <Sample.h> // Sample template
#include <samples/burroughs1_18649_int8.h> // a converted audio sample included in the Mozzi download
#include <EventDelay.h>
#include "Adafruit_TPA2016.h"
#include <LiquidCrystalFast.h>
#include <Encoder.h>

// Initialize LCDFast with the numbers of the interface pins~~~~~~~~~
LiquidCrystalFast lcd(14, 15, 16, 20, 21, 22, 23);
// LCD pins: RS  RW  EN  D4  D5  D6  D7


//Encoder setup~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Encoder knob1(2, 3);
Encoder knob2(5, 6);
Encoder knob3(8, 9);
Encoder knob4(11, 12);

long position1  = -999;
long position2  = -999;
long position3  = -999;
long position4  = -999;

//declare amp ~~~~~~~~~~~~~~~~~~~~
Adafruit_TPA2016 audioamp = Adafruit_TPA2016();


// Bamboo Samples ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <samples/bamboo/bamboo_02_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_03_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_04_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_05_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_06_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_07_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_08_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_09_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_10_2048_int8.h> // wavetable data
// Nic Samples
#include <samples/blop.h>
#include <samples/clap.h>
#include <samples/HH_closed.h>
#include <samples/HH_open.h>
#include <samples/kick.h>
#include <samples/snare.h>
#include <samples/strike.h>


// Defines our data tables
const int8_t * tables[16] ={
  BAMBOO_02_2048_DATA,
  BAMBOO_03_2048_DATA,
  BAMBOO_04_2048_DATA,
  BAMBOO_05_2048_DATA,
  BAMBOO_06_2048_DATA,
  BAMBOO_07_2048_DATA,
  BAMBOO_08_2048_DATA,
  BAMBOO_09_2048_DATA,
  BAMBOO_10_2048_DATA,
  Blop_DATA,
  clap_DATA,
  HH_closed_DATA,
  HH_open_DATA,
  kick_DATA,
  snare_DATA,
  strike_DATA
};

// Hold sample rates
const int sampleRates[16] {
  BAMBOO_02_2048_SAMPLERATE,
  BAMBOO_03_2048_SAMPLERATE,
  BAMBOO_04_2048_SAMPLERATE,
  BAMBOO_05_2048_SAMPLERATE,
  BAMBOO_06_2048_SAMPLERATE,
  BAMBOO_07_2048_SAMPLERATE,
  BAMBOO_08_2048_SAMPLERATE,
  BAMBOO_09_2048_SAMPLERATE,
  BAMBOO_10_2048_SAMPLERATE,
  Blop_SAMPLERATE,
  clap_SAMPLERATE,
  HH_closed_SAMPLERATE,
  HH_open_SAMPLERATE,
  kick_SAMPLERATE,
  snare_SAMPLERATE,
  strike_SAMPLERATE
};

// Hold number of cells
const int numCells[16] {
  BAMBOO_02_2048_NUM_CELLS,
  BAMBOO_03_2048_NUM_CELLS,
  BAMBOO_04_2048_NUM_CELLS,
  BAMBOO_05_2048_NUM_CELLS,
  BAMBOO_06_2048_NUM_CELLS,
  BAMBOO_07_2048_NUM_CELLS,
  BAMBOO_08_2048_NUM_CELLS,
  BAMBOO_09_2048_NUM_CELLS,
  BAMBOO_10_2048_NUM_CELLS,
  Blop_NUM_CELLS,
  clap_NUM_CELLS,
  HH_closed_NUM_CELLS,
  HH_open_NUM_CELLS,
  kick_NUM_CELLS,
  snare_NUM_CELLS,
  strike_NUM_CELLS
};


// use: Sample <table_size, update_rate> SampleName (wavetable)
//  Sample <BURROUGHS1_18649_NUM_CELLS, AUDIO_RATE> aSample(BURROUGHS1_18649_DATA);
float recorded_pitch = (float) BAMBOO_02_2048_SAMPLERATE / (float) BAMBOO_02_2048_NUM_CELLS;
Sample <BAMBOO_02_2048_NUM_CELLS, AUDIO_RATE> aSample(BAMBOO_02_2048_DATA); 

// Trellis stuff ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <i2c_t3.h>
#include "Adafruit_Trellis.h"

Adafruit_Trellis matrix = Adafruit_Trellis();
Adafruit_TrellisSet trellis = Adafruit_TrellisSet(&matrix);

#define NUMTRELLIS 1
#define numKeys (NUMTRELLIS * 16)

#define INTPIN 31
boolean triggered[16];  // For controlling Trellis key presses

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
EventDelay del;

void setup(){

 audioamp.begin();
 

  // Turn off AGC 
  audioamp.setAGCCompression(TPA2016_AGC_OFF);
  // we also have to turn off the release to really turn off AGC
  audioamp.setReleaseControl(0);
  

    audioamp.setGain(30);

  
  
  
  del.set(30);   // Set EventDelay

  // Set key trigger array
  for (uint8_t i=0; i < numKeys; i++) {
    triggered[i] = false; 
  }

  // Initialize trellis
  pinMode(INTPIN, INPUT);
  digitalWrite(INTPIN, HIGH);
  trellis.begin(0x70); // Trellis address

  //Clear LEDs
  for (uint8_t i=0; i < numKeys; i++) {
    trellis.clrLED(i); 
  }
  trellis.writeDisplay();





  Serial.begin(9600); // for Teensy 3.0/3.1, beware printout can cause glitches
  startMozzi();
}


//Progress bar function~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void LCD_progress_bar (int row, int var, int minVal, int maxVal)
{
  int block = map(var, minVal, maxVal, 0, 16);   // Block represent the current LCD space (modify the map setting to fit your LCD)
  int line = map(var, minVal, maxVal, 0, 80);     // Line represent the theoretical lines that should be printed 
  int bar = (line-(block*5));                             // Bar represent the actual lines that will be printed
  
  /* LCD Progress Bar Characters, create your custom bars */

  byte bar1[8] = { 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10};
  byte bar2[8] = { 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18};
  byte bar3[8] = { 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C};
  byte bar4[8] = { 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E};
  byte bar5[8] = { 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F};
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



void updateControl(){

  long new1, new2, new3, new4;
  new1 = constrain(knob1.read(), -100, 100);
  new2 = constrain(knob2.read(), -100, 100);
  new3 = constrain(knob3.read(), -100, 100);
  new4 = constrain(knob4.read(), -100, 100);
  
 
  if (new1 != position1) {
//update amp 
    int gainer = map(new1, 100, -100, -28, 30);
  audioamp.setGain(gainer);

    Serial.println(audioamp.getGain());
    
LCD_progress_bar(0, gainer, -28, 30);

lcd.setCursor(0, 1);
lcd.print("Volume"); 

      } else if(new2 != position2 || new3 != position3 || new4 != position4){}
      
      
 
  
      
      
//Update Positions
    position1 = new1;
    position2 = new2;
    position3 = new3;
    position4 = new4;
   
  
  
  
  
  
  
  
  
  
  // Read Trellis input
  if (del.ready()) {
    if (trellis.readSwitches()) {
      for (uint8_t i=0; i < numKeys; i++) {

        if (!triggered[i]) {
          if (trellis.justPressed(i)) {

            trellis.setLED(i);
            triggered[i] = true;
            
            aSample.setTable(tables[i]);
            aSample.setFreq((float) sampleRates[i] / (float) numCells[i]);
            aSample.start();

            //samples[i].start();
          }  
        } 
        else {
          if (trellis.justReleased(i)) {
            triggered[i] = false;
            trellis.clrLED(i);
          } 
        }
      }
    } 
    del.start();
  }

  trellis.writeDisplay(); //Change LEDs
}


int updateAudio() {
  return aSample.next();
}


void loop() {
  audioHook();
}

























