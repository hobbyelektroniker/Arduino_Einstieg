/*
  Analog Output
  Helligkeitssteuerung einer LED

  
  Version 1.0
  Der Hobbyelektroniker
  Der Code ist Public Domain und kann ohne Einschränkungen frei verwendet werden

*/

const int inputPin = A0;
const int ledPin = 10;


void setup() {
  Serial.begin(9600);
  // auf pinMode() können wir bei analoger Ausgabe verzichten
}

void zeigeWert(int poti, int wert) {
  static int wertAlt = 0;
  if (wertAlt != wert) {
    Serial.print(poti);
    Serial.print(" / ");
    Serial.println(wert);
    wertAlt = wert;
  }
}

void loop() {
  int poti = analogRead(inputPin);    // Wertebereich 0 .. 1023
  int wert = poti / 4;                // Umrechnen auf Wertebereich 0 .. 255
  zeigeWert(poti,wert);
  analogWrite(ledPin,wert);          // LED wird heller, wenn Poti aufgedreht wird
}
