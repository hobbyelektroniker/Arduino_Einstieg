/* 
  Der leichte Einstieg in Arduino & Co.
  Projekt Alarmanlage
  PIR - Sensor
  
  Version 1.00, 14.05.2019
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

#define VERS 100

#include <arduino.h>
#include "pir.h"

// Pin - Definitionen
const int pin = 6;

boolean pir_bewegung() {
  return digitalRead(pin);
}

void pir_init() {
}

int pir_version() {
  return VERS;
}
