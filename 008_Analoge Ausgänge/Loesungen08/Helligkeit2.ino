/*
  Analog Output
  Helligkeitssteuerung zweier LED's
  Lösung 2 (Hardware)
  
  Version 1.0
  Der Hobbyelektroniker
  Der Code ist Public Domain und kann ohne Einschränkungen frei verwendet werden

*/

const int inputPin = A0;
const int ledPin = 10;


void setup() {
  // auf pinMode() können wir bei analoger Ausgabe verzichten
}

void loop() {
  int poti = analogRead(inputPin);    // Wertebereich 0 .. 1023
  int wert = poti / 4;                // Umrechnen auf Wertebereich 0 .. 255
  analogWrite(ledPin,wert);           // beide LED's erhalten die korrekte Helligkeit
}
