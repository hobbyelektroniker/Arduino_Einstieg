/* 
  Der leichte Einstieg in Arduino & Co.
  Komfortable DEBUG - Ausgabe
  
  Version 1.00, 16.05.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

#define DEBUG 115200
#define LED 13
#define ZEIT 1000

#define SET_OUTPUT(pin) pinMode(pin, OUTPUT)

#ifdef DEBUG
  #define SERIAL_PRINT(text) Serial.println(text)
#else
  #define SERIAL_PRINT(text) 
#endif

void BLINK(int pin, int zeit) {
  digitalWrite(pin, HIGH); 
  SERIAL_PRINT("ein");
  delay(zeit); 
  SERIAL_PRINT(zeit);
  digitalWrite(pin, LOW); 
  SERIAL_PRINT("aus");
  delay(zeit);  
}             

void setup() {
  #ifdef DEBUG
    Serial.begin(DEBUG);
    #if DEBUG > 100000
      SERIAL_PRINT(String(DEBUG) + " Baud ist schnell!");
    #endif  
  #endif  
  SET_OUTPUT(LED);
  
}

void loop() {
  BLINK(LED, ZEIT);
}
