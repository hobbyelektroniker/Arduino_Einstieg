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

// Funktionen
// Alarmstufe  0: ok
//             1: Licht
//             2: Bewegung
//             3: Licht und Bewegung
//             4: Distanz unterschritten
void display_show(int alarmStufe);
void display_print(String line1, String line2 = "");


void display_init();   
int display_version(); // Version (100 --> Vers. 1.00)
