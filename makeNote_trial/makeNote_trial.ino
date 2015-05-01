#include <LiquidCrystalFast.h>

LiquidCrystalFast lcd(14, 15, 16, 20, 21, 22, 23);


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


void setup(){
  lcd.begin(16, 2);

  for (int i = 0; i < NUMKNOBS; i++) {
    pinMode(knobpin[i], INPUT_PULLUP);
  }
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

void loop(){
  makeNote();
}


