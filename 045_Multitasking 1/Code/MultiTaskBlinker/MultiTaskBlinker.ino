/* 
  Kooperatives Multitasking
  LED - Blinker
   
  Version 1.00, 13.02.2021
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

#include "SimpleArduinoTask.h"

// Klasse für eine blinkende LED
class Blink : public SimpleArduinoTask {
  public:
    void setup(int pin, unsigned long pause) {
      _pin = pin;
      _pause = pause;
      pinMode(_pin,OUTPUT);
      digitalWrite(_pin,LOW);
    }

    void loop() {
      digitalWrite(_pin,!digitalRead(_pin));
      delay(_pause);
    }  

  private:
    int _pin;
    unsigned long _pause;
};


// LED - Instanzen erstellen
const int anzahl = 12;
Blink blink[anzahl];


void setup() {
  for (int i=0; i<anzahl; i++) {
    blink[i].setup(i+2,(i+1)*200);
    blink[i].start();
  }
}

void loop() {
  for (int i=0; i<anzahl; i++) blink[i].tic();
}
