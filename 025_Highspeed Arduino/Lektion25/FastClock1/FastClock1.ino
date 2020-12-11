/* 
  Der leichte Einstieg in Arduino & Co.
  Rechteckgeneratur
  Es solll eine Frequenz von ungefähr 10 kHz ausgeegeben werden
  
  Version 1.00, 30.11.2019
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

const int outPin = 8;

void setup() {
  pinMode(outPin,OUTPUT);
}

void loop() {
  digitalWrite(outPin,!digitalRead(outPin));
  delayMicroseconds(50);
}
