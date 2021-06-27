#include <Wire.h>
#include <math.h>
#include <EEPROM.h>

// Wenn DEBUG aktiviert ist, erfolgt eine Ausgabe auf den seriellen Monitor.
// Andernfalls muss der Plotter verwendet werden!
// Die Geschwindigkeit muss auf 115200 eingestellt werden.

//#define DEBUG
#include "debug_macros.h"

#include "mpu6050.h"

// Eine Instanz des Lagesensors erstellen
MPU6050 mpu;

// data from the IMU
Angles angles;
Measurement measurement;

void setup() {
  Serial.begin(115200);
  PRINTLN();
  PRINTLN("Initializing...");
  Wire.begin();
  mpu.begin();
  //mpu.calibrate();

  PRINTLN("Ready");
}                                                                                                                                                         

// Hier stehen alle Aufrufe, die häufig gemacht werden müssen
void _loop() {
  mpu.readValues();
}

// Diese delay() blockiert nicht vollständig,
// es ruft während dem Warten _loop() auf
void _delay(unsigned long ms) {
  unsigned long endWait = millis() + ms;
  while (millis() < endWait) {
    _loop();
  }
}

void loop() {
  _loop();
  #ifdef DEBUG
    //mpu.readRaw(measurement);     // Rohe Messwerte
    //mpu.read(measurement);        // umgerechnet 
    //mpu.getValues(measurement);   // korrigiert um Offset
    //logMeasurements(measurement); // Anzeige der Messwerte 
    mpu.getAngles(angles);        // Roll (x), Pitch (y), Yaw (z)
    logData(angles);              // Anzeige der Winkel
    _delay(100);
  #else  
    mpu.getAngles(angles);
    plotData(angles);
    _delay(10);
  #endif
}

void logData(Angles &angles) {
  static char roll[7];
  static char pitch[7];
  static char yaw[7];
  dtostrf(angles.roll,6, 2, roll);
  dtostrf(angles.pitch,6, 2, pitch);
  dtostrf(angles.yaw,6, 2, yaw);
  
  Serial.print("Roll: ");
  Serial.print(roll);
  Serial.print(", Pitch: ");
  Serial.print(pitch);
  Serial.print(", Yaw: ");
  Serial.println(yaw);
}

void logMeasurements(Measurement &m) {
  static char accelX[9];
  static char accelY[9];
  static char accelZ[9];
  static char gyroX[9];
  static char gyroY[9];
  static char gyroZ[9];
  dtostrf(m.accel.x,8, 2, accelX);
  dtostrf(m.accel.y,8, 2, accelY);
  dtostrf(m.accel.z,8, 2, accelZ);
  dtostrf(m.gyro.x,8, 2, gyroX);
  dtostrf(m.gyro.y,8, 2, gyroY);
  dtostrf(m.gyro.z,8, 2, gyroZ);
  
  Serial.print("Accel x: ");
  Serial.print(accelX);
  Serial.print(", y: ");
  Serial.print(accelY);
  Serial.print(", z: ");
  Serial.print(accelZ);
  Serial.print("   --- Gyro x: ");
  Serial.print(gyroX);
  Serial.print(", y: ");
  Serial.print(gyroY);
  Serial.print(", z: ");
  Serial.println(gyroZ);

  
}

void plotData(Angles &angles) {
  Serial.print("Min:-90,Max:90,Roll:");
  Serial.print(angles.roll);
  Serial.print(",Pitch:");
  Serial.print(angles.pitch);
  Serial.print(",Jaw:");
  Serial.println(angles.yaw);  
}
