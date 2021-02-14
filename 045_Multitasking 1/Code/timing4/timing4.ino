/*
  Das richtige Timing (Lektion 12)
  Mit drei blinkenden Leds
  
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

void setup() {
  // Alle Led - Pins auf OUTPUT
  for (int i=0; i<anzahl_leds; i++) {
    pinMode(ledPin[i],OUTPUT);
  }
  // INPUT_PULLUP beim Taster
  pinMode(tasterPin,INPUT_PULLUP);
}

// Die Leds 1, 3 und 4 sollen blinken
// Die Led links oben (0) soll leuchten, wenn der Taster gedrückt wird

void blink4() {
  const int ledNummer = 4;
  const int blinkZeit = 500;
  static unsigned long startZeit = 0; 
  if (millis() > startZeit + blinkZeit) {
    digitalWrite(ledPin[ledNummer],!digitalRead(ledPin[ledNummer]));
    startZeit = millis();
  }
}

void blink3() {
  const int ledNummer = 3;
  const int blinkZeit = 700;
  static unsigned long startZeit = 0; 
  if (millis() > startZeit + blinkZeit) {
    digitalWrite(ledPin[ledNummer],!digitalRead(ledPin[ledNummer]));
    startZeit = millis();
  }
}

void blink1() {
  const int ledNummer = 1;
  const int blinkZeit = 1000;
  static unsigned long startZeit = 0; 
  if (millis() > startZeit + blinkZeit) {
    digitalWrite(ledPin[ledNummer],!digitalRead(ledPin[ledNummer]));
    startZeit = millis();
  }
}

void led0() {
  // Led 0 abhängig vom Taster ein-/ausschalten
  digitalWrite(ledPin[0],!digitalRead(tasterPin));
}

void loop() {
  blink4();
  blink1();
  blink3();
  led0();
}
