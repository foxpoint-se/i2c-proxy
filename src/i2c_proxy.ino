#include <Wire.h>
#include "MS5837.h"

#define BYTE_SIZE 4 


MS5837 depthSensor;

unsigned int SEND_FREQ_MS = 200;
unsigned long LAST_PUBLISH = 0;

void setup() {
  const int FRESH_WATER = 997;

  Serial1.begin(9600);
  Wire.begin();

  depthSensor.init();
  depthSensor.setModel(MS5837::MS5837_02BA);
  depthSensor.setFluidDensity(FRESH_WATER);
  delay(3000);
}

void loop(){
  unsigned long now = millis();

  if ((now - LAST_PUBLISH) >= SEND_FREQ_MS) {
      depthSensor.read();
      
      float depth = depthSensor.depth();
      byte * b = (byte *) &depth;
  
      Serial1.write(b, BYTE_SIZE);

      LAST_PUBLISH = now;
  }
}
