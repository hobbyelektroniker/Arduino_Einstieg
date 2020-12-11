/*
16 x 2 Display parallel
 
  Version 1.0
  Der Hobbyelektroniker
  Der Code ist Public Domain und kann ohne Einschränkungen frei verwendet werden
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pins für rs, en, d4, d5, d6, d7

void setup() {
  lcd.begin(16, 2);  // 16 Zeichen, 2 Zeilen
  
  lcd.print("Hallo Arduino");
  lcd.setCursor(0,1);
  lcd.print("12345");
  
  delay(1000);  
  lcd.clear();  // löscht den ganzen Bildschirm
  lcd.print("Hallo Arduino");
  lcd.setCursor(0,1);
  lcd.print("äöü"); // Umlaute werden nicht richtig dargestellt
  
}

void loop() {
}
