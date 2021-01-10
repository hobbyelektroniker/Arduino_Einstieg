/* 
  Modularisierung mit Header - Files
  Auslagerung von globalen Konstanten und Variablen in globals.h
  Eine weitere Funktion in work.cpp
    
  Version 1.00, 06.01.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

#include "globals.h"
#include "work.h"

int anzahl = startAnzahl;
int total = 0;

void setup() {
  Serial.begin(SERIAL_SPEED);
  Serial.println();
  Serial.println(String("Start Version ")+VERSION);

  doIt();
  doIt(4);
  doIt(5);

}


void loop() {}
