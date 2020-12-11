/*
  Rechnen 9
  Lösung der Übungsaufgabe
  
  Version 1.0
  Der Hobbyelektroniker
  Der Code ist Public Domain und kann ohne Einschränkungen frei verwendet werden

*/

int mult(int a, int b, int c) {
  return a * b * c;
}

int plus(int a, int b, int c) {
  return a + b + c;
}

void rechne(int (*operation)(int, int, int), int z1, int z2, int z3) {
  Serial.print(z1);

  if (operation == mult) {
    Serial.print(" x ");
    Serial.print(z2);
    Serial.print(" x ");
  } else {
    Serial.print(" + ");
    Serial.print(z2);
    Serial.print(" + ");
  }
    
  Serial.print(z3);
  Serial.print(" = ");
  Serial.println(operation(z1,z2,z3));
}

void setup() {
  Serial.begin(9600);
  Serial.println("Ich rechne mit drei Zahlen.");
  rechne(plus,3,5,7);
  rechne(mult,7,8,12);
}

void loop() {
}
