/*
  Analog Input
  Alarmanlage Stufe 3
  
  Version 1.0
  Der Hobbyelektroniker
  Der Code ist Public Domain und kann ohne Einschränkungen frei verwendet werden

*/

const int inputPin = A0;
const int ledPin = 7;

int alarmzustand; // <3 = kein Alarm, 3 = Alarm

void setup() {
  pinMode(ledPin,OUTPUT);

  // Grundzustand
  alarmzustand = 0;          // Am Anfang haben wir keinen Alarm
}

void alarmTest() {
  if (alarmzustand != 3) {
    if (analogRead(inputPin) > 600) {
      alarmzustand = alarmzustand + 1;
    } else {
      alarmzustand = 0;
    }
    delay(1000);  // der nächste Test soll erst nach 5 Sekunden gemacht werden
  }
}

void alarm() {
  if (alarmzustand == 3) {   // wir haben einen Alarmzustand! 
    digitalWrite(ledPin,HIGH);
    delay(500); 
    digitalWrite(ledPin,LOW);
    delay(500);
  } else {                   // nein, alles ruhig
    digitalWrite(ledPin,LOW);
  }  
}

void loop() {
  alarmTest();
  alarm();
}
