/*
  Rechnen 8

  Version 1.0
  Der Hobbyelektroniker
  Der Code ist Public Domain und kann ohne Einschränkungen frei verwendet werden

*/

int mult(int a, int b) {
  return a * b;
}

int plus(int a, int b) {
  return a + b;
}

void rechne(int (*operation)(int, int), int z1, int z2) {
  Serial.print(z1);

  if (operation == mult) {
    Serial.print(" x ");
  } else {
    Serial.print(" + ");
  }
    
  Serial.print(z2);
  Serial.print(" = ");
  Serial.println(operation(z1,z2));
}

void setup() {
  Serial.begin(9600);
  Serial.println("Ich rechne mit zwei Zahlen.");
  rechne(plus,3,5);
  rechne(mult,7,8);
}

void loop() {
}
