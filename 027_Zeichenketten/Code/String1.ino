/* 
  Der leichte Einstieg in Arduino & Co.
  Strings
  
  Version 1.00, 11.02.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

char hallo1[] = "Hallo 1";
char zeichen = 'A'; // Das ist kein String!!!
char zeichenString[] = "A"; // Das ist ein String!!!
char hallo2[8] = "Hallo 2";
char hallo3[7] = "Hallo 3"; // Ein Byte zuwenig, gibt Falschausgabe
char hallo4[12] = "Hallo 4";
String hallo = "Hallo"; 

void setup() {
  Serial.begin(9600);
  Serial.println(hallo1);
  Serial.println(zeichen);
  Serial.println(zeichenString);
  Serial.println(hallo2); 
  Serial.println(hallo3); // gibt eine falsche Ausgabe
  Serial.println(hallo4);
  Serial.println(hallo);
  Serial.println();
  Serial.println("Hallo4 im Detail");
  for (int i=0; i<sizeof(hallo4); i++) {
    Serial.print(i);
    Serial.print(":\t");
    Serial.print(int(hallo4[i]));
    Serial.print("\t");
    Serial.println(hallo4[i]);
  }
}

void loop() {
}
