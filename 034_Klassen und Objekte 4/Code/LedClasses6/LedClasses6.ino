/* 
  Objektorientiert Programmierung
  Jetzt blinken auch die realen LEDs
    
  Version 1.00, 15.06.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

#include "leds.h"

// Instanzen erzeugen
LedFunktionen led1; 
DigitalLed led2(2);
AnalogLed led3(3);

void setup() {
  Serial.begin(9600);
  led1.setBlinkZeit(500); // Pause in ms
  led2.setBlinkZeit(1000);
  led3.setBlinkZeit(1500);
  led3.setHelligkeit(50);
}

void printStatus() {
  static int oldStatus = 0;
  int status = led1.getStatus(); 
  if (status != oldStatus) {
    oldStatus = status;
    Serial.println(led1.getStatusText()); 
  }
}

void loop() {
  led1.blink();
  led2.blink();
  led3.blink();
  printStatus();
}
