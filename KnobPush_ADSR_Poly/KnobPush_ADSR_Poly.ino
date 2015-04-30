
#include <ADC.h>  // Teensy 3.0/3.1 uncomment this line and install http://github.com/pedvide/ADC
#include <MozziGuts.h>
#include <Oscil.h> // Sample template
#include <EventDelay.h>
#include <ADSR.h>
#include <mozzi_midi.h>
#include <LiquidCrystalFast.h>



// initialize the library with the numbers of the interface pins
LiquidCrystalFast lcd(14, 15, 16, 20, 21, 22, 23);
// LCD pins: RS  RW  EN  D4  D5  D6  D7

//what is the difference between these two ways of declaring variables?
const int NUMKNOBS = 4;
#define NUM_VOICES 3

int pitches[NUMKNOBS] = {
60, 64, 67, 69};

int knobpin[NUMKNOBS] = {
  1, 4, 7, 10};
  
  
int current[NUMKNOBS];
int previous[NUMKNOBS];

int polyFlags[NUM_VOICES];


// Define params for envelopes
ADSR <CONTROL_RATE, AUDIO_RATE> envelope0;
ADSR <CONTROL_RATE, AUDIO_RATE> envelope1;
ADSR <CONTROL_RATE, AUDIO_RATE> envelope2;


#include <tables/sin8192_int8.h> // a converted audio sample included in the Mozzi download

// use: Sample <table_size, update_rate> SampleName (wavetable)
Oscil <8192, AUDIO_RATE> aOscil0(SIN8192_DATA);
; 
Oscil <8192, AUDIO_RATE> aOscil1(SIN8192_DATA);
; 
Oscil <8192, AUDIO_RATE> aOscil2(SIN8192_DATA);
; 





void setup(){
  for (int i = 0; i < NUMKNOBS; i++) {
    pinMode(knobpin[i], INPUT_PULLUP);
  }
  lcd.begin(16, 2);
  startMozzi(); // :))
}




//Function to create noteOn and noteOff methods
void makeNote(){


  for (int i = 0; i < NUMKNOBS; i++) {

    //update all pins
    current[i] = digitalRead(knobpin[i]);

    //if pin is newly 0

    if (current[i] == 1 && previous[i] == 0) {
      //make a message for noteOff

     
       if(pitches[i]==polyFlags[0]){
        envelope0.noteOff();
        polyFlags[i]=0;
      }
      else if(pitches[i]==polyFlags[1]){
        envelope1.noteOff();
        polyFlags[i]=0;
      }
      else if(pitches[i]==polyFlags[2]){
        envelope2.noteOff();
        polyFlags[i]=0;
      }
      /* more voices
      else if(pitches[i]==polyFlags[3]){
        envelope3.noteOff();
        polyFlags[i]=0;
      }   
     */
  /*    
      //show me the money
      lcd.setCursor(i, 0);
      lcd.write(" ");
*/
      //then set previous to 0
      previous[i] = 1;
    }

    //HOWEVER
    //if pin newly 0
    else if (current[i] == 0 && previous[i] == 1) {
        
        if(polyFlags[0]==0){
            aOscil0.setFreq(mtof(pitches[i]));
            envelope0.noteOn();
            polyFlags[0]=pitches[i];
        } else if(polyFlags[1]==0){
            aOscil1.setFreq(mtof(pitches[i]));
            envelope1.noteOn();
            polyFlags[1]=pitches[i];
        } else if(polyFlags[2]==0){
            aOscil2.setFreq(mtof(pitches[i]));
            envelope2.noteOn();
            polyFlags[2]=pitches[i];
        } 
      
      
      
/*
      //make a message for noteOn
      lcd.setCursor(i, 0);
      lcd.write(i);
*/
      //then set previous to 0
      previous[i] = 0;
    }
  }
}


void updateControl(){
  
//  Set envelope params  
      byte attack_level = 250;
      byte decay_level = 150;
      envelope0.setADLevels(attack_level,decay_level);
      envelope1.setADLevels(attack_level,decay_level);
      envelope2.setADLevels(attack_level,decay_level);
  
      unsigned int attack, decay, sustain, release_ms;
      attack = 10;
      decay = 100;
      sustain = 300;
      release_ms = 90;  
  
      envelope0.setTimes(attack,decay,sustain,release_ms); 
      envelope1.setTimes(attack,decay,sustain,release_ms);
      envelope2.setTimes(attack,decay,sustain,release_ms);  
 
 
  makeNote();
  
//Update envelopes  
envelope0.update();
envelope1.update();
envelope2.update();

}





int updateAudio(){


   return (int)    aOscil0.next() * envelope0.next() + aOscil1.next() * envelope1.next() +
                  aOscil2.next() * envelope2.next() >> 8;
   
   
}


void loop(){
  audioHook();
}




