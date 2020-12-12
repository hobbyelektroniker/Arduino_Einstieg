/*
  Würfel mit 5 Augen
  Mit einer Funktion und einfachen Arrays
  mit zweidimensionalem Array
  
  Version 1.0
  Der Hobbyelektroniker
  Der Code ist Public Domain und kann ohne Einschränkungen frei verwendet werden
*/

// Anordnung der LED's 
/*
 * 0     1
 *    4
 * 2     3
 */
const int anzahl_augen = 5;
const int augen_pin[anzahl_augen] = {2,3,4,5,6};
const int tasterPin = 7;

// Anzeigen definieren
int anzeige[][anzahl_augen] = {
                    {0,0,0,0,0},  
                    {0,0,0,0,1},
                    {1,0,0,1,0},
                    {1,0,0,1,1},
                    {1,1,1,1,0},
                    {1,1,1,1,1}
                  };


void test() {
  // alle LED ein
  for (int i=0; i<anzahl_augen; i++) {
    digitalWrite(augen_pin[i],HIGH);
  }
  delay(2000);
  // alle LED aus
  for (int i=0; i<anzahl_augen; i++) {
    digitalWrite(augen_pin[i],LOW);
  }
}

void zeige(int zahl) {
  for (int i=0; i < anzahl_augen; i++) {
    digitalWrite(augen_pin[i],anzeige[zahl][i]);
  }
}

void setup() {
  for (int i=0; i<anzahl_augen; i++) {
    pinMode(augen_pin[i],OUTPUT);
  }
  pinMode(tasterPin,INPUT_PULLUP);
  test();
}

void loop() {
  if (!digitalRead(tasterPin)) {
    for (int i=1; i<6; i++) {
      zeige(i);
      delay(1000);
    }
    zeige(0);
  }
}