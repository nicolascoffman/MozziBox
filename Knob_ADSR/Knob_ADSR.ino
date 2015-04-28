/*  Example applying an ADSR envelope to an audio signal
    with Mozzi sonification library.  This shows 
    internal updates at CONTROL_RATE, using update() in updateControl(),
    with interpolation and output using next() at AUDIO_RATE in updateAudio().
    This is the "ordinary" way to use ADSR for smooth amplitude transitions while
    maintaining reasonable efficiency by updating internal states in updateControl().
    
    Demonstrates a simple ADSR object being controlled with
    noteOn() and noteOff() instructions.
  
    Tim Barrass 2013, CC by-nc-sa.
*/

#include <ADC.h>  // Teensy 3.0/3.1 uncomment this line and install http://github.com/pedvide/ADC
#include <MozziGuts.h>
#include <Oscil.h>
#include <EventDelay.h>
#include <ADSR.h>
#include <tables/sin8192_int8.h> 
#include <mozzi_rand.h>
#include <mozzi_midi.h>
#include <Encoder.h>
#include <LiquidCrystalFast.h>


#define CONTROL_RATE 64

LiquidCrystalFast lcd(14, 15, 16, 20, 21, 22, 23);
Encoder knob1(2, 3);
Encoder knob2(5, 6);
Encoder knob3(8, 9);
Encoder knob4(11, 12);

long position1  = -999;
long position2  = -999;
long position3  = -999;
long position4  = -999;

  long new1, new2, new3, new4;

Oscil <8192, AUDIO_RATE> aOscil(SIN8192_DATA);; 

// for triggering the envelope
EventDelay noteDelay;

ADSR <CONTROL_RATE, AUDIO_RATE> envelope;

boolean note_is_on = true;

void setup(){
  
        // choose envelope levels
      byte attack_level = 200;
      byte decay_level = 100;
      envelope.setADLevels(attack_level,decay_level);
  
  lcd.begin(16, 2);

  noteDelay.set(2000); // 2 second countdown
  startMozzi(CONTROL_RATE);
}


unsigned int duration, attack, decay, sustain, release_ms;



void updateControl(){
  if(noteDelay.ready()){
    
  new1 = map(knob1.read(), 100, -100, 10, 1000);
  new2 = map(knob2.read(), 100, -100, 10, 1000);
  new3 = map(knob3.read(), 100, -100, 10, 1000);
  new4 = map(knob4.read(), 100, -100, 10, 1000);
    
  



 if (new1 != position1 || new2 != position2 || new3 != position3 || new4 != position4) {
  lcd.setCursor(0, 0);
      lcd.print("1 =");
  lcd.setCursor(0, 1);
      lcd.print(new1);
      
  lcd.setCursor(4, 0);
    lcd.print("2 =");
  lcd.setCursor(4, 1);
    lcd.print(new2);
    
   lcd.setCursor(8, 0);
      lcd.print("3 =");
  lcd.setCursor(8, 1);
      lcd.print(new3);
      
  lcd.setCursor(12, 0);
    lcd.print("4 =");
  lcd.setCursor(12, 1);
    lcd.print(new4);
    
 envelope.setTimes(new1, new2, new3, new4);   
    
    position1 = new1;
    position2 = new2;
    position3 = new3;
    position4 = new4;
   
  }
 
     envelope.noteOn();

     byte midi_note = rand(24)+36;
     aOscil.setFreq((int)mtof(midi_note));
    
     noteDelay.start(attack+decay+sustain+release_ms);
     
   }
  envelope.update();
} 


int updateAudio(){
  return (int) (envelope.next() * aOscil.next())>>8;
}


void loop(){
  audioHook(); // required here
}






