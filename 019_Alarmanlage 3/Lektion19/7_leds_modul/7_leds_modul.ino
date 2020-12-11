/* 
  Der leichte Einstieg in Arduino & Co.
  Projekt Alarmanlage
  
  Version 1.00, 09.05.2019
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

#include "pir.h"
#include "licht.h"
#include "abstand.h"
#include "display.h"
#include "leds.h"

void setup() {
  pir_init();
  licht_init();
  abstand_init();
  display_init();
  leds_init();
}

void loop() {
  int i = 0;
  display_show(i);
  leds_show(i);
}
