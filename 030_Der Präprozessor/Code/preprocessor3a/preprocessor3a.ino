/* 
  Der leichte Einstieg in Arduino & Co.
  Ein Makro mit Programmcode
  
  Version 1.00, 16.05.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

#define LED 13
//const int zeit = 1000;
#define zeit 1000

#define SET_OUTPUT pinMode(LED, OUTPUT)

void setup() {
  SET_OUTPUT;
}

void loop() {
  digitalWrite(LED, HIGH);   // LED einschalten
  delay(zeit);               // Pause
  digitalWrite(LED, LOW);    // LED ausschalten
  delay(zeit);               // Pause
}
