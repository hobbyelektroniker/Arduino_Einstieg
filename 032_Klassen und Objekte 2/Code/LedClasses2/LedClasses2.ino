/* 
  Objektorientiert Programmierung
  Eine digitale Led
    
  Version 1.00, 10.06.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

#include "leds.h"

// Klasse DigitalLed
// - übernimmt die Funktionen von LedFunktionen
//   und wendet sie eine reale digitale Led an.
// - benötigt einen Anschlusspin
class DigitalLed : public LedFunktionen {
  public:
    DigitalLed(int pin) : LedFunktionen() {
      _pin = pin;
      pinMode(pin,OUTPUT);
    }

    void setStatus(int status) {
      LedFunktionen::setStatus(status);
      switch (getStatus()) {
        case eingeschaltet: digitalWrite(_pin,HIGH); 
                            break;
        case ausgeschaltet: digitalWrite(_pin,LOW); 
                            break;
      }
    }    

  private:
    int _pin;  
};

// Instanzen erzeugen
// Die Objekte led1 und led2 werden global erzeugt
// und bleiben während der ganzen Programmlaufzeit bestehen.
DigitalLed led1(2); 
DigitalLed led2(3); 

void setup() {
  Serial.begin(9600);
}

void loop() {
  led1.einschalten();
  led2.ausschalten();
  Serial.println(String("LED 1: ") + led1.getStatusText());
  Serial.println(String("LED 2: ") + led2.getStatusText());
  Serial.println();
  delay(1000);
  led1.ausschalten();
  led2.einschalten();
  Serial.println(String("LED 1: ") + led1.getStatusText());
  Serial.println(String("LED 2: ") + led2.getStatusText());
  Serial.println();
  delay(1000);
}
