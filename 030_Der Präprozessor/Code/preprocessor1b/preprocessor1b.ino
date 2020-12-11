/* 
  Der leichte Einstieg in Arduino & Co.
  Ein sehr einfaches Programm: Blink
  
  Version 1.00, 16.05.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

const int zeit = 1000;

void setup() {
  // Der LED-Port wird als Ausgang konfiguriert
  pinMode(13, 1);
}

void loop() {
  digitalWrite(13, 1);   // LED einschalten
  delay(zeit);           // Pause
  digitalWrite(13, 0);   // LED ausschalten
  delay(zeit);           // Pause
}
