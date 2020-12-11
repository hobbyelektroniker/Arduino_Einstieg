
#include <myslowservo.h>

LangsamerServo::LangsamerServo() : Servo() {
  _ziel = _undefiniert;
  _start_zeit = 0;
}

void LangsamerServo::write(int grad) {
  _ziel = _undefiniert;
  Servo::write(grad);
}
  
void LangsamerServo::write(int grad, int bremse) {
  _ziel = grad;
  _bremse = bremse;
  _start_zeit = 0;
  tic();
}

bool LangsamerServo::amZiel() {
  return (_ziel == _undefiniert);
}

void LangsamerServo::tic() {
  int pos = read();
  if (_ziel == pos) _ziel = _undefiniert;
  if (_ziel != _undefiniert && millis() > _start_zeit + _bremse) {
    _start_zeit = millis();
    if (_ziel > pos) {
      Servo::write(pos+1);
    } else {
      Servo::write(pos-1);
    }
  }
  
}
