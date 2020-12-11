/*
  Würfel mit 5 Augen
  Mit einzelnen Funktionen
  
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

void aus() {
  for (int i=0; i<anzahl_augen; i++) {
    digitalWrite(augen_pin[i],LOW);
  }  
}

void eins() {
  aus();
  digitalWrite(augen_pin[4],HIGH);
}

void zwei() {
  aus();
  digitalWrite(augen_pin[0],HIGH);
  digitalWrite(augen_pin[3],HIGH);
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
    eins();
    delay(2000);
    zwei();
    delay(2000);
    aus();
  }
}
