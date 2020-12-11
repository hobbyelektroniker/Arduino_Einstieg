/*
  Ansteuerung eines Servos
  ohne Verwendung einer Bibliothek
  
  Version 1.0
  Der Hobbyelektroniker
  Der Code ist Public Domain und kann ohne Einschränkungen frei verwendet werden
*/

const int servoPin = 8;
const int minPulse = 500; // in Mikrosekunden
const int maxPulse = 2500; // in Mikrosekunden
const int periode = 20; // in ms

int actPulse;

void setServoPosition() {
  static int old = 0;
  if (actPulse != old) {
    Serial.println(actPulse);
    old = actPulse;
  }
    digitalWrite(servoPin,HIGH);
    delayMicroseconds(actPulse);
    digitalWrite(servoPin,LOW);
    delay(periode);
}

void setPos(int winkel) { // 0 .. 180 Grad
  actPulse = map(winkel,0,180,maxPulse,minPulse);  // Drehrichtung korrigiert
}

void setup() {
  Serial.begin(9600);
  pinMode(servoPin,OUTPUT);
  setPos(90);
}

void loop() {
  setServoPosition();
}
