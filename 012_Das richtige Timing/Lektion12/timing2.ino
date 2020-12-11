/*
  Das richtige Timing
  So geht's !!!
  
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
const int anzahl_leds = 5;
const int ledPin[anzahl_leds] = {2,3,4,5,6};
const int tasterPin = 7;
const int blinkZeit = 500; // 0.5 s Pause gibt Sekundentakt

unsigned long startZeit = 0;


void setup() {
  // Alle Led - Pins auf OUTPUT
  for (int i=0; i<anzahl_leds; i++) {
    pinMode(ledPin[i],OUTPUT);
  }
  // INPUT_PULLUP beim Taster
  pinMode(tasterPin,INPUT_PULLUP);
}

// Die mittlere Led (4) soll im Sekundentakt blinken
// Die Led links oben (0) soll leuchten, wenn der Taster gedrückt wird

void blink() {
  // Led 4 blinken
  if (millis() > startZeit + blinkZeit) {
    digitalWrite(ledPin[4],!digitalRead(ledPin[4]));
    startZeit = millis();
  }
}

void led0() {
  // Led 0 abhängig vom Taster ein-/ausschalten
  digitalWrite(ledPin[0],!digitalRead(tasterPin));
}

void loop() {
  blink();
  led0();
}
