/* 
    2.8" TFT SPI Display mit LOLIN D1 MINI (ESP8266)
  
  15.01.2021
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
    
  Dieser Code basiert auf der Bibliothek TFT_eSPI.
  https://github.com/Bodmer/TFT_eSPI
*/

#include "tft_esp.h"

TFTEsp::TFTEsp() : TFT_eSPI() {}

// Bildschirm löschen
void TFTEsp::cls() {
  cls(_bgColor);
}

void TFTEsp::cls(uint16_t color) {
  fillScreen(color);
}

// Farben
void TFTEsp::setFgColor(uint16_t color) {
  _fgColor = color;
  setTextColor();
}

void TFTEsp::setBgColor(uint16_t color) {
  _bgColor = color;
  setTextColor();
}

void TFTEsp::setTextColor() {
  setTextColor(_fgColor,_bgColor);  
}

void TFTEsp::setTextColor(uint16_t fgColor, uint16_t bgColor) {
  TFT_eSPI::setTextColor(fgColor,bgColor);  
}

uint16_t TFTEsp::getFgColor() {
  return _fgColor;
}

uint16_t TFTEsp::getBgColor() {
  return _bgColor;
}
