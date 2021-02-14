/* 
  Klasse für ein einfaches kooperatives Multitasking
    
  Version 1.00, 10.02.2021
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

class SimpleArduinoTask {
  public:

    // Task starten
    void start() {
      _delay = 0;
      _run = true;
    }

    // Task beenden
    void stop() {
      _run = false;
    }

    // Ist der Task aktiv?
    bool isRunning() {
      return (_run);
    }

    // Nicht blockierendes delay()
    void delay(unsigned long ms) {
      _startTime = millis();
      _delay = ms;
    }

    // Das muss regelmässig aufgerufen werden
    void tic() {
      if (_delay) {
        if ((unsigned long)millis() - _startTime < _delay) return;
        _delay = 0;
      }
      loop();
    }

    // In einer abgeleiteten Klasse wird hier die Funktionalität implementiert
    virtual void loop() {
      stop();
    }
   
  private:
    bool _run = false;
    unsigned long _delay, _startTime; 

};
