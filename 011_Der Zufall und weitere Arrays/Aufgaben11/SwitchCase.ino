/*
  Würfel mit 5 Augen
  
  Version 1.0
  Der Hobbyelektroniker
  Der Code ist Public Domain und kann ohne Einschränkungen frei verwendet werden
*/

void setup() {
  Serial.begin(9600);
}

void test(char c) {
  if (c < 'a') return;
  Serial.print(c); Serial.print(": ");
  switch (c) {
    case 'a':
      Serial.println("das ist a");
      break;
    case 'b':
      Serial.println("das ist b");
      break;
    case 'c':
      Serial.println("das ist c");
      break;
    case 'd':
      Serial.println("das ist d");
      break;
    case 'e':
      Serial.println("das ist e");
      break;
    case 'f':
      Serial.println("das ist f");
      break;
    default:
      Serial.println("das ist sonstwas");
  }  
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    test(c);
  }
}
