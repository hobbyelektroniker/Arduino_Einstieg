/*
16 x 2 Display parallel
 
  Version 1.0
  Der Hobbyelektroniker
  Der Code ist Public Domain und kann ohne Einschränkungen frei verwendet werden
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pins für rs, en, d4, d5, d6, d7

void printX(const char a[]) {
  int i = 0;
  while (true) {
    char ch = a[i++];
    if (ch == 0) return;
    if (ch == '&') {
      ch = a[i++];
      switch (ch) {
        case 'a': lcd.write(0xE1); 
                  break;
        case 'o': lcd.write(0xEF);
                  break; 
        case 'u': lcd.write(0xF5); 
                  break;
        case 'g': lcd.write(0xDF); 
                  break;
        case 'O': lcd.write(0xF4); 
                  break;
        case 'U': lcd.write(0xF3); 
                  break;
        case 'S': lcd.write(0xF6); 
                  break;
        default: if (ch < 128) lcd.write(ch);      
      }
    } else if (ch < 128) {
      lcd.write(ch);
    }    
  }
}

void setup() {
  lcd.begin(16, 2);  // 16 Zeichen, 2 Zeilen
  printX("Sonderzeichen:");
  lcd.setCursor(0,1);
  printX("&a &o &u &g &O &U &S");
}

void loop() {
}
