/* 
  Der leichte Einstieg in Arduino & Co.
  Mehrfachincludes
  
  Version 1.00, 16.05.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

#include "Led10.h"
#include "Led13.h"

void setup() {
  init10(); 
  init13();
}

void loop() {
  blink10(1000);
  blink13(500);
}
