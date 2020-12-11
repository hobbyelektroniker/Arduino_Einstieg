/* 
  Der leichte Einstieg in Arduino & Co.
  Die String - Klasse
  Weitere Funktionen
  
  Version 1.00, 10.03.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/



void setup() {
  Serial.begin(9600);
  String s = " Hallo, das ist ein Text   ";
  Serial.println(s + " ist " + s.length() + " Zeichen lang!");
  s.trim();
  Serial.println(s + " ist " + s.length() + " Zeichen lang!");
  
  Serial.println();
  s.replace("Text","String.");
  Serial.println(s);
  
  Serial.println();
  s.toLowerCase();
  Serial.println(s);
  s.toUpperCase();
  Serial.println(s);
  
}

void loop() {
}
