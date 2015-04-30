#include <LiquidCrystalFast.h>

LiquidCrystalFast lcd(14, 15, 16, 20, 21, 22, 23);

const int NUMKNOBS = 4;
int knobpin[NUMKNOBS] = {
  1, 4, 7, 10};
int current[NUMKNOBS];
int previous[NUMKNOBS];

void setup(){
  lcd.begin(16, 2);

  for (int i = 0; i < NUMKNOBS; i++) {
    pinMode(knobpin[i], INPUT_PULLUP);
  }
}



//Function to create noteStart and noteStop messages
void makeNote(){


  for (int i = 0; i < NUMKNOBS; i++) {

    current[i] = digitalRead(knobpin[i]);

    //if newly 0

    if (current[i] == 1 && previous[i] == 0) {
      //make a message for noteStop
      lcd.setCursor(i, 0);
      lcd.write(" ");

      //then set previous to 0
      previous[i] = 1;
    }

    //HOWEVER
    //if newly 0
    else   if (current[i] == 0 && previous[i] == 1) {

      //make a message for noteStart
      lcd.setCursor(i, 0);
      lcd.write(i);

      //then set previous to 0
      previous[i] = 0;
    }
  }
}

void loop(){
  makeNote();
}


