/*
  Rechnen 5

  Version 1.0
  Der Hobbyelektroniker
  Der Code ist Public Domain und kann ohne Einschränkungen frei verwendet werden

*/

void rechne(int z1, int z2) {
  Serial.print(z1);
  Serial.print(" x ");
  Serial.print(z2);
  Serial.print(" = ");
  Serial.println(z1*z2);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Ich multipliziere zwei Zahlen.");

  rechne(3,5);
  rechne(7,8);
}

void loop() {
}
