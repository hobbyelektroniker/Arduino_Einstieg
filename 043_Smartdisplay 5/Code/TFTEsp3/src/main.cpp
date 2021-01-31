#include <Arduino.h>
/***************************************************
  2.8" TFT SPI Display mit LOLIN D1 MINI (ESP8266)
  Daten von Wetterstation empfangen
 
  30.01.2021
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
 ****************************************************/

#include "tft_esp.h"
TFTEsp disp = TFTEsp();       // Instanz der eigenen Klasse erstellen

//*********************
//* Screen definieren *
//*********************

// Das sind die Felder für die anzuzeigenden Werte
TFTField zeitFeld = TFTField(&disp);
TFTField tempFeld = TFTField(&disp);
TFTField feuchteFeld = TFTField(&disp);
TFTField druckFeld = TFTField(&disp);

TFTField ortFeld = TFTField(&disp);
TFTField wind_geschwFeld = TFTField(&disp);


// Diese Daten werden von extern empfangen
String zeitWert, ortWert;
float tempWert, feuchteWert, wind_geschwWert;
int druckWert;

void setTestValues() {
  zeitWert = "TT.MM.JJJJ SS:MM:ss";
  tempWert = 0;
  feuchteWert = 0;
  druckWert = 0;
  ortWert = "irgendwo";
  wind_geschwWert = 0;
}

// Hier werden die fixen Texte angezeigt und die Positionen der Elemente festgelegt
void prepareScreen() {
  // Display vorbereiten
  disp.setFgColor(TFT_YELLOW);
  disp.setBgColor(TFT_BLUE);
  disp.setRotation(1); // Breitformat 320 x 240
  disp.cls(); // Bildschirm löschen

  // Titel
  disp.setTextSize(3);
  disp.drawText("Wetter",0,0,disp.width(),'c');
  int y = disp.fontHeight() + 5;

  // Ort
  disp.setTextSize(2);
  ortFeld.setAlignement('c');
  ortFeld.setPos(0,y,disp.width());
  y += disp.fontHeight() + 10;

  // Zeitfeld
  zeitFeld.setAlignement('c');
  zeitFeld.setPos(0,y,disp.width());
  zeitFeld.setPadding(0,2);
  zeitFeld.setBgColor(TFT_BROWN);
  y += disp.fontHeight() + 30;

  // Feldgrössen und Position
  int feldAbstand = disp.fontHeight() + 8;
  int labelBreite = disp.textWidth("Windgeschw."); // Längster Text
  int feldtextBreite = disp.textWidth(" 1025");

  // Temperatur
  int x = 0;
  disp.drawString("Temperatur",x,y);
  tempFeld.setAlignement('r');
  tempFeld.setPos(labelBreite+10,y,feldtextBreite);
  disp.drawString("C",x+labelBreite+10+tempFeld.getFieldWidth()+5,y);
  y += feldAbstand;

  // Feuchte
  x = 0;
  disp.drawString("Feuchte",x,y);
  feuchteFeld.setAlignement('r');
  feuchteFeld.setPos(labelBreite+10,y,feldtextBreite);
  disp.drawString("%",x+labelBreite+10+feuchteFeld.getFieldWidth()+5,y);  
  y += feldAbstand;

  // Luftdruck
  x = 0;
  disp.drawString("Luftdruck",x,y);
  druckFeld.setAlignement('r');
  druckFeld.setPos(labelBreite+10,y,feldtextBreite);
  disp.drawString("hPa",x+labelBreite+10+druckFeld.getFieldWidth()+5,y); 

  // Windgeschwindigkeit
  x = 0;
  disp.drawString("Windgeschw.",x,y);
  wind_geschwFeld.setAlignement('r');
  wind_geschwFeld.setPos(labelBreite+10,y,feldtextBreite);
  disp.drawString("m/s",x+labelBreite+10+wind_geschwFeld.getFieldWidth()+5,y); 

}

// Die variablen Werte werden angezeigt
void showValues() {
  tempFeld.setText(String(tempWert,1));
  feuchteFeld.setText(String(feuchteWert,1));
  druckFeld.setText(String(druckWert));
  zeitFeld.setText(zeitWert);
  ortFeld.setText(ortWert);
  wind_geschwFeld.setText(String(wind_geschwWert,1));

  zeitFeld.show();
  tempFeld.show();
  feuchteFeld.show();
  druckFeld.show();
  ortFeld.show();
  wind_geschwFeld.show();

}

//***************************************
//* Empfangener Datenstring verarbeiten *
//***************************************

// Ein neuer Wert wurde empfangen und wird der entsprechenden Variablen zugewiesen
void newValue(String key, String val) {
  if (key.equals("temp")) {
    tempWert = val.toFloat();
  } else if (key.equals("feuchte")) {
    feuchteWert = val.toFloat();
  } else if (key.equals("druck")) {
    druckWert = val.toInt();
  } else if (key.equals("zeit")) {
    zeitWert = val;
  } else if (key.equals("wind_geschw")) {
    wind_geschwWert = val.toFloat();
  } else if (key.equals("ort")) {
    ortWert = val;
  }
}

void newCmdOrValue(const char* text) {
  String cmd = String(text);
  if (cmd.equals("<cls>")) {
    prepareScreen();
    showValues();
  } else if (cmd.equals("<show>")) {
    showValues();
  } else if (cmd.startsWith("[")) {
    int i = cmd.indexOf("]=");
    if (i<0) return;
    String key = cmd.substring(1,i);
    String val = cmd.substring(i+2); 
    newValue(key,val);
  }
}

//****************
//* Datenempfang *
//****************

void fromSerial() {
  char buffer[80];
  int anzahl = 0;
  char ch;

  while (true) {
    if (Serial.available()) {
      ch = Serial.read();
      if (ch == 13 || anzahl == 79) { // String beendet
        buffer[anzahl] = 0;
        newCmdOrValue(buffer);
        anzahl = 0;
      }
      if (ch >= ' ') {  // keine Steuerzeichen einfügen 
        buffer[anzahl++] = ch;
      }
    }
  }
}

//*****************
//* Hauptprogramm *
//*****************

void setup() {
  Serial.begin(9600);
 
  disp.begin();    // Display aktivieren
  setTestValues(); // Testwerte laden
  prepareScreen(); // Ausgabebildschirm definieren
  showValues();    // Testwerte anzeigen

  fromSerial();    // Daten von seriellen Monitor einlesen
}

void loop() {
}

