/*
  Lauflicht mit FOR-Schleife
  Lösung 1 der Übungsaufgabe
  
  Version 1.0
  Der Hobbyelektroniker
  Der Code ist Public Domain und kann ohne Einschränkungen frei verwendet werden

*/

const int ledPin = 5;
const int potiPin = A0;
const int anzahlLeds = 6;

void setup() {
  for (int i = 0; i < anzahlLeds; i++) {
    pinMode(ledPin+i,OUTPUT); // Es werden 6 Ausgänge benötigt
  }
}

int geschwindigkeit() {
  // Das Poti wird gelesen und der Wert umgerechnet
  int p = analogRead(potiPin);
  return map(p,0,1023,500,5);  
}

void loop() {
  
  // wir gehen nach oben
  for (int i=ledPin; i<ledPin+anzahlLeds; i++) {  // von Pin 5 bis Pin 10
    digitalWrite(i,HIGH);         // LED ein
    if (i > ledPin) {
      digitalWrite(i-1,LOW);      // vorherige aus
    } else {  
      digitalWrite(ledPin+1,LOW); // Beim Einschalten der untersten LED
                                  // muss die zweitunterste ausgeschaltet werden
    }
    delay(geschwindigkeit());
  }

  // wir gehen nach unten
  for (int i=ledPin+anzahlLeds-2; i>ledPin; i--) {  // Pin 9 bis Pin 6
    digitalWrite(i,HIGH);
    digitalWrite(i+1,LOW);
    delay(geschwindigkeit());
  }
  
}
