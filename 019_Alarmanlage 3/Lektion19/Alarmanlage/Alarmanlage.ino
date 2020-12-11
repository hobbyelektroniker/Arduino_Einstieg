/* 
  Der leichte Einstieg in Arduino & Co.
  Projekt Alarmanlage
  
  Version 1.00, 09.05.2019
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

#include "globals.h"
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

void alarmTest() {
  int stufe;
  if (abstand_cm() < 10) {
    stufe = 4;
  } else if (licht_staerke() > 850 && pir_bewegung()) {
    stufe = 3;
  } else if (pir_bewegung()) {
    stufe = 2;
  } else if (licht_staerke() > 850) {
    stufe = 1;
  } else {
    stufe = 0;
  }    
  display_show(stufe);
  leds_show(stufe);
}

void loop() {
  alarmTest();
}
