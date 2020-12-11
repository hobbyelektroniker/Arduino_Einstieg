/* 
  Der leichte Einstieg in Arduino & Co.
  Rechteckgeneratur
  Es solll eine Frequenz von ungefähr 100 kHz ausgeegeben werden
  
  Version 1.00, 30.11.2019
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

const int outPin = 8;

// Pin D8
#define outPort PORTB
#define outBit 0

#define bitToggle(port, bitNum) port = port ^ 1 << bitNum

void setup() {
  pinMode(outPin,OUTPUT);
  digitalWrite(outPin,LOW);
}

void loop() {
  bitToggle(outPort, outBit);
  delayMicroseconds(5);
}
