/* 
  Der leichte Einstieg in Arduino & Co.
  Helligkeit und Blinkfrequenz ändern
  
  Version 1.00, 06.10.2019
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

const int ledPin = 6;
const int pauseButtonPin = 9;
const int helligkeitButtonPin = 8;

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

void aenderePause() {
  pause *= 2;
  if (pause > 2000) pause = 50; 
  delay(500);
}

void aendereHelligkeit() {
  helligkeit *= 2;
  if (helligkeit > 255) helligkeit = 5;
  delay(500);
}

void setup() {
  pinMode(pauseButtonPin,INPUT_PULLUP);
  pinMode(helligkeitButtonPin,INPUT_PULLUP);
}

void loop() {
  blinkAnalog();
  if (!digitalRead(pauseButtonPin)) aenderePause();
  if (!digitalRead(helligkeitButtonPin)) aendereHelligkeit();  
}
