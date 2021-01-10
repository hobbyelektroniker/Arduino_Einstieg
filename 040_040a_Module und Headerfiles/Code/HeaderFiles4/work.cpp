#include "work.h"
#include <arduino.h>
#include "globals.h"

// Definitionen
void rechneTotal() {
  total = 0;
  for (int i=1; i<= anzahl; i++) total += i;
}

void doIt(int anz) { // Das ist die Definition
  if (anz) anzahl = anz;
  Serial.print(String("Anzahl: ") + anzahl);
  rechneTotal();
  Serial.println(String(", Total: ") + total);  
}
