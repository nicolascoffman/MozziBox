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
  aSample.setFreq(recorded_pitch);
  

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


void updateControl(){

  // Read Trellis input
  if (del.ready()) {
    if (trellis.readSwitches()) {
      for (uint8_t i=0; i < numKeys; i++) {

        if (!triggered[i]) {
          if (trellis.justPressed(i)) {

            trellis.setLED(i);
            triggered[i] = true;
            
            aSample.setTable(tables[i]);
//            aSample.setFreq((float) sampleRates[i] / (float) numCells[i]);
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

























