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

#include <samples/bamboo/bamboo_00_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_01_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_02_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_03_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_04_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_05_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_06_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_07_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_08_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_09_2048_int8.h> // wavetable data
#include <samples/bamboo/bamboo_10_2048_int8.h> // wavetable data



const int8_t * tables[16] ={
  BAMBOO_00_2048_DATA,
  BAMBOO_01_2048_DATA,
  BAMBOO_02_2048_DATA,
  BAMBOO_03_2048_DATA,
  BAMBOO_04_2048_DATA,
  BAMBOO_05_2048_DATA,
  BAMBOO_06_2048_DATA,
  BAMBOO_07_2048_DATA,
  BAMBOO_08_2048_DATA,
  BAMBOO_09_2048_DATA,
  BAMBOO_10_2048_DATA,
};

// Trellis stuff ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <i2c_t3.h>
#include "Adafruit_Trellis.h"

Adafruit_Trellis matrix = Adafruit_Trellis();
Adafruit_TrellisSet trellis = Adafruit_TrellisSet(&matrix);

#define NUMTRELLIS 1
#define numKeys (NUMTRELLIS * 16)

#define INTPIN 31

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
EventDelay del;
EventDelay lightDel;

const char KNOB_PIN = 1;  // set the analog input pin for the knob
const char PIEZO_PIN = 3;  // set the analog input pin for the piezo 
const int threshold = 80;  // threshold value to decide when the detected signal is a knock or not

// use: Sample <table_size, update_rate> SampleName (wavetable)
//  Sample <BURROUGHS1_18649_NUM_CELLS, AUDIO_RATE> aSample(BURROUGHS1_18649_DATA);
float recorded_pitch = (float) BURROUGHS1_18649_SAMPLERATE / (float) BURROUGHS1_18649_NUM_CELLS;
Sample <BURROUGHS1_18649_NUM_CELLS, AUDIO_RATE> aSample(BAMBOO_00_2048_DATA); 


boolean triggered[16]; 

void setup(){

  // Set EventDelays
  del.set(30);
  lightDel.set(500);
  
  // Set key trigger array
  for (uint8_t i=0; i < numKeys; i++) {
    triggered[i] = false; 
  }


  pinMode(1, INPUT_PULLUP);



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
  //  Serial.begin(115200); // set up the Serial output so we can look at the piezo values // set up the Serial output so we can look at the piezo values
  startMozzi(); // :))
}


void updateControl(){
  // read the knob
  //  int knob_value = mozziAnalogRead(KNOB_PIN); // value is 0-1023
  int knob_value = digitalRead(1);

  // map it to values between 0.1 and about double the recorded pitch
  float pitch = (recorded_pitch * (float) 512 / 512.f) + 0.1f; 

  // set the sample playback frequency
  aSample.setFreq(pitch);

  // Clear trellis lights periodically
  if (lightDel.ready()) {
    for (uint8_t i=0; i < numKeys; i++) {
      //trellis.clrLED(i);
    }
  }


  // Read Trellis input
  if (del.ready()) {
    if (trellis.readSwitches()) {
      for (uint8_t i=0; i < 11; i++) {

        if (!triggered[i]) {
          if (trellis.justPressed(i)) {
            
            trellis.setLED(i);
            triggered[i] = true;
            // Play corresponding sample
            aSample.setTable(tables[i]);
            aSample.start();

            //samples[i].start();
          }  
        } else {
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























