/* 
  Der leichte Einstieg in Arduino & Co.
  mehrere Dateien
  
  Version 1.00, 16.05.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

const int zeit = 1000;

void blink() {
  digitalWrite(13, 1);   
  delay(zeit);               
  digitalWrite(13, 0);    
  delay(zeit);               
}

void setup() {
  pinMode(13, 1);
}

void loop() {
  blink();
}
