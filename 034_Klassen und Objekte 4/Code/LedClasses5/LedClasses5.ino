/* 
  Objektorientiert Programmierung
  Eine Blinkfunktion
    
  Version 1.00, 15.06.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

#include "leds.h"


// Instanzen erzeugen
LedFunktionen led1; 

void setup() {
  Serial.begin(9600);
  led1.setBlinkZeit(500); // Pause in ms
}

void printStatus() {
  static long oldStatus = 0;
  int status = led1.getStatus(); 
  if (status != oldStatus) {
    oldStatus = status;
    Serial.println(led1.getStatusText()); 
  }
}

void loop() {
  led1.blink();
  printStatus();
}
