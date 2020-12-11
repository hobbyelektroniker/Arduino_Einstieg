#pragma once
//#ifndef Blink_H
//#define Blink_H

void initLed(int pin) {
  pinMode(pin,OUTPUT);
}

void blinkLed(int pin, int zeit) {
  digitalWrite(pin, HIGH); 
  delay(zeit); 
  digitalWrite(pin, LOW); 
  delay(zeit);  
}             

//#endif
