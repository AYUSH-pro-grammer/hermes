#include <Wire.h>

const uint8_t MPU = 0x68;

float velocityX = 0;
unsigned long lastTime;

void setup() {
  Serial.begin(115200);

  Wire.begin();  // SDA=D4, SCL=D5 on XIAO RP2040

  Wire.beginTransmission(MPU);
  Wire.write(0x6B);     
  Wire.write(0);         
  Wire.endTransmission(true);

  lastTime = millis();
}

void loop() {
  int16_t ax_raw;

  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true);

  ax_raw = Wire.read() << 8 | Wire.read();

  float ax = ax_raw / 16384.0;   // g
  ax = ax * 9.81;     // m/s²

  unsigned long now = millis();
  float dt = (now - lastTime) / 1000.0;
  lastTime = now;

  velocityX += ax * dt;

  Serial.print("Accel X: ");
  Serial.print(ax);
  Serial.print(" m/s²  ");

  Serial.print("Speed X: ");
  Serial.print(velocityX);
  Serial.println(" m/s");

  delay(20);
}