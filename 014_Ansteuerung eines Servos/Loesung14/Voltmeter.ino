/*
  Ein Arduino-Voltmeter mit Zeiger
  
  Version 1.0
  Der Hobbyelektroniker
  Der Code ist Public Domain und kann ohne Einschränkungen frei verwendet werden
*/

#include <Servo.h>

Servo servo;  // Erzeugen eines Servo-Objekts

const int servoPin = 8;
const int potiPin = A0;  // Analoger Pin mit Potentiometer


void setup() {
  servo.attach(servoPin);  // Der Servo ist an Pin 8 angeschlossen
}

void messen() {
  int gelesen = analogRead(potiPin);
  int grad = map(gelesen,0,1023,170,10); 
  servo.write(grad);
}

void loop() {
  messen();
  delay(15);   // dem Servo Zeit lassen, um die Position anzufahren                        
}
