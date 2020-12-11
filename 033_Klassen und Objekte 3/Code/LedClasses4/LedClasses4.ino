/* 
  Objektorientiert Programmierung
  Instanzzähler
    
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
      _anzahl++;
    }

    ~AnalogLed() {
      _anzahl--;
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

    static int getAnzahl() {
      return _anzahl;
    }      

  private:
    int _pin;
    int _helligkeit; // PWM-Wert 0 .. 255  
    static int _anzahl;
};
int AnalogLed::_anzahl = 0;

// Instanzen erzeugen
// Die Objekte led1, led2 und led3 werden global erzeugt
// und bleiben während der ganzen Programmlaufzeit bestehen.
AnalogLed led1(3); 
DigitalLed led2(4);
LedFunktionen led3; 

void printInfo(String txt) {
  Serial.println();
  Serial.println("----------------");
  Serial.println(txt);
  Serial.println(String("LedFunktionen: ") + LedFunktionen::getAnzahl());
  Serial.println(String("DigitalLed: ") + DigitalLed::getAnzahl());
  Serial.println(String("AnalogLed: ") + AnalogLed::getAnzahl());
}

void test() {
  printInfo("Start von test()");
  AnalogLed led4(5); 
  DigitalLed led5(6);
  LedFunktionen led6;   
  printInfo("Ende von test()");
}

void setup() {
  Serial.begin(9600);
  printInfo("Vor Aufruf von test()");
  test();
  printInfo("Nach Beenden von test()");
}


void loop() {
}
