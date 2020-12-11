/* 
  Objektorientiert Programmierung
  - Diverse Led - Klassen
  - Jetzt mit Instanzzähler
    
  Version 1.20, 15.06.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

// Klasse LedFunktionen
// - kann ein- und ausgeschaltet werden
// - der Zustand kann abgefragt werden
class LedFunktionen {
  public:
    LedFunktionen() { 
      _anzahl++;
    }

    ~LedFunktionen() { 
      _anzahl--;
    }

    void einschalten() {
      setStatus(eingeschaltet); 
    }

    void ausschalten() {
      setStatus(ausgeschaltet); 
    }

    virtual void setStatus(int status) {
      _status = status;  
    }
    
    int getStatus() {
      return _status;
    }

    virtual String getStatusText() {
      switch (_status) {
        case eingeschaltet: return "eingeschaltet"; 
                            break;
        case ausgeschaltet: return "ausgeschaltet"; 
                            break;
        default: return "";
      }
    }

    void setBlinkZeit(int zeit) {
      _blinkZeit = zeit;
    }

    void blink() {
      if (millis() > _oldTime + _blinkZeit) {
        _oldTime = millis();
        if (_status == eingeschaltet) {
          ausschalten();
        } else {
          einschalten();
        }
      }
    }

    static int getAnzahl() {
      return _anzahl;
    }

    static const int eingeschaltet = -1;
    static const int ausgeschaltet = -2;
    
  private:
    int _status;
    int _blinkZeit;
    unsigned long _oldTime = 0;
    static int _anzahl;
};
int LedFunktionen::_anzahl = 0;

// Klasse DigitalLed
// - übernimmt die Funktionen von LedFunktionen
//   und wendet sie eine reale digitale Led an.
// - benötigt einen Anschlusspin
class DigitalLed : public LedFunktionen {
  public:
    DigitalLed(int pin) : LedFunktionen() {
      _pin = pin;
      pinMode(pin,OUTPUT);
      _anzahl++;
    }

    ~DigitalLed() {
      _anzahl--;
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

    static int getAnzahl() {
      return _anzahl;
    }

  private:
    int _pin;  
    static int _anzahl;
};
int DigitalLed::_anzahl = 0;

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
