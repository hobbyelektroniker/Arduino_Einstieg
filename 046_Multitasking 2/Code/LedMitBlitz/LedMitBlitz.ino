/* 
  Einfaches kooperatives Multitasking
  Eine blinkende und eine blitzende LED 
    
  Version 1.00, 20.03.2021
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

/*
 * Grüne Led an Pin 3
 * Rote Led an Pin 2
 */

/*
 * Pflichtenheft:
 * Eine grüne LED soll mit einer Pause von 1000 ms blinken 
 * Eine rote LED soll alle 2000 ms für 100 ms aufblitzen
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

// Aufblitzende LED 
class Blitz : public SimpleArduinoTask {
  public:
    void setup(int pin, unsigned long blinkPeriode) {
      led = pin;
      dunkelZeit = blinkPeriode - blitzZeit;
      pinMode(led,OUTPUT);
      digitalWrite(led,LOW);
    }

    void loop() {
      if (schritt == 0) {
        digitalWrite(led,HIGH); // hell
        wait(blitzZeit); 
        schritt = 1;
        return;
      }
      if (schritt == 1) {
        digitalWrite(led,LOW); // dunkel
        wait(dunkelZeit); 
        schritt = 0;
        return;
      }
    }  

  private:
    int led;
    const unsigned long blitzZeit = 100;
    unsigned long dunkelZeit;
};


// LED - Instanzen erstellen
Blink gruen;
Blitz rot;


void setup() {
  gruen.setup(3,1000);
  rot.setup(2,2000);
  gruen.start();
  rot.start();
}

void loop() {
  gruen.tic();
  rot.tic();
}
