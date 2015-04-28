/* Encoder Library - TwoKnobs Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>
#include <LiquidCrystalFast.h>

// initialize the library with the numbers of the interface pins
LiquidCrystalFast lcd(14, 15, 16, 20, 21, 22, 23);
         // LCD pins: RS  RW  EN  D4  D5  D6  D7


// Change these pin numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder knob1(2, 3);
Encoder knob2(5, 6);
Encoder knob3(8, 9);
Encoder knob4(11, 12);
//   avoid using pins with LEDs attached


void setup() {
  lcd.begin(16, 2);
  // Print a message to the LCD.

}

long position1  = -999;
long position2  = -999;
long position3  = -999;
long position4  = -999;

void loop() {
  long new1, new2, new3, new4;
  new1 = knob1.read();
  new2 = knob2.read();
  new3 = knob3.read();
  new4 = knob4.read();
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
    
    position1 = new1;
    position2 = new2;
    position3 = new3;
    position4 = new4;
   
  }
}
