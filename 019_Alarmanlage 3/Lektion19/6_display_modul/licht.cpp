/* 
  Der leichte Einstieg in Arduino & Co.
  Projekt Alarmanlage
  Licht - Sensor (LDR)
  
  Version 1.00, 09.05.2019
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

#define VERS 100

#include <arduino.h>
#include "globals.h"
#include "licht.h"

// Pin - Definitionen
const int pin = A2; 

int licht_staerke() {
  return analogRead(pin);
}

void licht_init() {
}

int licht_version() {
  return VERS;
}
