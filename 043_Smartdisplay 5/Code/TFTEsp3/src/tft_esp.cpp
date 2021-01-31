/* 
    2.8" TFT SPI Display mit LOLIN D1 MINI (ESP8266)
  
  26.01.2021
  Der Hobbyelektroniker
  https://community.hobbyelektroniker.ch
  https://www.youtube.com/c/HobbyelektronikerCh
  Der Code kann mit Quellenangabe frei verwendet werden.
    
  Dieser Code basiert auf den Bibliotheken von Adafruit.
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
  TFT_eSPI::setTextColor(_fgColor,_bgColor);  
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

int16_t TFTEsp::drawText(const char* text, int16_t x, int16_t y, int16_t width, char align, int16_t xPadding, int16_t yPadding) {
  if (yPadding) {
    fillRect(x-xPadding,y-yPadding,width+2*xPadding, fontHeight()+2*yPadding-1, _bgColor);
  } else { 
    fillRect(x-xPadding,y,width+2*xPadding, fontHeight(), _bgColor);
  }
  int tw = textWidth(text);
  if (align == 'c') { // eingemittet
    x = x + int((width - tw) / 2);
  } else if (align == 'r') { // rechtbündig
    x = x + width - tw;
  }
  drawString(text,x,y);
  return width+xPadding;
}

TFTField::TFTField(TFTEsp* tft) {
  _tft = tft;
  _initialized = false;
}

void TFTField::begin() {
  if (_initialized) return;
  _initialized = true;
  _alignement = 'l';
  _x = _y = 0;
  _width = 20;
  _xPadding = 0;
  _yPadding = 0;
  _fgColor = _tft->getFgColor();
  _bgColor = _tft->getBgColor();
  _text = String("---");
}

void TFTField::setAlignement(char value) {
  begin();
  _alignement = value;
}

void TFTField::setPadding(int16_t x, int16_t y) {
  begin();
  _xPadding = x;
  _yPadding = y;
}

void TFTField::setPos(int16_t x, int16_t y, int16_t width) {
  begin();
  _x = x;
  _y = y;
  _width = width;
}

void TFTField::setText(const char* text) {
  begin();
  _text = String(text);
}

void TFTField::setText(const String text) {
  begin();
  _text = text;
}

void TFTField::setFgColor(uint16_t color) {
  begin();
  _fgColor = color;
}

void TFTField::setBgColor(uint16_t color) {
  begin();
  _bgColor = color;
}

uint16_t TFTField::getFieldWidth() {
  begin();
  return _width + _xPadding;
}

uint16_t TFTField::getFgColor() {
  begin();
  return _fgColor;
}

uint16_t TFTField::getBgColor() {
  begin();
  return _bgColor;
}

void TFTField::show() {
  begin();
  int16_t h = _tft->fontHeight();
  if (_yPadding) h += 2*_yPadding-1;

  // x-Position bei Rechtsbündigkeit berechnen
  int16_t x = _x;
  if (_alignement == 'r') {
    x = x + _width - _tft->textWidth(_text);
  } else if (_alignement == 'c') {
    x = x + int((_width - _tft->textWidth(_text)) / 2);
  }

  _tft->fillRect(_x-_xPadding, _y-_yPadding, _width+2*_xPadding, h, _bgColor);
  _tft->setTextColor(_fgColor,_bgColor);
  _tft->drawString(_text,x,_y);
}

