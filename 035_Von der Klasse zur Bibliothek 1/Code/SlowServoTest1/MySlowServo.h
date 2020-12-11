/* 
  Objektorientiert Programmierung
  Klasse LangsamerServo
    
  Version 1.00, 30.08.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

#ifndef MYSLOWSERVO_H
#define MYSLOWSERVO_H

#include <arduino.h>
#include <Servo.h>

class LangsamerServo : public Servo {
  public:
    LangsamerServo(); // Constructor

    // Positionieren auf einen bestimmten Winkel
    void write(int grad);             // mit maximaler Geschwindigkeit
    void write(int grad, int bremse); // langsames Positionieren (ms Pause pro Grad)
    
    void tic(); // muss regelmässig aufgerufen werden
    
  private:
    const int _undefiniert = -999;
    int _bremse;
    int _ziel;
    unsigned long _start_zeit;
};

#endif
