/* 
  Der leichte Einstieg in Arduino & Co.
  String - Funktionen
  
  Version 1.00, 11.02.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

int intZahl = 25;
float floatZahl = 23.7;

/*
// 5006 Bytes / 326 Bytes
void ausgabe() {
  String text1 = "Die Integer - Zahl ist ";
  String text2 = "Die Float - Zahl ist ";
  Serial.println(text1 + String(intZahl));
  Serial.println(text2 + String(floatZahl,3));
}
*/

/*
// 4746 Bytes / 320 Bytes
void ausgabe() {
  char text1[] = "Die Integer - Zahl ist %d"; 
  char text2[] = "Die Float - Zahl ist %s";  
  char t1[30];
  sprintf(t1,text1,intZahl);

  char t2[30] = "";
  char tf[10];
  dtostrf(floatZahl, 0, 3, tf);
  sprintf(t2,text2,tf);
    
  Serial.println(t1);
  Serial.println(t2);
}
*/

/*
// 3520 Bytes / 330 Bytes
void ausgabe() {
  char text1[30] = "Die Integer - Zahl ist "; 
  char text2[30] = "Die Float - Zahl ist ";  
  char ti[5];
  itoa(intZahl,ti,10);
  strcat(text1,ti);

  char tf[10];
//  ftoa(floatZahl,tf,3);  // Das geht im Arduino nicht
  dtostrf(floatZahl, 0, 3, tf);
  strcat(text2,tf);
  
  Serial.println(text1);
  Serial.println(text2);
}
*/


//2874 Bytes / 316 Bytes
void ausgabe() {
  char text1[] = "Die Integer - Zahl ist "; 
  char text2[] = "Die Float - Zahl ist ";  
  Serial.print(text1);
  Serial.println(intZahl);
  Serial.print(text2);
  Serial.println(floatZahl,3);
}


void setup() {
  Serial.begin(9600);
  Serial.println("Das soll ausgegeben werden:");
  Serial.println("Die Integer - Zahl ist 25");
  Serial.println("Die Float - Zahl ist 23.700");
  Serial.println();
  ausgabe();
}

void loop() {
}
