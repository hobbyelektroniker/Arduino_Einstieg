#include <Arduino.h>
/***************************************************
  2.8" TFT SPI Display mit LOLIN D1 MINI (ESP8266)
  Eine einfache eigene TFT - Klasse (TFTEsp)
 
  15.01.2021
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
 ****************************************************/

#include "tft_esp.h"
TFTEsp disp = TFTEsp();       // Instanz der eigenen Klasse erstellen

/* hardware SPI
#define TFT_MOSI D7
#define TFT_CLK  D5

// other pins
#define TFT_CS    D2     
#define TFT_RST   D3     
#define TFT_DC    D4     

/* Betriebsspannung
 *  VCC 3.3V
 *  LED 3.3V
 *  GND GND
 */

// Farbdefinitionen aus Library (TFT_eSPI.h)
// #define TFT_BLACK       0x0000      /*   0,   0,   0 */
// #define TFT_NAVY        0x000F      /*   0,   0, 128 */
// #define TFT_DARKGREEN   0x03E0      /*   0, 128,   0 */
// #define TFT_DARKCYAN    0x03EF      /*   0, 128, 128 */
// #define TFT_MAROON      0x7800      /* 128,   0,   0 */
// #define TFT_PURPLE      0x780F      /* 128,   0, 128 */
// #define TFT_OLIVE       0x7BE0      /* 128, 128,   0 */
// #define TFT_LIGHTGREY   0xD69A      /* 211, 211, 211 */
// #define TFT_DARKGREY    0x7BEF      /* 128, 128, 128 */
// #define TFT_BLUE        0x001F      /*   0,   0, 255 */
// #define TFT_GREEN       0x07E0      /*   0, 255,   0 */
// #define TFT_CYAN        0x07FF      /*   0, 255, 255 */
// #define TFT_RED         0xF800      /* 255,   0,   0 */
// #define TFT_MAGENTA     0xF81F      /* 255,   0, 255 */
// #define TFT_YELLOW      0xFFE0      /* 255, 255,   0 */
// #define TFT_WHITE       0xFFFF      /* 255, 255, 255 */
// #define TFT_ORANGE      0xFDA0      /* 255, 180,   0 */
// #define TFT_GREENYELLOW 0xB7E0      /* 180, 255,   0 */
// #define TFT_PINK        0xFE19      /* 255, 192, 203 */ //Lighter pink, was 0xFC9F      
// #define TFT_BROWN       0x9A60      /* 150,  75,   0 */
// #define TFT_GOLD        0xFEA0      /* 255, 215,   0 */
// #define TFT_SILVER      0xC618      /* 192, 192, 192 */
// #define TFT_SKYBLUE     0x867D      /* 135, 206, 235 */
// #define TFT_VIOLET      0x915C      /* 180,  46, 226 */

void test1() {
  disp.setFgColor(TFT_YELLOW);
  disp.setBgColor(TFT_BLUE);
  disp.cls(TFT_RED);
  delay(3000);

  disp.cls();
  disp.setRotation(1);
  disp.setTextSize(2);
  
  disp.print("Hallo Welt!");
  disp.setTextWrap(true);
  disp.setTextColor(TFT_SILVER,TFT_BROWN);
  disp.println("Dieser Text ist von der neuen Klasse!. ");
  disp.println("Und schon geht es weiter.");
  disp.setTextColor();
  disp.println("Was passiert, wenn der Text viel länger als eine Zeile ist? Gibt es dann einen Zeilenumbruch?"); 
}

void test2() {
  disp.setFgColor(TFT_YELLOW);
  disp.setBgColor(TFT_BLUE);
  disp.cls();
  disp.setRotation(1);
  disp.setTextSize(2);

  disp.setCursor(10,20);
  disp.println(String("x-Richtung: ") + disp.width());
  disp.println(String("y-Richtung: ") + disp.height());

  disp.drawString("Position 50 / 100",50,100);
  disp.drawString(String("Position 50 / 120"),50,120);

}

void setup() {
  Serial.begin(9600);
  Serial.println("ILI9341 Test!"); 
 
  disp.begin();
    //test1();
    test2();


}

void loop() {
//
}
