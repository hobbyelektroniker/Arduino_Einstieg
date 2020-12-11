/* 
  Der leichte Einstieg in Arduino & Co.
  Auch Parameter sind möglich
  
  Version 1.00, 16.05.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

#define LED 13
#define ZEIT 1000

#define SET_OUTPUT(pin) pinMode(pin, OUTPUT)

#define BLINK(pin, zeit) \
  digitalWrite(pin, HIGH); \
  delay(zeit); \
  digitalWrite(pin, LOW); \
  delay(zeit)            

void setup() {
  SET_OUTPUT(LED);
  SET_OUTPUT(10);
  SET_OUTPUT(11);
  SET_OUTPUT(12);
  SET_OUTPUT(9);
}

void loop() {
  BLINK(LED, ZEIT);
  BLINK(10,500);
  BLINK(11,500);
  BLINK(12,500);
  BLINK(9,500);
}
