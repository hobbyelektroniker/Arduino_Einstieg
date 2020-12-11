/* 
  Der leichte Einstieg in Arduino & Co.
  Speichern der Blinkfrequenz
  
  Version 1.00, 06.10.2019
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

#include <EEPROM.h>

const int eeprom_signatur = 23379;
const int eeprom_version = 1;

const int ledPin = 6;
const int pauseButtonPin = 9;
const int helligkeitButtonPin = 8;

int helligkeit = 64;
int pause = 1000;

void eeprom_speichern() {
  int adresse = 0;
  EEPROM.put(adresse,eeprom_signatur);
  adresse += sizeof(eeprom_signatur);
  EEPROM.put(adresse,eeprom_version);
  adresse += sizeof(eeprom_version);
  EEPROM.put(adresse,pause);
  adresse += sizeof(pause);
}

void eeprom_laden() {
  int signatur;
  int version = 0;
  int adresse = 0;
  EEPROM.get(adresse,signatur);
  adresse += sizeof(signatur);
  if (signatur != eeprom_signatur) return;
  EEPROM.get(adresse,version);
  adresse += sizeof(version);
  EEPROM.get(adresse,pause);
  adresse += sizeof(pause);
}

void blinkAnalog() {
  static unsigned long start = 0;
  static boolean isOn = false;
  if (start+pause < millis()) {
    start = millis();
    isOn = !isOn;
    if (isOn) {
      analogWrite(ledPin,helligkeit);
    } else {
      analogWrite(ledPin,0);
    }
  }
}

void aenderePause() {
  pause *= 2;
  if (pause > 2000) pause = 50; 
  delay(500);
  eeprom_speichern();
}

void aendereHelligkeit() {
  helligkeit *= 2;
  if (helligkeit > 255) helligkeit = 5;
  delay(500);
}

void setup() {
  pinMode(pauseButtonPin,INPUT_PULLUP);
  pinMode(helligkeitButtonPin,INPUT_PULLUP);
  eeprom_laden();
}

void loop() {
  blinkAnalog();
  if (!digitalRead(pauseButtonPin)) aenderePause();
  if (!digitalRead(helligkeitButtonPin)) aendereHelligkeit();  
}
