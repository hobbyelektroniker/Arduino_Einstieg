/* 
  Der leichte Einstieg in Arduino & Co.
  Projekt Alarmanlage
  Displayansteuerung
  
  Version 1.00, 09.05.2019
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/

#define VERS 100

#include <arduino.h>
#include "globals.h"
#include "display.h"

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pins für rs, en, d4, d5, d6, d7

void printX(const char a[]) {
  int i = 0;
  while (true) {
    char ch = a[i++];
    if (ch == 0) return;
    if (ch == '&') {
      ch = a[i++];
      switch (ch) {
        case 'a': lcd.write(0xE1); 
                  break;
        case 'o': lcd.write(0xEF);
                  break; 
        case 'u': lcd.write(0xF5); 
                  break;
        default: if (ch < 128) lcd.write(ch);      
      }
    } else if (ch < 128) {
      lcd.write(ch);
    }
  } 
}

void display_print(String line1, String line2) {
  lcd.clear();
  printX(line1.c_str());
  lcd.setCursor(0,1); printX(line2.c_str());
}

void display_show(int neuerAlarm) {
  static int alarm = -1;
  if (alarm == neuerAlarm) return; // nichts geändert 
  alarm = neuerAlarm;
  switch (alarm) {
    case 0:
      display_print("Alles in","Ordnung!");
      break;
    case 1: // Licht festgestellt
      display_print("Das Licht ist","eingeschaltet!");
      break;
    case 2: // Bewegung festgestellt
      display_print("Bewegung","festgestellt!");
      break;
    case 3: // Licht und Bewegung 
      display_print("Ein Einbrecher","ist im Raum!");
      break;
    case 4: // Distanz unterschritten
      display_print("Hilfe, ich werde","angegriffen!");
      break;
    default:   
      lcd.clear();
  }
}

void display_init() {
  lcd.begin(16, 2);  // 16 Zeichen, 2 Zeilen
  lcd.clear();
}

int display_version() {
  return VERS;
}
