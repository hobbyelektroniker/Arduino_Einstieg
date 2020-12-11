/*
  Rechnen 2

  Version 1.0
  Der Hobbyelektroniker
  Der Code ist Public Domain und kann ohne Einschränkungen frei verwendet werden

*/

// Variablen
int zahl1 = 5;

void setup() {
  Serial.begin(9600);
  Serial.println("Ich gebe eine Zahl aus.");
  Serial.print("Die Zahl ist ");
  Serial.println(zahl1);
  zahl1 = 7;
  Serial.print("Die Zahl ist ");
  Serial.println(zahl1);
}

void loop() {
}
