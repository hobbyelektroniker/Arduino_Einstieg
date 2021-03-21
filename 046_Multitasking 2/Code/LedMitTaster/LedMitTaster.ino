/* 
  Einfaches kooperatives Multitasking
  Zwei LEDs und ein Taster

  Version 1.00, 20.03.2021    
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

/*
 * Grüne Led an Pin 3
 * Rote Led an Pin 2
 * Taster an Pin 6, gegen GND geschaltet
 */

/*
 * Pflichtenheft
 * Eine grüne LED soll mit einer Pause von 1000 ms blinken
 * Eine rote LED soll:
 * - Auf einen Tastendruck warten
 * - 6 Mal normal (pause = 500 ms) blinken
 * - 3 Mal langsam (doppelte Pause) blinken
 * - Wieder auf Taster warten
 */

#include "SimpleArduinoTask.h"

// Einfache Blinkklasse
class Blink : public SimpleArduinoTask {
  public:
    void setup(int pin, unsigned long pausenZeit) {
      led = pin;
      pause = pausenZeit;
      pinMode(led,OUTPUT);
      digitalWrite(led,LOW);
    }

    void loop() {
      digitalWrite(led,!digitalRead(led));
      wait(pause);
    }  

  private:
    int led;
    unsigned long pause;
};

// Blinkende LED mit Taster 
class BlinkTaster : public SimpleArduinoTask {
  public:
    void setup(int ledPin, int tasterPin,  unsigned long pausenZeit) {
      led = ledPin;
      taster = tasterPin;
      pause = pausenZeit;
      pinMode(led,OUTPUT);
      pinMode(taster,INPUT_PULLUP);
      digitalWrite(led,LOW);
    }

    void loop() {
      if (schritt == 0) { // warten auf Taster
        if (!digitalRead(taster)) { 
          // Taster wurde gedrückt, zu Schritt 1 
          zaehler = 0;
          schritt = 1;
        }
        return;
      }
      if (schritt == 1) { // 6 Mal normal blinken
        digitalWrite(led,!digitalRead(led));
        wait(pause);
        zaehler++;
        if (zaehler == 2*6) { // erledigt
          zaehler = 0;        
          schritt = 2;
        }
        return;
      }
      if (schritt == 2) { // 3 Mal langsam blinken
        digitalWrite(led,!digitalRead(led));
        wait(2*pause);
        zaehler++;
        if (zaehler == 2*3) { // erledigt
          schritt = 0;
        }
        return;
      }      
    }  

  private:
    int led, taster;
    int zaehler;
    unsigned long pause;
};


// LED - Instanzen erstellen
Blink gruen;
BlinkTaster rot;


void setup() {
  gruen.setup(3,1000);
  rot.setup(2,6,500);
  gruen.start();
  rot.start();
}

void loop() {
  gruen.tic();
  rot.tic();
}
