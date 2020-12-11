/* 
  Der leichte Einstieg in Arduino & Co.
  mehrere Dateien
  
  Version 1.00, 16.05.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

#define LED 13

#include "test1.h"

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  blink();
}
