/*
  Arrays
  
  Version 1.0
  Der Hobbyelektroniker
  Der Code ist Public Domain und kann ohne Einschränkungen frei verwendet werden

*/

// Schulnoten
float bart_note1 = 4, bart_note2 = 3.5, bart_note3 = 4.5;
float lisa_note1 = 1.25, lisa_note2 = 1, lisa_note3 = 2, lisa_note4 = 1;

void durchschnittBart() {
  float total = bart_note1 + bart_note2 + bart_note3;
  float durchschnitt = total / 3;
  Serial.print("Bart bekommt die Zeugnisnote ");
  Serial.println(durchschnitt);
}

void durchschnittLisa() {
  float total = lisa_note1 + lisa_note2 + lisa_note3 + lisa_note4;
  float durchschnitt = total / 4;
  Serial.print("Lisa bekommt die Zeugnisnote ");
  Serial.println(durchschnitt);
}

void setup() {
  Serial.begin(9600);
  durchschnittBart();
  durchschnittLisa();
}

void loop() {
}
