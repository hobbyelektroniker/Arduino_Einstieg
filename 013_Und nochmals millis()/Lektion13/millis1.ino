/*
  Spielereien mit millis()

  
  Version 1.0
  Der Hobbyelektroniker
  Der Code ist Public Domain und kann ohne Einschränkungen frei verwendet werden
*/

// Anordnung der LED's 
/*
 * 1     2
 *    0
 * 4     3
 */
const int anzahl_leds = 5;
const int ledPin[anzahl_leds] = {6,2,3,5,4};
const int tasterPin = 7;

// mögliche Zustände
const int aus = 0;
const int ein = 1;
const int blinken = 2;

// aktuelle Zustände
int ledStatus[anzahl_leds];
String statusText[] = {"aus","ein","blinken"};

unsigned long startZeit;
unsigned long tic;

void start() {
  ledStatus[0] = blinken;  // Led 0 blinkt immer
  for (int i=1; i<anzahl_leds; i++) ledStatus[i] = aus; // alle Anderen aus
  startZeit = millis();
}

void setup() {
  Serial.begin(9600);
  for (int i=0; i<anzahl_leds; i++) pinMode(ledPin[i],OUTPUT);
  pinMode(tasterPin,INPUT_PULLUP);  // INPUT_PULLUP beim Taster
  while (digitalRead(tasterPin));
  start();
}

void checkStart() {
  if (!digitalRead(tasterPin)) start();
}

void checkZustand() {
  static int sekundeAlt = 0;
  int sekunde = (tic-startZeit) / 1000; // Sekunden seit Start
  sekunde = sekunde % 60; // 0..59
  if (sekunde != sekundeAlt) {
    Serial.println(); Serial.print("Sekunde "); Serial.println(sekunde);
    sekundeAlt = sekunde;
  }
      
}

void schalteLeds() {
  
}

void loop() {
  checkStart();
  tic = millis(); // Der Zeittakt in Millisekunden
  checkZustand();
  schalteLeds();
}
