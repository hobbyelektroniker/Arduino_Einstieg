/* 
  Der leichte Einstieg in Arduino & Co.
  Ein Makro mit Programmcode
  
  Version 1.00, 16.05.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

void setup() {
  pinMode(13, 1);
}

void loop() {
  digitalWrite(13, 1);   // LED einschalten
  delay(1000);           // Pause
  digitalWrite(13, 0);   // LED ausschalten
  delay(1000);           // Pause
}
