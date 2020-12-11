/* 
  Objektorientierte Programmierung
  Langsamer Servo
  - Ableitung von 'Servo' und Aufteilung in .h und .cpp
    
  Version 1.00, 30.08.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

#include "MySlowServo.h"

const int servo_pin = 7;

LangsamerServo servo;

void setup() {
  Serial.begin(115200);
  servo.attach(servo_pin);
  servo.write(90);
}

// Das soll anstelle von delay() verwendet werden
void pause(int ms) {
  unsigned long start = millis();
  while (millis() < start + ms) {
    _loop();
  }
}

// in diesen Loop kommt alles, was regelmässig aufgerufen werden muss
void _loop() {
  servo.tic();
}

void loop() {
  _loop();
  servo.write(20,10);
  pause(2000);
  servo.write(150,100);
  pause(5000);
} 
