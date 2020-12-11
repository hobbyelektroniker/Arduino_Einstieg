/* 
  Der leichte Einstieg in Arduino & Co.
  Blinken mit Helligkeitssteuerung
  
  Version 1.00, 06.10.2019
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

const int ledPin = 6;

int helligkeit = 64;
int pause = 1000;

void blinkAnalog() {
  static unsigned long start = 0;
  static boolean isOn = false;
  if (start+pause < millis()) {
    start = millis();
    isOn = !isOn;
    if (isOn) {
      analogWrite(ledPin,helligkeit);
    } else {
      analogWrite(ledPin,0);
    }
  }
}

void setup() {

}

void loop() {
  blinkAnalog();
}
