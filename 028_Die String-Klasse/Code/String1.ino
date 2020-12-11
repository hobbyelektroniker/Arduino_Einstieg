/* 
  Der leichte Einstieg in Arduino & Co.
  Die String - Klasse
  Umwandlung Zahl <==> String
  
  Version 1.00, 09.03.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

void erzeugen() {
  String text;
  Serial.println("Strings erzeugen");
  text = "Hallo"; Serial.println(text);
  text = String("Hallo"); Serial.println(text);

  Serial.println();
  text = String('a'); Serial.println(text);

  Serial.println();
  text = String(18); Serial.println(text); // text = 18 wäre auch möglich
  text = String(18,DEC); Serial.println(text);
  text = String(18,HEX); Serial.println(text);
  text = String(18,BIN); Serial.println(text);
  text = String(18,OCT); Serial.println(text);
  text = String(18,8); Serial.println(text);
  text = String(18,17); Serial.println(text); // Beliebige Basis
  
  Serial.println();
  text = String(18.5); Serial.println(text); // Default: 2 Nachkommastellen
  text = String(18.5,3); Serial.println(text);
}

void stringZuZahl() {
  Serial.println();
  Serial.println("String zu Zahl");
  String s;
  
  // ganze Zahl
  s = "25"; 
  int i = s.toInt();
  Serial.print(s + ":\t"); Serial.println(i);
  s = "25.7";
  i = s.toInt();
  Serial.print(s + ":\t"); Serial.println(i);
  
  s = "25.35";
  float f = s.toFloat();
  double d = s.toDouble();
  Serial.print(s + ":\t"); Serial.print(f); Serial.print("\t"); Serial.println(d);
  
  s = "Keine Zahl";
  i = s.toInt();
  Serial.print(s + ":\t"); Serial.println(i);
  Serial.println();
}

void setup() {
  Serial.begin(9600);
  erzeugen();  
  stringZuZahl();
}

void loop() {
}
