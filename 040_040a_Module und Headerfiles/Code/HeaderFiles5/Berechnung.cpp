#include "Berechnung.h"

// Definition einer Klasse
RechneTotal::RechneTotal(int multiplikator) {
  _multiplikator = multiplikator;
};

int RechneTotal::total(int anzahl) {
  int result = 0;
  for (int i=1; i<= anzahl; i++) result += i;
  return result * _multiplikator;
}

int RechneTotal::getMultiplikator() {
  return _multiplikator;
}
