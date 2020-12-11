/* 
  Objektorientiert Programmierung
  Eine analoge Led
    
  Version 1.00, 14.06.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

#include "leds.h"

// Klasse AnalogLed
// - übernimmt die Funktionen von LedFunktionen
//   und wendet sie eine reale analoge Led an.
// - benötigt einen Anschlusspin
// - die Helligkeit kann gesetzt werden
class AnalogLed : public LedFunktionen {
  public:
    AnalogLed(int pin) : LedFunktionen() {
      _pin = pin;
      _helligkeit = 255; // maximale Helligkeit
    }

    void setHelligkeit(int helligkeit) {
      _helligkeit = constrain(helligkeit,0,255);
      setStatus(getStatus());
    }

    int getHelligkeit() {
      return _helligkeit;
    }

    void setStatus(int status) {
      LedFunktionen::setStatus(status);
      switch (getStatus()) {
        case eingeschaltet: analogWrite(_pin,_helligkeit);  
                            break;
        case ausgeschaltet: analogWrite(_pin,0); // dunkel = ausgeschaltet
                            break;
      }
    }    

    String getStatusText() {
      return  LedFunktionen::getStatusText() + ", Helligkeit: " + _helligkeit;
    }    

  private:
    int _pin;
    int _helligkeit; // PWM-Wert 0 .. 255  
};

// Instanzen erzeugen
// Die Objekte led1 und led2 werden global erzeugt
// und bleiben während der ganzen Programmlaufzeit bestehen.
AnalogLed led1(3); 
AnalogLed led2(4); 

void setup() {
  Serial.begin(9600);
  led1.setHelligkeit(50);
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
