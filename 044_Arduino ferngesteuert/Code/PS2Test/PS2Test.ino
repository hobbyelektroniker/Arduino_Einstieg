/* 
  Objektorientiert Programmierung
  Arduinosteuerung mit PS2-Controller
    
  Version 1.00, 08.02.2021
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
*/


#include <PS2X_lib.h>  

PS2X ps2; // ps2 - Instanz erzeugen
int vibrate = 0;

void setup(){
  Serial.begin(57600);
  int fehler = ps2.config_gamepad(13,11,10,12, false, true);   // CLK, CMD, CS, DATA, Pressures?, Rumble

  switch (fehler) {
    case 0: int type = ps2.readType();
            switch (type) {
              case 0: Serial.println("Unbekannter Controller: kein Test möglich"); 
                      while (true);
                      break;
              case 1: Serial.println("DualShock Controller gefunden");
                      break;
              case 2: Serial.println("GuitarHero Controller: kein Test möglich"); 
                      while (true);
                      break;
            }
            break;
    case 1: Serial.println("Keine Kommunikation mit dem Controller: kein Test möglich");
            while (true);
            break;
    default: Serial.println("Probleme mit dem Controller festgestellt!");
  }
  Serial.println("Initialisierung...");
  for (int i=0; i< 5; i++) ps2.read_gamepad();  
  Serial.println("Bereit für Test");
}

void checkButton(unsigned int bt, String txt) {
  if (ps2.Button(bt)) Serial.println(txt);
  if (ps2.ButtonPressed(bt)) Serial.println(String(txt) + " gedrückt");
  if (ps2.ButtonReleased(bt)) Serial.println(String(txt) + " losgelassen");
  if (ps2.NewButtonState(bt)) Serial.println(String(txt) + " geändert");
}

void checkAnalog() {
  int x = ps2.Analog(PSS_LX);
  int y = ps2.Analog(PSS_LY);
  if (x < 125 || x > 130 || y < 125 || y > 130) {
    Serial.println(String("links  x = ") + x + ", y = " + y);
  }
  x = ps2.Analog(PSS_RX);
  y = ps2.Analog(PSS_RY);
  if (x < 125 || x > 130 || y < 125 || y > 130) {
    Serial.println(String("rechts x = ") + x + ", y = " + y);
  }
}

void testAll() {
  checkButton(PSB_START,"START");
  checkButton(PSB_SELECT,"SELECT");
  
  checkButton(PSB_PAD_UP,"AUF");
  checkButton(PSB_PAD_DOWN,"AB");
  checkButton(PSB_PAD_LEFT,"LINKS");
  checkButton(PSB_PAD_RIGHT,"RECHTS");
  
  checkButton(PSB_TRIANGLE,"DREIECK"); // GREEN
  checkButton(PSB_CIRCLE,"KREIS");     // RED
  checkButton(PSB_SQUARE,"QUADRAT");   // PINK
  checkButton(PSB_CROSS,"KREUZ");      // BLUE

  checkButton(PSB_L1,"L1");
  checkButton(PSB_L2,"L2");
  checkButton(PSB_L3,"L3");

  checkButton(PSB_R1,"R1");
  checkButton(PSB_R2,"R2");
  checkButton(PSB_R3,"R3");

  if (ps2.ButtonPressed(PSB_CROSS)) vibrate = 100;    
  if (ps2.ButtonReleased(PSB_CROSS)) vibrate = 0;    

//  if (ps2.NewButtonState()) Serial.println("beliebige Taste geändert");

  checkAnalog();

}

void loop(){
  ps2.read_gamepad(false,vibrate); // Controller lesen
  testAll();
  delay(50);
}
