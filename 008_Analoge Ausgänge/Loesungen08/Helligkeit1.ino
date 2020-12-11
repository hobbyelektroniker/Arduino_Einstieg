/*
  Analog Output
  Helligkeitssteuerung zweier LED's
  Lösung 1 (Software)
  
  Version 1.0
  Der Hobbyelektroniker
  Der Code ist Public Domain und kann ohne Einschränkungen frei verwendet werden

*/

const int inputPin = A0;
const int led1Pin = 10;
const int led2Pin = 9;

void setup() {
  // auf pinMode() können wir bei analoger Ausgabe verzichten
}

void loop() {
  int poti = analogRead(inputPin);    // Wertebereich 0 .. 1023
  int wert = poti / 4;                // Umrechnen auf Wertebereich 0 .. 255
  analogWrite(led1Pin,wert);          // LED wird heller, wenn Poti aufgedreht wird
  analogWrite(led2Pin,255-wert);      // LED wird dunkler, wenn Poti aufgedreht wird
}
