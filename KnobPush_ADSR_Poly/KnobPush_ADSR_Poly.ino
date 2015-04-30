
#include <ADC.h>  // Teensy 3.0/3.1 uncomment this line and install http://github.com/pedvide/ADC
#include <MozziGuts.h>
#include <Oscil.h> // Sample template
#include <EventDelay.h>
#include <ADSR.h>


#include <tables/sin8192_int8.h> // a converted audio sample included in the Mozzi download



// use: Sample <table_size, update_rate> SampleName (wavetable)
Oscil <8192, AUDIO_RATE> aOscil0(SIN8192_DATA);
; 
Oscil <8192, AUDIO_RATE> aOscil1(SIN8192_DATA);
; 
Oscil <8192, AUDIO_RATE> aOscil2(SIN8192_DATA);
; 

int pitches[4] = {60, 64, 67, 69};
int knobpin[4] = {1, 4, 7, 10};

#define NUM_VOICES 3


const int NUMKNOBS = 4;

void setup(){
  pinMode(1, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);  


  startMozzi(); // :))
}





void updateControl(){
  for (int i = 0; i < NUMKNOBS; i++) {
    if (digitalRead(knobpin[i]) == 0 ) {
     
     int  freq = pitches[i]

  
  //Then Polyphonic Oscil Allocation

  static char whoseTurn;
  switch(whoseTurn){  
  case 0:
    aOscil0.setFreq(mtof(freq))
      //start ADSR 
      whoseTurn++;
      break;

  case 1:
      aOscil1.setFreq(mtof(freq))
      //start ADSR 
      whoseTurn++;
      break;

  case 2:
      aOscil2.setFreq(mtof(freq))
      //start ADSR 
      whoseTurn=0;
      break;

  }






}




int updateAudio(){
  long asig = (long)
    aOscil0.next() +
      aOscil1.next() +
      aOscil2.next();
  asig >>= 9; // shift back to audio output range?
  return (int) asig;
}


void loop(){
  audioHook();
}



