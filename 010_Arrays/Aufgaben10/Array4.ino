/*
  Arrays
  
  Version 1.0
  Der Hobbyelektroniker
  Der Code ist Public Domain und kann ohne Einschränkungen frei verwendet werden

*/

// Schulnoten
float bart[] = {4, 3.5, 4.5};
float lisa[] = {1.25, 1, 2, 1};

float durchschnitt(float noten[]) {
  int anzahl = sizeof(noten)/sizeof(noten[0]); // Geht NICHT!!!
  Serial.println(sizeof(noten));
  Serial.println(sizeof(noten[0]));
  Serial.println(anzahl);

  float total = 0;
  for (int i=0; i<anzahl; i++) {
    total += noten[i];
  }
  return total / anzahl;
}

void setup() {
  Serial.begin(9600);
  
  Serial.print("Bart bekommt die Zeugnisnote ");
  Serial.println(durchschnitt(bart));

  Serial.print("Lisa bekommt die Zeugnisnote ");
  Serial.println(durchschnitt(lisa));
  
}

void loop() {
}
