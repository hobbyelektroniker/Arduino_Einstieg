#include "debug_macros.h"

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
#endif
