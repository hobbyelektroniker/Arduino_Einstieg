/* 
  Der leichte Einstieg in Arduino & Co.
  Die String - Klasse
  Strings zusammenfügen
  
  Version 1.00, 09.03.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

void zusammenfuegen() {
  String text1, text2, text3;
  Serial.println("Strings zusammenfügen");
  text1 = "Das ist der erste String.";
  text2 = "Das ist der zweite String.";
  text3 = text1 + text2;
  Serial.println(text3);
  Serial.println(text1 + " " + text2);
  Serial.println();
  text1.concat(text2);
  Serial.println(text1);
  Serial.println();

  text1 = String("Zahl ") + String("1");
  Serial.println(text1);
  text1 = String("Zahl ") + "1";
  Serial.println(text1);
  text1 = String("Zahl ") + 1;
  Serial.println(text1);
  
  text1 = "Zahl " + 2;
  Serial.println(text1);
  Serial.println(String("Zahl ") + 2);

  text1 = String("Zahl ");
  text1 += 3;
  Serial.println(text1);
}


void einMalEins(int zahl) {
  Serial.println();
  Serial.println("Das kleine EinMalEins");
  for (int i=1; i<11; i++) {
    Serial.println(String(i) + "\t*\t" + zahl + "\t=\t" + i*zahl);
  }
}

void addition(int zahl) {
  Serial.println();
  Serial.println("Addition");
  for (int i=1; i<11; i++) {
    Serial.println(String(i) + "\t+\t" + zahl + "\t=\t" + (i+zahl));
  }
}

void setup() {
  Serial.begin(9600);
  zusammenfuegen();  
  einMalEins(5);
  addition(7);
}

void loop() {
}
