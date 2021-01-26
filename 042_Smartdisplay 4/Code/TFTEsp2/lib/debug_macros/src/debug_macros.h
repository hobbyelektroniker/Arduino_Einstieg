/* 
  Debug Ausgaben
  Die Aktivierung erfolgt durch #define DEBUG im Hauptprogramm
  
  04.12.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/
#pragma once

#ifdef DEBUG
  void PrintOnce(String txt);
  void PrintlnOnce(String txt);

  #define SERIAL_BEGIN(speed) Serial.begin(speed)
  #define PRINTLN(txt) Serial.println(txt)
  #define PRINT(txt) Serial.print(txt)

  // Die Ausgabe erfolgt nur, wenn sich der Text geändert hat
  #define PRINTLN1(txt) PrintlnOnce(String(txt))
  #define PRINT1(txt) PrintOnce(String(txt))
  
#else
  #define SERIAL_BEGIN(speed)
  #define PRINTLN(txt)
  #define PRINT(txt)
  #define PRINTLN1(txt)
  #define PRINT1(txt)
#endif 
