/*
  Lauflicht mit Berechnung
  Lösung 2 der Übungsaufgabe
  
  Version 1.0
  Der Hobbyelektroniker
  Der Code ist Public Domain und kann ohne Einschränkungen frei verwendet werden

*/

const int anzahlLeds = 6;

int pins[] = {3,5,6,9,10,11};

const int potiPin = A0;
const int helligkeitPotiPin = A1;

// Die LED's sind numeriert von 0 bis 5!
int alteLedNummer;
int ledNummer; // 0 bis 5
int richtung;  // 1 für auf und -1 für ab

void setup() {
  // Analoge Ausgänge benötigen kein pinMode

  // Startzustand
  alteLedNummer = 1;   // hier kann eine beliebige Lednummer eingetragen werden,
                       // mit Ausnahme der Startled
  ledNummer = 0;       // Start mit der LED 0
  richtung = 1;        // es geht nach oben
}

int helligkeit() {
  return map(analogRead(helligkeitPotiPin),0,1023,0,255);
}

void loop() {
  
  // Die LED's werden ein- und ausgeschaltet
  analogWrite(pins[ledNummer],helligkeit()); // Die aktuelle LED wird eingeschaltet
  analogWrite(pins[alteLedNummer],0); // Die alte LED wird ausgeschaltet

  // Die nächste LED wird ermittelt  
  alteLedNummer = ledNummer;                     // Die aktuelle LED wird zur alten LED
  ledNummer += richtung;                         // nächste LED bestimmen

  // Neue Richtung bestimmen
  if (ledNummer == anzahlLeds-1) richtung = -1;  // oben angekommen, wieder nach unten
  if (ledNummer == 0) richtung = 1;              // unten angekommen, wieder nach oben

  // Die Pause
  delay(map(analogRead(potiPin),0,1023,500,5));  // Die Pause wird vom Poti gelesen

}
