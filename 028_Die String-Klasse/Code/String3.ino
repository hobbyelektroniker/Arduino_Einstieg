/* 
  Der leichte Einstieg in Arduino & Co.
  Die String - Klasse
  Strings vergleichen
  Indexierung
  
  Version 1.00, 10.03.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

void vergleich() {
  String s1 = "Hallo Welt";
  String s2 = "Das ist ein String";

  Serial.println(s2 == "Das ist ein String");
  Serial.println(s1 == s2);
  Serial.println(s2.equals("Das ist ein String"));
  Serial.println(s2.equalsIgnoreCase("das ist ein string"));
  
  Serial.println();
  Serial.println(s1.startsWith("Hallo"));
  Serial.println(s1.endsWith("Welt"));

  Serial.println();
  Serial.println(s1 != s2);
  Serial.println(s1 > s2);
  Serial.println(s1.compareTo(s2));
}

void indexierung() {
  Serial.println();
  
  String s = "Hallo";
  Serial.println(s);
  Serial.println(s[1]);
  Serial.println(s.charAt(1));
  s[1] = 'A';
  Serial.println(s);
  s.setCharAt(1,'a');
  Serial.println(s);

  Serial.println();
  Serial.println(String("Länge von ") + s + ": " + s.length());
  Serial.println(s.substring(1));
  Serial.println(s.substring(1,3));

  Serial.println();
  s = "Die String - Objekte benötigen mehr Speicher als C-Strings";
  Serial.println(String("Länge von ") + s + ": " + s.length());
  Serial.println(s.indexOf("String"));
  Serial.println(s.lastIndexOf("String"));
  Serial.println(s.indexOf("String",5));
  
  Serial.println();
  s = "Die String - Objekte";
  Serial.println(s);
  s.remove(3);
  Serial.println(s);
  s = "Die String - Objekte";
  s.remove(4,9);
  Serial.println(s);
}

void setup() {
  Serial.begin(9600);
  vergleich();  
//  indexierung();
  
}

void loop() {
}
