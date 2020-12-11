/* 
  Der leichte Einstieg in Arduino & Co.
  Mit DEBUG - Ausgabe und Makro
  
  Version 1.00, 16.05.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

#define DEBUG
#define LED 13
#define ZEIT 1000

#define SET_OUTPUT(pin) pinMode(pin, OUTPUT)

void BLINK(int pin, int zeit) {
  digitalWrite(pin, HIGH); 
  #ifdef DEBUG
    Serial.println("ein");
  #endif  
  delay(zeit); 
  digitalWrite(pin, LOW); 
  #ifdef DEBUG
    Serial.println("aus");
  #endif
  delay(zeit);  
}             

void setup() {
  #ifdef DEBUG
    Serial.begin(9600);
  #endif  
  SET_OUTPUT(LED);
}

void loop() {
  BLINK(LED, ZEIT);
}
