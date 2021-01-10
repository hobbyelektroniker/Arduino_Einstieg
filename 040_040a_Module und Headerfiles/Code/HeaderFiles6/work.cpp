#include "work.h"
#include <arduino.h>
#include "globals.h"

// Definitionen von Funktionen
void doIt(int anz) { // Das ist die Definition
  if (anz) anzahl = anz;
  Serial.print(String("Anzahl: ") + anzahl);
  total = rechneTotal.total(anzahl);
  Serial.println(String(", Total: ") + total);  
}
