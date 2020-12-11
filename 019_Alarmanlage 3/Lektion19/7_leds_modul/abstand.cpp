/* 
  Der leichte Einstieg in Arduino & Co.
  Projekt Alarmanlage
  Ultraschallsensor
  
  Version 1.00, 09.05.2019
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/


#define VERS 100

#include <arduino.h>
#include "globals.h"
#include "abstand.h"

#include <NewPing.h>

const int trigger_Pin = 7;
const int echo_Pin = 8;
const int maxDistanz = 80; // 80 cm

NewPing sonar(trigger_Pin,echo_Pin,maxDistanz);

int abstand_cm() {
  int cm = sonar.ping_cm();
  if (!cm) cm = maxDistanz;
  return cm;
}

void abstand_init() {
  pinMode(trigger_Pin,OUTPUT);
  digitalWrite(trigger_Pin,LOW);
}

int abstand_version() {
  return VERS;
}
