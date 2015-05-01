
#include <ADC.h>  // Teensy 3.0/3.1 uncomment this line and install http://github.com/pedvide/ADC
#include <MozziGuts.h>
#include <Oscil.h> // Sample template
#include <EventDelay.h>
#include <ADSR.h>
#include <mozzi_midi.h>
#include <LiquidCrystalFast.h>
#include <Encoder.h>

//Encoder setup
Encoder knob1(2, 3);
Encoder knob2(5, 6);
Encoder knob3(8, 9);
Encoder knob4(11, 12);

long position1  = -999;
long position2  = -999;
long position3  = -999;
long position4  = -999;




//what is the difference between these two ways of declaring variables?
const int NUMKNOBS = 4;
#define NUM_VOICES 3

int pitches[NUMKNOBS] = {
  57, 61, 64, 66};

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


// ADSR Stuff
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
  release_ms = 50;  

  envelope[0].setTimes(attack,decay,sustain,release_ms); 
  envelope[1].setTimes(attack,decay,sustain,release_ms);
  envelope[2].setTimes(attack,decay,sustain,release_ms);  

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

long new1, new2, new3, new4;
  new1 = constrain(knob1.read(), -100, 100);
  new2 = constrain(knob2.read(), -100, 100);
  new3 = constrain(knob3.read(), -50, 50);
  new4 = constrain(knob4.read(), -100, 100);
  
 
  if (new1 != position1 || new2 != position2 || new3 != position3 || new4 != position4) {
    
    //  Set envelope params  
    int ratio =  map(new3, 50, -50, 1, 5);
    
   int val =  255/(ratio+1);
    
    
  byte attack_level = val*ratio;
  byte decay_level = val;
  envelope[0].setADLevels(attack_level,decay_level);
  envelope[1].setADLevels(attack_level,decay_level);
  envelope[2].setADLevels(attack_level,decay_level);

  unsigned int attack, decay, sustain, release_ms;
  attack = map(new1, 100, -100, 50, 999);
  decay =  map(new2, 100, -100, 50, 999);
  sustain = 6000;
  release_ms =  map(new4, -100, 100, 100, 999);  

  envelope[0].setTimes(attack,decay,sustain,release_ms); 
  envelope[1].setTimes(attack,decay,sustain,release_ms);
  envelope[2].setTimes(attack,decay,sustain,release_ms);  


//Update Display
  lcd.setCursor(0, 0);
      lcd.print("Atk");
      if(attack<100){

  lcd.setCursor(0, 1);
      lcd.print(" ");
     lcd.setCursor(1, 1);      
      lcd.print(attack);
      }else{
        lcd.setCursor(0, 1);
        lcd.print(attack);
      }
      
  lcd.setCursor(4, 0);
    lcd.print("Dcy");
          if(decay<100){
  lcd.setCursor(4, 1);
      lcd.print(" ");
     lcd.setCursor(5, 1);      
      lcd.print(decay);
      }else{
    lcd.setCursor(4, 1);
    lcd.print(decay);
      }

    
   lcd.setCursor(8, 0);
      lcd.print("Rat");
   lcd.setCursor(8, 1);
      lcd.print(ratio);
   lcd.setCursor(9, 1);
      lcd.print(":1");
      
  lcd.setCursor(12, 0);
    lcd.print("Rel");
  lcd.setCursor(12, 1);
    lcd.print(release_ms);
    

//Update Positions
    position1 = new1;
    position2 = new2;
    position3 = new3;
    position4 = new4;
   
  }

 
  

  buttonMessages();



  //Update envelopes
  for(int q=0; q<NUM_VOICES; q++){
    envelope[q].update();


  }
}





int updateAudio(){


  return (int)    oscilator[0].next() * envelope[0].next() + oscilator[1].next() * envelope[1].next() +
    oscilator[2].next() * envelope[2].next() >> 8;


}


void loop(){
  audioHook();
}








