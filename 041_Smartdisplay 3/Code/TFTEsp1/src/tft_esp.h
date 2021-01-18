/* 
  2.8" TFT SPI Display mit LOLIN D1 MINI (ESP8266)
  Header-Datei
  
  15.01.2021
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
    
  Dieser Code basiert auf der Bibliothek TFT_eSPI.
  https://github.com/Bodmer/TFT_eSPI
 
*/

#pragma once

////////// Pinbelegung /////////////

/* Betriebsspannung
 *  VCC 3.3V
 *  LED 3.3V
 *  GND GND
 */

/* Hardware SPI
 *  MOSI D7
 *  CLK  D5
 *  MISO D6 (nicht verwendet)
 */

/* empfohlene Pins (frei wählbar)
 *  CS  D2
 *  RST D3
 *  DC  D4
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


#include <TFT_eSPI.h> // Hardware-specific library

class TFTEsp : public TFT_eSPI {
  public:
    
    TFTEsp();
// geerbte Funktionen    
//  void begin();
//  void setRotation()

    // Bildschirm löschen
    void cls();
    void cls(uint16_t color);

    // *** Farben ***
    void setFgColor(uint16_t color);
    void setBgColor(uint16_t color);
    uint16_t getFgColor();
    uint16_t getBgColor();
    
    // *** Textausgabe ***
    // void print();
    // void println();
    // void setTextSize()

    void setTextColor(); // setzt die Textfarbe wieder auf die Standardfarben
    void setTextColor(uint16_t fgColor, uint16_t bgColor);


  private:
    uint16_t _fgColor = ILI9341_WHITE;
    uint16_t _bgColor = ILI9341_BLACK;

};

     

    
