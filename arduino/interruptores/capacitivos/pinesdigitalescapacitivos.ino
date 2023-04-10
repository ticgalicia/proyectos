//Fuente: https://www.rinconingenieril.es/sensor-capacitivo/
#include <CapacitiveSensor.h>
//Crear e indicar pines del sensor
//4 -> Sender 3 -> Receiver
CapacitiveSensor   sensor = CapacitiveSensor(4,3);
void setup()
{
//Pin 12 (led) como salida
pinMode(13,OUTPUT);
}
void loop()
{
//Almacenar lectura del sensor en una variable
long lectura =  sensor.capacitiveSensor(30);
//Comparar lectura
if(lectura > 1)
digitalWrite(13,HIGH);
else
digitalWrite(13,LOW);
delay(10);
}
