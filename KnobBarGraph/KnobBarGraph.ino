#include <Encoder.h>
#include <LiquidCrystalFast.h>



// initialize the library with the numbers of the interface pins
LiquidCrystalFast lcd(14, 15, 16, 20, 21, 22, 23);
         // LCD pins: RS  RW  EN  D4  D5  D6  D7

Encoder knob1(2, 3);

void setup() {
  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);
  lcd.write("Knob 1 Value");
}


long position1  = -999;


void LCD_progress_bar (int row, int var, int minVal, int maxVal)
{
  int block = map(var, minVal, maxVal, 0, 16);   // Block represent the current LCD space (modify the map setting to fit your LCD)
  int line = map(var, minVal, maxVal, 0, 80);     // Line represent the theoretical lines that should be printed 
  int bar = (line-(block*5));                             // Bar represent the actual lines that will be printed
  
  /* LCD Progress Bar Characters, create your custom bars */

  byte bar1[8] = { 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10};
  byte bar2[8] = { 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18};
  byte bar3[8] = { 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C};
  byte bar4[8] = { 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E};
  byte bar5[8] = { 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F};
  lcd.createChar(1, bar1);
  lcd.createChar(2, bar2);
  lcd.createChar(3, bar3);
  lcd.createChar(4, bar4);
  lcd.createChar(5, bar5);
  
  for (int x = 0; x < block; x++)                        // Print all the filled blocks
  {
    lcd.setCursor (x, row);
    lcd.write (1023);
  }
  
  lcd.setCursor (block, row);                            // Set the cursor at the current block and print the numbers of line needed
  if (bar != 0) lcd.write (bar);
  if (block == 0 && line == 0) lcd.write (1022);   // Unless there is nothing to print, in this case show blank
  
  for (int x = 16; x > block; x--)                       // Print all the blank blocks
  {
    lcd.setCursor (x, row);
    lcd.write (1022);
  }
}


void loop() {
    long new1;
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  new1 = knob1.read();
    if (new1 != position1) {
LCD_progress_bar(1, new1, 100, -100);
    position1 = new1;
    }
    }



