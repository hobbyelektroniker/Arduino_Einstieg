/* 
  Der leichte Einstieg in Arduino & Co.
  Projekt Alarmanlage
  Leuchtdioden
  
  Version 1.00, 09.05.2019
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

#define VERS 100

#include <arduino.h>
#include "globals.h"
#include "leds.h"

// Pin - Definitionen
const int ledPins[] = {9,10,13}; 

// Index in Array
const int gruen = 0;
const int gelb = 1;
const int rot = 2;

// mögliche Zustände der Led's
const int aus = 0;
const int ein = 1;
const int blinken = 2;

const int blinkZeit = 500;  // 500 ms 

// Aktuelle Zustände der Led's
int ledZustand[] = {aus,aus,aus};


// Schalten der Led's, die blinken sollen
void ledBlink() {
  static unsigned long alteZeit = 0;
  unsigned long zeit = millis();
  if (zeit >= alteZeit + blinkZeit) {
    alteZeit = zeit;
    for (int i = gruen; i <= rot; i++) {
      if (ledZustand[i] == blinken) digitalWrite(ledPins[i],!digitalRead(ledPins[i]));
    }
  }
}

// Schalten der Led's, die nicht blinken sollen
void ledAnzeige() {
  for (int i = gruen; i <= rot; i++) {
    if (ledZustand[i] == aus) digitalWrite(ledPins[i],LOW);
    if (ledZustand[i] == ein) digitalWrite(ledPins[i],HIGH);
  }
}


void leds_show(int neuerAlarm) {
  static int alarm = -1;
  ledBlink();
  if (alarm == neuerAlarm) return; // nichts geändert 
  alarm = neuerAlarm;
  switch (alarm) {
    case 0:
      ledZustand[gruen] = ein;
      ledZustand[gelb] = aus;
      ledZustand[rot] = aus;
      break;
    case 1:;
    case 2:
      ledZustand[gruen] = aus;
      ledZustand[gelb] = ein;
      ledZustand[rot] = aus;
      break;
    case 3:
      ledZustand[gruen] = aus;
      ledZustand[gelb] = blinken;
      ledZustand[rot] = aus;
      break;
    case 4:
      ledZustand[gruen] = aus;
      ledZustand[gelb] = aus;
      ledZustand[rot] = blinken;
      break;
  }
  ledAnzeige();
}

void leds_init() {
  for (int i = gruen; i <= rot; i++) {
    pinMode(ledPins[i],OUTPUT);
  }
}

int leds_version() {
  return VERS;
}
