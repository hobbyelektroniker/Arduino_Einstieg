

// Grösster allozierbarer Block
int freeRam () 
{
  int size = 2048; 
  byte *buf;
  while ((buf = (byte *) malloc(--size)) == NULL);
  free(buf);
  return size;
}

void kurztest(long durchlaeufe) {
  Serial.println("Kurztest mit " + String(durchlaeufe) + " Durchläufen."); 
  for (int i = 1; i < durchlaeufe; i++) {
    float x = random(1000000) / 1000.0;
    String s = "Das ist ein String mit der Zufallszahl ";
    String s1 = String(x,3);
    String s2 = "";
    int anzahl = random(120);
    s1 += " / " + String(anzahl);
    for (int i=0; i<anzahl; i++) {
      s2 = s2 + char(random(65,91));
    }
    int freeMem = freeRam();
    s = String(freeMem) + ":  \t" + s + s1 + " - " + s2; 
    Serial.println(s.substring(0,100)); 
  }
}

void langtest(long durchlaeufe) {
  Serial.println("Langer Test mit " + String(durchlaeufe) + " Durchläufen."); 
  int minMem = 32000;
  int maxMem = 0;
  for (int i = 1; i < durchlaeufe; i++) {
    float x = random(1000000) / 1000.0;
    String s = "Das ist ein String mit der Zufallszahl ";
    String s1 = String(x,3);
    String s2 = "";
    int anzahl = random(120);
    s1 += " / " + String(anzahl);
    for (int i=0; i<anzahl; i++) {
      s2 = s2 + char(random(65,91));
    }
    int freeMem = freeRam();
    if (freeMem < minMem) minMem = freeMem;
    if (freeMem > maxMem) maxMem = freeMem;
    s = String(freeMem) + ":  \t" + s + s1 + " - " + s2; 
  }
  Serial.println("Minimaler freier Speicherplatz: " + String(minMem) + " Bytes.");
  Serial.println("Maximaler freier Speicherplatz: " + String(maxMem) + " Bytes.");
}

void setup() {
  int startRam = freeRam();
  Serial.begin(9600);
  randomSeed(analogRead(0));
  Serial.println("SPEICHERTEST");
  kurztest(20);
  Serial.println();
  unsigned long start = millis();
  langtest(1000);
  Serial.println("Das hat " + String(millis() - start) + " ms gedauert!");
  Serial.println("Freier Speicherplatz beim Start: " + String(startRam) + " Bytes.");
  Serial.println("Freier Speicherplatz am Ende: " + String(freeRam()) + " Bytes.");
}

void loop() {
}
