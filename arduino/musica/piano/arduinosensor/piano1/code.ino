//fuente: https://www.youtube.com/watch?v=BGoQZt4qBNc
//sin terminar.

#include <CapacitiveSensor.h>

CapacitiveSensor a= CapacitiveSensor (2,3);
CapacitiveSensor b= CapacitiveSensor (4,5);
CapacitiveSensor c= CapacitiveSensor (6,7);
CapacitiveSensor d= CapacitiveSensor (8,9);
CapacitiveSensor e= CapacitiveSensor (10,7);
CapacitiveSensor f= CapacitiveSensor (8,9);
CapacitiveSensor g= CapacitiveSensor (8,10);
CapacitiveSensor h= CapacitiveSensor (8,11);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  long SEN1 = a.capacitiveSensorRaw(30);
  long SEN2 = b.capacitiveSensorRaw(30);
  long SEN3 = c.capacitiveSensorRaw(30);
  long SEN4 = d.capacitiveSensorRaw(30);
  long SEN5 = e.capacitiveSensorRaw(30);
  long SEN6 = f.capacitiveSensorRaw(30);
  long SEN7 = g.capacitiveSensorRaw(30);
  long SEN8 = h.capacitiveSensorRaw(30);

  Serial.print(SEN1);
  Serial.print("/r");

  if (SEN1 >10) { tone(A4,262,100); }
  if (SEN2 >10) { tone(A4,282,100); }
  if (SEN3 >10) { tone(A4,362,100); }
  if (SEN4 >10) { tone(A4,462,100); }
  if (SEN5 >10) { tone(A4,562,100); }
  if (SEN6 >10) { tone(A4,662,100); }
  if (SEN7 >10) { tone(A4,762,100); }
  if (SEN8 >10) { tone(A4,262,100); }

}
