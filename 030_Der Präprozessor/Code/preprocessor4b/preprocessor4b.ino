/* 
  Der leichte Einstieg in Arduino & Co.
  Auch Parameter sind möglich
  
  Version 1.00, 16.05.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

void setup() {
  pinMode(13, 1);
  pinMode(10, 1);
}

void loop() {
// BLINK(LED, ZEIT)
  digitalWrite(13, 1);
  delay(1000); 
  digitalWrite(13, 0);
  delay(1000);               

// BLINK(10,500)
  digitalWrite(10, 1);
  delay(500); 
  digitalWrite(10, 0);
  delay(500);               
}
