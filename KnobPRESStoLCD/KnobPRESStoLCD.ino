
#include <LiquidCrystalFast.h>



// initialize the library with the numbers of the interface pins
LiquidCrystalFast lcd(14, 15, 16, 20, 21, 22, 23);
         // LCD pins: RS  RW  EN  D4  D5  D6  D7

void setup() {
  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);

pinMode(1, INPUT_PULLUP);
pinMode(4, INPUT_PULLUP);
pinMode(7, INPUT_PULLUP);
pinMode(10, INPUT_PULLUP);

}





void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):

int new1 = digitalRead(1);
int new2 = digitalRead(4);
int new3 = digitalRead(7);
int new4 = digitalRead(10);

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

}



