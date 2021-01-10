/* 
  Modularisierung mit Header - Files
  Auslagerung von globalen Konstanten und Variablen in globals.h
  Berechnungsfunktion in Work wird aufgeteilt in .h und .cpp.
    
  Version 1.00, 06.01.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

// Dieses Beispiel funktioniert NICHT !!!

#include "globals.h"
#include "work.h"

void setup() {
  Serial.begin(SERIAL_SPEED);
  Serial.println();
  Serial.println(String("Start Version ")+VERSION);

  Serial.print(String("Anzahl: ") + anzahl);
  rechneTotal();
  Serial.println(String(", Total: ") + total);

  anzahl = 4;
  Serial.print(String("Anzahl: ") + anzahl);
  rechneTotal();
  Serial.println(String(", Total: ") + total);

  anzahl = 5;
  Serial.print(String("Anzahl: ") + anzahl);
  rechneTotal();
  Serial.println(String(", Total: ") + total);

}


void loop() {}
