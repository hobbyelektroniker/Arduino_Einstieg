/*
  Skala anbringen
  
  Version 1.0
  Der Hobbyelektroniker
  Der Code ist Public Domain und kann ohne Einschränkungen frei verwendet werden
*/

#include <Servo.h>  // Hinzufügen der Library

Servo servo;  // Erzeugen eines Servo-Objekts

const int servoPin = 8;  // Es funktionieren auch Pins ohne PWM
const int potiPin = A0;  // Analoger Pin mit Potentiometer


void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);  // Der Servo ist an Pin 8 angeschlossen
}

void servoTest() {
  // Ansteuern des Servos
  int gelesen = analogRead(potiPin);

  // Der Bereich wird etwas eingeschränkt, damit der Servo nirgends mechanisch anschlägt
  int grad = map(gelesen,0,1023,170,10); // Drehrichtung korrigiert 

  
  servo.write(grad); // Der Servo fährt die Position an

  // Das ist nur notwendig, wenn man etwas auf den seriellen Monitor ausgeben will
  static int gradAlt = -1;
  if (grad != gradAlt) {
    Serial.println(grad);
    gradAlt = grad;
  }
}

void loop() {
  servoTest();
  delay(15);   // dem Servo Zeit lassen, um die Position anzufahren                        
}
