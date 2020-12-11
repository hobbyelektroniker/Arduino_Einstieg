/*
  Rechnen 4

  Version 1.0
  Der Hobbyelektroniker
  Der Code ist Public Domain und kann ohne Einschränkungen frei verwendet werden

*/

// Variablen
int zahl1, zahl2;

void rechne() {
  Serial.print(zahl1);
  Serial.print(" x ");
  Serial.print(zahl2);
  Serial.print(" = ");
  Serial.println(zahl1*zahl2);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Ich multipliziere zwei Zahlen.");

  // Wert der Zahlen festlegen
  zahl1 = 3; zahl2 = 5;
  rechne();

  // Wert der Zahlen festlegen
  zahl1 = 7; zahl2 = 8;
  rechne();
}

void loop() {
}
