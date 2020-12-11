const int zeit = 1000;

void blink() {
  digitalWrite(LED, HIGH);   
  delay(zeit);               
  digitalWrite(LED, LOW);    
  delay(zeit);               
}
