/* 
  Der leichte Einstieg in Arduino & Co.
  Projekt Alarmanlage
  Leuchtdioden
  
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
void leds_show(int alarmStufe);

void leds_init();   // Led's initialisieren
int leds_version(); // Version (100 --> Vers. 1.00)
