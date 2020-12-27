/***************************************************
  2.8" TFT SPI Display mit LOLIN D1 MINI (ESP8266)
  Fliesstext
 
  26.12.2020
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
 ****************************************************/


#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

// hardware SPI
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

/* Color definitions
#define ILI9341_BLACK 0x0000       ///<   0,   0,   0
#define ILI9341_NAVY 0x000F        ///<   0,   0, 123
#define ILI9341_DARKGREEN 0x03E0   ///<   0, 125,   0
#define ILI9341_DARKCYAN 0x03EF    ///<   0, 125, 123
#define ILI9341_MAROON 0x7800      ///< 123,   0,   0
#define ILI9341_PURPLE 0x780F      ///< 123,   0, 123
#define ILI9341_OLIVE 0x7BE0       ///< 123, 125,   0
#define ILI9341_LIGHTGREY 0xC618   ///< 198, 195, 198
#define ILI9341_DARKGREY 0x7BEF    ///< 123, 125, 123
#define ILI9341_BLUE 0x001F        ///<   0,   0, 255
#define ILI9341_GREEN 0x07E0       ///<   0, 255,   0
#define ILI9341_CYAN 0x07FF        ///<   0, 255, 255
#define ILI9341_RED 0xF800         ///< 255,   0,   0
#define ILI9341_MAGENTA 0xF81F     ///< 255,   0, 255
#define ILI9341_YELLOW 0xFFE0      ///< 255, 255,   0
#define ILI9341_WHITE 0xFFFF       ///< 255, 255, 255
#define ILI9341_ORANGE 0xFD20      ///< 255, 165,   0
#define ILI9341_GREENYELLOW 0xAFE5 ///< 173, 255,  41
#define ILI9341_PINK 0xFC18        ///< 255, 130, 198
*/

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(9600);
  Serial.println("ILI9341 Test!"); 
 
  tft.begin();
  tft.fillScreen(ILI9341_BLUE);
  tft.setRotation(2);
  tft.setTextSize(1);
  tft.setTextColor(ILI9341_YELLOW, ILI9341_BLUE);
  tft.setTextWrap(true);
  tft.print("Das ist ein kleiner Text. ");
  tft.println("Und schon geht es weiter.");
  tft.println("Was passiert, wenn der Text viel länger als eine Zeile ist? Gibt es dann einen Zeilenumbruch?");
  
}

void loop() {
//
}
