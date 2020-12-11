/*
  Das richtige Timing
  Mit zwei blinkenden Leds
  
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
const int blinkZeit4 = 500; // 0.5 s Pause gibt Sekundentakt
const int blinkZeit3 = 700;

unsigned long startZeit4 = 0;
unsigned long startZeit3 = 0;


void setup() {
  // Alle Led - Pins auf OUTPUT
  for (int i=0; i<anzahl_leds; i++) {
    pinMode(ledPin[i],OUTPUT);
  }
  // INPUT_PULLUP beim Taster
  pinMode(tasterPin,INPUT_PULLUP);
}

// Die Leds 3 und 4 sollen blinken
// Die Led links oben (0) soll leuchten, wenn der Taster gedrückt wird

void blink4() {
  // Led 4 blinken
  if (millis() > startZeit4 + blinkZeit4) {
    digitalWrite(ledPin[4],!digitalRead(ledPin[4]));
    startZeit4 = millis();
  }
}

void blink3() {
  // Led 3 blinken
  if (millis() > startZeit3 + blinkZeit3) {
    digitalWrite(ledPin[3],!digitalRead(ledPin[3]));
    startZeit3 = millis();
  }
}

void led0() {
  // Led 0 abhängig vom Taster ein-/ausschalten
  digitalWrite(ledPin[0],!digitalRead(tasterPin));
}

void loop() {
  blink4();
  blink3();
  led0();
}
