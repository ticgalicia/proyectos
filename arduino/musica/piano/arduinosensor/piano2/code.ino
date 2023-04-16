#include <CapacitiveSensor.h>


#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880

int altavoz = 11;

CapacitiveSensor   ca = CapacitiveSensor(8,2);
CapacitiveSensor   cf = CapacitiveSensor(8,3);
CapacitiveSensor   cch = CapacitiveSensor(8,4);
CapacitiveSensor   ceh = CapacitiveSensor(8,5);
CapacitiveSensor   cfh = CapacitiveSensor(8,6);
CapacitiveSensor   cgs = CapacitiveSensor(8,7);

void setup()
{
pinMode(altavoz, OUTPUT);

}

void loop()
{

long ba = ca.capacitiveSensor(30);
long bf = cf.capacitiveSensor(30);
long bch = cch.capacitiveSensor(30);
long beh = ceh.capacitiveSensor(30);
long bfh = cfh.capacitiveSensor(30);
long bgs = cgs.capacitiveSensor(30);

if(ba > 10)
tone(altavoz, a, 10);
else if(bf > 10)
tone(altavoz, f, 10);
else if(bch > 10)
tone(altavoz, cH, 10);
else if(beh > 10)
tone(altavoz, eH, 10);
else if(bfh > 10)
tone(altavoz, fH, 10);
else if(bgs > 10)
tone(altavoz, gS, 10);

delay(10);
}
