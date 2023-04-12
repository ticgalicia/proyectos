//https://www.youtube.com/watch?v=bplxlbh1OMw

#include <CapacitiveSensor.h>

CapacitiveSensor   sens1 = CapacitiveSensor(8,6);
CapacitiveSensor   sens2 = CapacitiveSensor(4,2);

void setup() {
  
  sens1.set_CS_AutocaL_Millis(0xFFFFFFFF);
  sens2.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(115200);
}

bool clickz = false;
bool clickx = false;

void loop() {

    long totalz =  sens1.capacitiveSensor(20);
    long totalx =  sens2.capacitiveSensor(20);
    
    if(totalz > 1000 && !clickz) {
      Serial.println("zp");
      clickz = true;
    }

    if(totalx > 1000 && !clickx) {
      Serial.println("xp");
      clickx = true;
    }
    
    if (totalz <= 1000 && clickz) {
      clickz = false;
      Serial.println("zr");
    }
    
    if (totalx <= 1000 && clickx) {
      clickx = false;
      Serial.println("xr");
    }
}
