/* 
  Objektorientiert Programmierung
  - Eine Simulations - Klasse
    
  Version 1.10, 10.06.2020
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
    LedFunktionen() { // Standardkonstruktor, kann weggelassen werden
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

//  protected:  // besser Wert über Getter zur Verfügung stellen
//    int _status;

  private:
    int _status;
};
