
/*
 * Arduino UNO, Nano
 * SDA=A4, SCL=A5
 * 
 * MPU6050: Standard I2C-Adresse: 104
 * 
 * Wire muss im Hauptprogramm importiert werden.
 * Wire.begin() muss im Hauptprogramm vor MPU6050.begin() aufgerufen werden. 
 */

const float COPLEMENTARY_FILTER_WEIGHT = 0.98;
const int EEPROM_SIGNATURE = 27298;

struct Vector {
  float x;
  float y;
  float z;
  
  void clear() {
    x = 0.0;
    y = 0.0;
    z = 0.0;
  }
};

struct Measurement {
  Vector accel;
  float temp;
  Vector gyro;
  
  void clear() {
    accel.clear();
    temp = 0.0;
    gyro.clear();
  }  
};

struct Angles {
  float roll;   // x - Achse
  float pitch;  // y - Achse
  float yaw;    // z - Achse
  
  void clear() {
    roll = 0;
    pitch = 0;
    yaw = 0;
  }
};

class MPU6050 {
  public:

    // Muss zur Initialisierung einmalig aufgerufen werden!
    void begin(int address = 104) {
      _address = address;

      // MPU - Konfiguration
      setRegister(0x6B, 0); // SLEEP = 0
      setRegister(0x1B, 0); // Gyro full scale +/- 250 deg/s
      setRegister(0x1C, 0); // accel to +/- 2g    

      // Umrechnungsfaktoren, abhängig von der MPU - Konfiguration
      _accel_sensitivity_conversion = 16384;
      _gyro_sensitivity_conversion = 131;  

      // noch keine Messung vorhanden
      _lastMeasurement.clear();
      _lastMeasurementTime = 0;
      _angles.clear();
      _rollAngle = 0;
      _pitchAngle = 0;

      delay(100);

      // Offset - Werte laden
      loadOffset();
    }

    // Bei Bedarf kann eine Kalibrierung durchgeführt werden
    // Der Sensor muss in seiner Ruheposition stehen 
    void calibrate(int iterations = 1000) {
      PRINTLN("Calibrating...");
      Measurement m;

      // Alte Kalibrierungsdaten löschen
      _accelOffset.clear();
      _gyroOffset.clear();

      // Mehrere Werte aufaddieren
      for (int i=0; i<iterations; i++) {
        read(m);
        _accelOffset.x += m.accel.x;
        _accelOffset.y += m.accel.y;
        _accelOffset.z += m.accel.z;
        _gyroOffset.x += m.gyro.x;
        _gyroOffset.y += m.gyro.y;
        _gyroOffset.z += m.gyro.z;
      }

      // Durchschnittswerte berechnen
      _accelOffset.x /= iterations;
      _accelOffset.y /= iterations;
      _accelOffset.z /= iterations;
      _gyroOffset.x /= iterations;
      _gyroOffset.y /= iterations;
      _gyroOffset.z /= iterations;

      // Offsets berechnen (Soll - Durchschnitt)
      _accelOffset.x = 0.0 - _accelOffset.x;
      _accelOffset.y = 0.0 - _accelOffset.y;
      _accelOffset.z = 1.0 - _accelOffset.z;
      _gyroOffset.x = 0.0 - _gyroOffset.x;
      _gyroOffset.y = 0.0 - _gyroOffset.y;
      _gyroOffset.z = 0.0 - _gyroOffset.z;

      saveOffset();
    }

    // Offset - Werte aus dem EEPROM laden
    // Wenn noch keine Werte vorhanden sind, wird automatisch eine
    // Kalibrierung durchgeführt
    void loadOffset() {
      int signature;
      int address = 0;
      EEPROM.get(address,signature);
      address += sizeof(signature);
      if (signature != EEPROM_SIGNATURE) {
        // Keine gültigen Werte, Kalibrierung durchführen
        calibrate();
      } else {
        // Werte einlesen
        EEPROM.get(address,_accelOffset);
        address += sizeof(_accelOffset);
        EEPROM.get(address,_gyroOffset);
        PRINTLN("Offsets loaded");
      }
    }

    // Offset - Werte in das EEPROM speichern
    // Wenn noch keine Werte vorhanden sind, wird automatisch eine
    // Kalibrierung durchgeführt
    void saveOffset() {
      int address = 0;
      EEPROM.put(address,EEPROM_SIGNATURE);
      address += sizeof(EEPROM_SIGNATURE);
      EEPROM.put(address,_accelOffset);
      address += sizeof(_accelOffset);
      EEPROM.put(address,_gyroOffset);
      PRINTLN("Offsets saved");
    }

    // liest Sensorwerte aus   
    void readRaw(Measurement &measurement) {
      Wire.beginTransmission(_address); 
      Wire.write(0x3B); // Accel register
      Wire.endTransmission();
      
      // 7 Werte aus 14 Registern anfordern und warten bis sie verfügbar sind
      Wire.requestFrom(_address, 14); 
      while(Wire.available() < 14);

      // Je 2 Bytes auslesen   
      measurement.accel.x = Wire.read()<<8|Wire.read();
      measurement.accel.y = Wire.read()<<8|Wire.read();
      measurement.accel.z = Wire.read()<<8|Wire.read();
      measurement.temp = Wire.read()<<8|Wire.read(); 
      measurement.gyro.x = Wire.read()<<8|Wire.read();
      measurement.gyro.y = Wire.read()<<8|Wire.read();
      measurement.gyro.z = Wire.read()<<8|Wire.read();
    }     

    // liest die Sensorwerte aus und rechnet sie um
    void read(Measurement &measurement) {
      readRaw(measurement);

      // umrechnen
      measurement.accel.x /= _accel_sensitivity_conversion;
      measurement.accel.y /= _accel_sensitivity_conversion;
      measurement.accel.z /= _accel_sensitivity_conversion;
      measurement.gyro.x /= _gyro_sensitivity_conversion;
      measurement.gyro.y /= _gyro_sensitivity_conversion;
      measurement.gyro.z /= _gyro_sensitivity_conversion;
      measurement.temp = measurement.temp / 340 + 36.53; // Grad Celsius (gemäss Datenblatt)      
    }

    // Hier wird Roll, Pitch und Yaw berechnet
    // Das sollte in kurzen Abständen aufgerufen werden,
    // damit der Gyro richtig ausgewertet wird.
    void readValues() {
      read(_lastMeasurement);
      
      // Korrekturen mit Offset
      _lastMeasurement.accel.x += _accelOffset.x;
      _lastMeasurement.accel.y += _accelOffset.y;
      _lastMeasurement.accel.z += _accelOffset.z;
      _lastMeasurement.gyro.x += _gyroOffset.x;
      _lastMeasurement.gyro.y += _gyroOffset.y;
      _lastMeasurement.gyro.z += _gyroOffset.z;

      // Roll und Pitch von accel
      _angles.roll = deg(atan2(_lastMeasurement.accel.y, _lastMeasurement.accel.z));
      _angles.pitch = deg(-atan2(_lastMeasurement.accel.x, _lastMeasurement.accel.z));
      _angles.yaw = 0;
      
      // Roll (x), Pitch (y) und Yaw (z) aus gyro berechnen
      unsigned long currentTime = millis();
      if (!_lastMeasurementTime) {
        // Initialisierung
        _gyroValues.clear();
        _rollAngle = 0;
        _pitchAngle = 0;
      } else {
        float dt = float(currentTime - _lastMeasurementTime) / 1000.0;
        _gyroValues.x += _lastMeasurement.gyro.x * dt;
        _gyroValues.y += _lastMeasurement.gyro.y * dt;
        _gyroValues.z += _lastMeasurement.gyro.z * dt;
        _rollAngle = COPLEMENTARY_FILTER_WEIGHT * (_rollAngle + _gyroValues.x * dt) + 
                     (1 - COPLEMENTARY_FILTER_WEIGHT) * _angles.roll; 
        _pitchAngle = COPLEMENTARY_FILTER_WEIGHT * (_pitchAngle + _gyroValues.y * dt) + 
                     (1 - COPLEMENTARY_FILTER_WEIGHT) * _angles.pitch; 
        _angles.yaw = _gyroValues.z;
      }
      _lastMeasurementTime = millis();      

    }

    void getValues(Measurement &measurement) {
      measurement = _lastMeasurement;
    }

    // Die Winkel können abgefragt werden. Die Ermittlung der Daten
    // muss vorher mit readValues() durchgeführt worden sein
    // Die Werte werden in Grad zurückgegeben
    void getAngles(Angles &angles) {
      angles.roll = _angles.roll; 
      angles.pitch = _angles.pitch;
      angles.yaw = _angles.yaw;
    }

    // Umrechnungsfunktionen zwischen Bogenmass und Gradmass
    // Die Methoden sind statisch, damit man sie auch ohne Instanz verwenden kann
    static float deg(float rad) {
      return rad * 180 / M_PI; // Grad
    }
    static float rad(float deg) {
      return deg * M_PI / 180.0; // Rad
    }

    void setRegister(uint8_t reg, uint8_t value) {
      Wire.beginTransmission(_address);
      Wire.write(reg);
      Wire.write(value);
      Wire.endTransmission();
    }

  private:
    int _address;
    float _accel_sensitivity_conversion;
    float _gyro_sensitivity_conversion; 

    Measurement _lastMeasurement;
    unsigned long _lastMeasurementTime;
    Vector _accelOffset;
    Vector _gyroOffset;
    Vector _gyroValues;
    Angles _angles;
    float _rollAngle;
    float _pitchAngle;

};
