/* 
  Objektorientiert Programmierung
  - Diverse Led - Klassen
  - Jetzt mit Instanzzähler
    
  Version 1.30, 14.06.2020
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
    LedFunktionen() { // Konstruktor
      _anzahl++;
    }

    ~LedFunktionen() { // Destruktor
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

    static int getAnzahl() {
      return _anzahl;
    }

    static const int eingeschaltet = -1;
    static const int ausgeschaltet = -2;
    
  private:
    int _status;
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
