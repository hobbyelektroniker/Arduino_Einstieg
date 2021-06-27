#pragma once

#ifdef DEBUG
  void PrintOnce(String txt) {
    static String old("");
    static int count = 0;
    if (!txt.equals(old)) {
      old = txt;
      count++;
      if (count > 5) {
        Serial.println(txt);
        count = 0;
      } else {
        Serial.print(txt + ", ");
      }
    }
  }

  void PrintlnOnce(String txt) {
    static String old("");
    if (!txt.equals(old)) {
      old = txt;
      Serial.println(txt);
    }
  }

  #define SERIAL_BEGIN(speed) Serial.begin(speed)
  #define PRINTLN(txt) Serial.println(txt)
  #define PRINT(txt) Serial.print(txt)
  #define PRINTLN1(txt) PrintlnOnce(String(txt))
  #define PRINT1(txt) PrintOnce(String(txt))
  
#else
  #define SERIAL_BEGIN(speed)
  #define PRINTLN(txt)
  #define PRINT(txt)
  #define PRINTLN1(txt)
  #define PRINT1(txt)
#endif  
