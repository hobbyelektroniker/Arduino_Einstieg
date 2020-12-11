/* 
  Objektorientiert Programmierung
  Eine Simulations - Klasse für eine LED
    
  Version 1.00, 06.06.2020
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
    void einschalten() {
      setStatus(eingeschaltet); 
    }

    void ausschalten() {
      setStatus(ausgeschaltet); 
    }

    void setStatus(int status) {
      _status = status;  
    }
    
    int getStatus() {
      return _status;
    }

    String getStatusText() {
      switch (_status) {
        case eingeschaltet: return "eingeschaltet"; 
                            break;
        case ausgeschaltet: return "ausgeschaltet"; 
                            break;
        default: return "";
      }
    }

    static const int eingeschaltet = -1;
    static const int ausgeschaltet = -2;

  private:
    int _status;
};

// Instanzen erzeugen
// Die Objekte led1 und led2 werden global erzeugt
// und bleiben während der ganzen Programmlaufzeit bestehen.
LedFunktionen led1; 
LedFunktionen led2; 

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
