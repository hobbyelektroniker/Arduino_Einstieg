/* 
  Der leichte Einstieg in Arduino & Co.
  Ein sehr einfaches Programm: Blink
  
  Version 1.00, 16.05.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

#define LED 13
const int zeit = 1000;

void setup() {
  // Der LED-Port wird als Ausgang konfiguriert
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);   // LED einschalten
  delay(zeit);               // Pause
  digitalWrite(LED, LOW);    // LED ausschalten
  delay(zeit);               // Pause
}
