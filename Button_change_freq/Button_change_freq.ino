/*
   Example using a piezo to change the frequency of a sinewave
   with Mozzi sonification library.
   
   Demonstrates the use of Oscil to play a wavetable, and analog input for control.
   
   This example goes with a tutorial on the Mozzi site:
   http://sensorium.github.io/Mozzi/learn/introductory-tutorial/
   
   The circuit:
     Audio output on digital pin 9 on a Uno or similar, or
    DAC/A14 on Teensy 3.0/3.1, or 
     check the README or http://sensorium.github.com/Mozzi/
   
     Piezo on analog pin 3:
       + connection of the piezo attached to the analog pin
       - connection of the piezo attached to ground
       1-megohm resistor between the analog pin and ground
   
   Mozzi help/discussion/announcements:
   https://groups.google.com/forum/#!forum/mozzi-users
   
   Tim Barrass 2013, CC by-nc-sa.
*/

#include <ADC.h>  // Teensy 3.0/3.1 uncomment this line and install http://github.com/pedvide/ADC
#include <MozziGuts.h>
#include <Oscil.h> // oscillator 
#include <tables/sin2048_int8.h> // table for Oscils to play
#include <Smooth.h>

// increase the rate of updateControl from the default of 64, to catch the piezo's rapid transients
#define CONTROL_RATE 128 

const int PIEZO_PIN = 3;  // set the analog input pin for the piezo 

// use: Oscil <table_size, update_rate> oscilName (wavetable), look in .h file of table #included above
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin(SIN2048_DATA);


void setup(){
  pinMode(1, INPUT_PULLUP);
pinMode(4, INPUT_PULLUP);
pinMode(7, INPUT_PULLUP);
pinMode(10, INPUT_PULLUP);
  startMozzi(CONTROL_RATE); // :)) use the control rate defined above
}


void updateControl(){
 
  for(int i=1; i<=10; i+=3){
  int thing = digitalRead(i);

  
  switch (thing) {
  case 0: 
     frequency = 440;
    break;
  case 1:
    frequency = 480;
    break;
  case 2:
    frequency = 520;
    break;
  case 3:
    frequency = 560;
    break;
  default: 
    frequency = 0;
  }
}   
}
  
  // set the frequency
  aSin.setFreq(frequency);
  
  Serial.println(); // next line
}


int updateAudio(){
  return aSin.next();
}


void loop(){
  audioHook();
}







