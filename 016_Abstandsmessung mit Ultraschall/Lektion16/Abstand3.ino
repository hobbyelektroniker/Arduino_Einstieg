/*
Abstandsmessung mit Ultraschall
 
  Version 1.0
  Der Hobbyelektroniker
  Der Code ist Public Domain und kann ohne Einschränkungen frei verwendet werden
*/

#include <LiquidCrystal.h>

const int trigger_Pin = 7;
const int echo_Pin = 8;

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
        default: if (ch < 128) lcd.write(ch);      
      }
    } else if (ch < 128) {
      lcd.write(ch);
    }
  } 
}

void setup() {
  pinMode(trigger_Pin,OUTPUT);
  digitalWrite(trigger_Pin,LOW);
  lcd.begin(16, 2);  // 16 Zeichen, 2 Zeilen
}


void abstand() {
  // Triggersignal senden
  digitalWrite(trigger_Pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_Pin,LOW);
  
  // Echo auswerten
  unsigned long timeout = 5000; // Maximale Distanz etwa 70 cm
  unsigned long pulsbreite = pulseIn(echo_Pin, HIGH, timeout); // in Mikrosekunden
  float cm = pulsbreite / 58.0;

  lcd.clear();
  if (cm) {
    lcd.print(cm); lcd.print(" cm");
  } else {
    lcd.print("Maximale Distanz");
    lcd.setCursor(0,1);
    printX("&uberschritten!");
  }
}

void loop() {
  abstand();
  delay(2000);
}
