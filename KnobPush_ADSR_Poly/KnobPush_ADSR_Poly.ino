
#include <ADC.h>  // Teensy 3.0/3.1 uncomment this line and install http://github.com/pedvide/ADC
#include <MozziGuts.h>
#include <Oscil.h> // Sample template
#include <EventDelay.h>
#include <ADSR.h>
#include <mozzi_midi.h>
#include <LiquidCrystalFast.h>

#include <tables/sin8192_int8.h> // a converted audio sample included in the Mozzi download

// initialize the library with the numbers of the interface pins
LiquidCrystalFast lcd(14, 15, 16, 20, 21, 22, 23);
// LCD pins: RS  RW  EN  D4  D5  D6  D7


// for triggering the envelopes
EventDelay noteDelay0;
EventDelay noteDelay1;
EventDelay noteDelay2;

// Define params for envelope
ADSR <CONTROL_RATE, AUDIO_RATE> envelope;


// use: Sample <table_size, update_rate> SampleName (wavetable)
Oscil <8192, AUDIO_RATE> aOscil0(SIN8192_DATA);
; 
Oscil <8192, AUDIO_RATE> aOscil1(SIN8192_DATA);
; 
Oscil <8192, AUDIO_RATE> aOscil2(SIN8192_DATA);
; 



int pitches[4] = {
  60, 64, 67, 69};
int knobpin[4] = {
  1, 4, 7, 10};

#define NUM_VOICES 3


const int NUMKNOBS = 4;

void setup(){
  pinMode(1, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);  

  lcd.begin(16, 2);
  startMozzi(); // :))
}





void updateControl(){
  
//  Set envelope params  
      byte attack_level = 250;
      byte decay_level = 150;
      envelope.setADLevels(attack_level,decay_level);
  
      unsigned int attack, decay, sustain, release_ms;
      attack = 10;
      decay = 100;
      sustain = 300;
      release_ms = 90;  
  
      envelope.setTimes(attack,decay,sustain,release_ms); 
  
  
// Read knobs, set freq  
  for (int i = 0; i < NUMKNOBS; i++) {
    if (digitalRead(knobpin[i]) == 0 ) {
  
      //Set pitch
      int  freq = pitches[i];
/*    
//     start note 
      aOscil0.setFreq(mtof(freq));
      envelope.noteOn();
      noteDelay.start(attack+decay+sustain+release_ms);
 */    
     
//     FEEDBACK
      lcd.setCursor(0, 0);
      lcd.print(i);
      lcd.setCursor(0, 1);
      lcd.print(freq);     

      //The Polyphonic Oscil Allocation
   
  static char whoseTurn;
       switch(whoseTurn){  
       case 0:
       aOscil0.setFreq(mtof(freq));
       envelope.noteOn();
       noteDelay0.start(attack+decay+sustain+release_ms);
       lcd.setCursor(7,1);
       lcd.print("Oscil0");
       whoseTurn++;
       break;
       
       case 1:
       aOscil1.setFreq(mtof(freq));
       envelope.noteOn();
       noteDelay1.start(attack+decay+sustain+release_ms);
       lcd.setCursor(7,1);
       lcd.print("Oscil1");
       whoseTurn++;
       break;
       
       case 2:
       aOscil2.setFreq(mtof(freq));
       envelope.noteOn(); 
       noteDelay0.start(attack+decay+sustain+release_ms);
       lcd.setCursor(7,1);
       lcd.print("Oscil2");
       whoseTurn=0;
       break;
       
       }

       

    }
  }
         envelope.update();

}




int updateAudio(){

     return (int) (envelope.next() *  aOscil0.next())>>8;
//  return  aOscil0.next();

  /*    This is the update aduio adapted from "Multi Oscil"
   long asig = (long)
   aOscil0.next() +
   aOscil1.next() +
   aOscil2.next();
   asig >>= 9; // shift back to audio output range?
   return (int) asig;
   
   */
}


void loop(){
  audioHook();
}




