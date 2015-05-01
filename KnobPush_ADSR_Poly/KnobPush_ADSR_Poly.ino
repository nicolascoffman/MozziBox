
#include <ADC.h>  // Teensy 3.0/3.1 uncomment this line and install http://github.com/pedvide/ADC
#include <MozziGuts.h>
#include <Oscil.h> // Sample template
#include <EventDelay.h>
#include <ADSR.h>
#include <mozzi_midi.h>
#include <LiquidCrystalFast.h>
#include <RCpoll.h>


//what is the difference between these two ways of declaring variables?
const int NUMKNOBS = 4;
#define NUM_VOICES 3

int pitches[NUMKNOBS] = {
  60, 64, 67, 69};

int knobpin[NUMKNOBS] = {
  1, 4, 7, 10};


#define CONTROL_RATE 64 

// initialize the library with the numbers of the interface pins
LiquidCrystalFast lcd(14, 15, 16, 20, 21, 22, 23);
// LCD pins: RS  RW  EN  D4  D5  D6  D7

EventDelay noteDelay;

boolean current[NUMKNOBS];
boolean previous[NUMKNOBS];
int storage[NUMKNOBS];



ADSR <CONTROL_RATE, AUDIO_RATE> envelope0;
;
ADSR <CONTROL_RATE, AUDIO_RATE> envelope1;
;
ADSR <CONTROL_RATE, AUDIO_RATE> envelope2;
;

ADSR <CONTROL_RATE, AUDIO_RATE> envelope[NUM_VOICES] = {
  envelope0, envelope1, envelope2};

#include <tables/sin8192_int8.h> // a converted audio sample included in the Mozzi download

// use: Sample <table_size, update_rate> SampleName (wavetable)
Oscil <8192, AUDIO_RATE> aOscil0(SIN8192_DATA);
; 
Oscil <8192, AUDIO_RATE> aOscil1(SIN8192_DATA);
; 
Oscil <8192, AUDIO_RATE> aOscil2(SIN8192_DATA);
; 

Oscil <8192, AUDIO_RATE> oscilator[NUM_VOICES] = {
  aOscil0, aOscil1, aOscil2};



void setup(){
  for (int i = 0; i < NUMKNOBS; i++) {
    pinMode(knobpin[i], INPUT_PULLUP);
  }
  lcd.begin(16, 2);
  Serial.begin(9600);

  startMozzi(); // :))

  for(int f=0; f<NUM_VOICES; f++){
    envelope[f].noteOff();
  }

}


void playNote(int note, int z){

  if (z==NUM_VOICES){
    oscilator[0].setFreq((mtof(pitches[note])));
    envelope[0].noteOn();
    
    //find O in storage[];
    for(int repl=0; repl<NUMKNOBS; repl++){
      if(storage[repl] == 0){
    //replace it with -1
        storage[repl]=-1;
      }
    }
     storage[note]=0;
  }
  else  if(envelope[z].playing()==false){
    oscilator[z].setFreq((mtof(pitches[note])));
    envelope[z].noteOn();
    //Store note value
    storage[note]=z;

  }  
  else if(envelope[z].playing()==true){
    playNote(note, z+1);
  }

}


void stopNote(int note){
  envelope[storage[note]].noteOff();
}


void buttonMessages(){

  for (int i = 0; i < NUMKNOBS; i++) {

    //if pin pressed
    if(digitalRead(knobpin[i])==0){
      //pin index current is true
      current[i] = true; 
    }
    else if(digitalRead(knobpin[i])==1){
      //pin index current is false
      current[i] = false;  
    } 

    //if recent change; current = !previous
    if(current[i] == !previous[i]){
      //if recently pressed
      if(current[i]){
        playNote(i, 0);
      }
      else if(!current[i]){
        stopNote(i);
      }
    }
    previous[i]=current[i];
  }
}


void updateControl(){





  //  Set envelope params  
  byte attack_level = 250;
  byte decay_level = 150;
  envelope[0].setADLevels(attack_level,decay_level);
  envelope[1].setADLevels(attack_level,decay_level);
  envelope[2].setADLevels(attack_level,decay_level);

  unsigned int attack, decay, sustain, release_ms;
  attack = 10;
  decay = 100;
  sustain = 6000;
  release_ms = 600;  

  envelope[0].setTimes(attack,decay,sustain,release_ms); 
  envelope[1].setTimes(attack,decay,sustain,release_ms);
  envelope[2].setTimes(attack,decay,sustain,release_ms);  


  buttonMessages();



  //Update envelopes
  for(int q=0; q<NUM_VOICES; q++){
    envelope[q].update();


    Serial.print("    Envelope ");
    Serial.print(q);
    if(envelope[q].playing()==false){
      Serial.println(" is dead");
    }
    else     if(envelope[q].playing()==true){
      Serial.println(" is playing");
    }  



  }
}





int updateAudio(){


  return (int)    oscilator[0].next() * envelope[0].next() + oscilator[1].next() * envelope[1].next() +
    oscilator[2].next() * envelope[2].next() >> 8;


}


void loop(){
  audioHook();
}








