/* 
  Der leichte Einstieg in Arduino & Co.
  Mit DEBUG - Ausgabe
  
  Version 1.00, 16.05.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

#define LED 13
#define ZEIT 1000

#define SET_OUTPUT(pin) pinMode(pin, OUTPUT)

void BLINK(int pin, int zeit) {
  digitalWrite(pin, HIGH); 
  Serial.println("ein");
  delay(zeit); 
  digitalWrite(pin, LOW); 
  Serial.println("aus");
  delay(zeit);  
}             

void setup() {
  Serial.begin(9600);
  SET_OUTPUT(LED);
}

void loop() {
  BLINK(LED, ZEIT);
}
