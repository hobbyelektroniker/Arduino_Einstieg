/*
  Würfel mit 5 Augen
  mit Zufall und Statistik
  Lösung der Übungsaufgabe
  
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

int statistikArray[] = {0,0,0,0,0,0};  // Werte für 'aus',1,2,3,4,5

// Anzeigen definieren
int anzeige[][anzahl_augen] = {
                    {0,0,0,0,0},  // aus
                    {0,0,0,0,1},  // 1
                    {1,0,0,1,0},  // 2
                    {1,0,0,1,1},  // 3
                    {1,1,1,1,0},  // 4
                    {1,1,1,1,1}   // 5
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

void wuerfeln() {
  // Zum Start alles aus
  zeige(0);
  delay(500);
  for (int i=0; i<30;i++) {
    zeige(random(1,6)); 
    delay(100);
  }
  delay(500);
}

void setup() {
  Serial.begin(9600);
  for (int i=0; i<anzahl_augen; i++) {
    pinMode(augen_pin[i],OUTPUT);
  }
  pinMode(tasterPin,INPUT_PULLUP);
  randomSeed(analogRead(0));
//  test();
}

void statistik(int anzahl) {
  Serial.println();
  Serial.print("Anzahl Würfe: "); Serial.println(anzahl);
  for (int i=0; i<6; i++) statistikArray[i] = 0;
  for (int i=0; i<anzahl; i++) {
    int zahl = random(1,6);
    zeige(zahl);
    statistikArray[zahl]++;
  }
  for (int i=1; i<6; i++) {  // 'aus' wird nicht ausgegeben
    Serial.print(i); Serial.print(": "); 
    Serial.print(statistikArray[i]); Serial.print(" / ");
    Serial.print(100.0/anzahl*statistikArray[i]); Serial.println(" %");
  } 
  delay(500);
}

void loop() {
  if (!digitalRead(tasterPin)) {
    statistik(10);
    statistik(100);
    statistik(1000);
    statistik(10000);
  }
}
