/*
  Analog Input
  Alarmanlage Stufe 1
  
  Version 1.0
  Der Hobbyelektroniker
  Der Code ist Public Domain und kann ohne Einschränkungen frei verwendet werden

*/

const int inputPin = A0;
const int ledPin = 7;

int alarmzustand; //0 = kein Alarm, 1 = Alarm

void setup() {
  pinMode(ledPin,OUTPUT);

  // Grundzustand
  alarmzustand = 0;          // Am Anfang haben wir keinen Alarm
}

void alarmTest() {
  if (analogRead(inputPin) > 600) alarmzustand = 1;
}

void alarm() {
  if (alarmzustand == 1) {   // wir haben einen Alarmzustand!  
    digitalWrite(ledPin,HIGH);
  } else {                   // nein, alles ruhig
    digitalWrite(ledPin,LOW);
  }  
}

void loop() {
  alarmTest();
  alarm();
}
