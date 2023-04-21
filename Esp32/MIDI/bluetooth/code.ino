//fuente: https://www.youtube.com/watch?v=oJEJICLnl2M
/* Código hecho por: Daniel Marcial (@danielmarcial22) */


const int nBotones = 3; //este es el número de botones
const int calibracion=130; //este valor funciona como una especie delay (es el numero de loops minimo de espera que debe haber entre cada repetición de nota)
boolean notaioff[nBotones];
int contador[nBotones];
//el array notas[] debe tener un mismo número de elementos
//que el número de botones, pues cada nota corresponde a un botón
byte notas[] = {60,63,67}; //estás son las notas que se dispararán los botones
byte botones[] = {23,22,21}; //aqui se ponen los GPIO de cada boton, el numero de elementos debe ser nBotones


const int nPots=2; //número de potenciómetros
// RECUERDA USAR GPIOS QUE TENGAN ADC1 SOLAMENTE, ya que el ADC2 de ESP32 no puede ser usado con Wifi o Bluetooth
byte analogs[] = {39,32} ; //son los GPIO que se usaran como entradas analógicas, se debe revisar que el GPIO sea un canal de ADC en el ESP32

int lecturas[nPots]; 
int lecturasAnteriores[nPots];

bool hayip=false;

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;

void setup() {


  Serial.begin(115200);
  SerialBT.begin("MIDI-blue"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");  
  
  for (int i=0;i<nBotones;i++)
  {
   pinMode(botones[i], INPUT_PULLUP);
  }
  analogReadResolution(10);
  
}

void midi(unsigned char command, unsigned char note,unsigned char vel)
{
    SerialBT.write(command);
    SerialBT.write(note);
    SerialBT.write(vel);
}


void loop() {
  

    
  
  for (int i=0; i<nBotones; i++) //la variable i recorre los números del 2 al 6
  {
      if (digitalRead(botones[i]) == LOW) //botón presionado
      {
        if (contador[i]==0)//cuenta regresiva terminada ?
        {
          if (notaioff[i]== 1) //¿la nota esta apagada?
          {
            contador[i]=calibracion; //valor de cuenta regresiva 
            midi(144,notas[i],100); //se envía la nota
            notaioff[i] = 0; //la nota no esta apagada (esta encendida)
          }
        }
        
      }
      else //botón sin presionar (posible envio de Note Off)
      {
        if (contador[i]==0) //cuenta regresiva terminada ?
        {
          if (notaioff[i] ==0) //¿La nota esta esta activada?
          {
            contador[i]=calibracion; //valor de cuenta regresiva 
            midi(144,notas[i],0); //envio de note off
            notaioff[i] = 1;  //la nota ya no está encendida
          }
        }
      }
  }

  
for (int i=0; i<nBotones;i++)
{
if (contador[i]>0) contador[i]--;
}

for (int k=0; k<nPots; k++) //se hace un recorrido desde k=0 hasta que k sea menor a nPots
{
  int lec = analogRead(analogs[k]);
  lecturas[k] = map(lec,0,1023,0,255); //mapeamos al rango al doble del CC
}

for (int k=0; k<nPots;k++)
{    //vemos si hubo un cambio en el valor de los potenciometros
      if (lecturas[k] > (lecturasAnteriores[k]+1) || lecturas[k] < (lecturasAnteriores[k]-1) )
      {                   
          midi(176,k+30,lecturas[k]/2); //mándamos a partir del CC 30
          lecturasAnteriores[k] = lecturas[k];
      } 
}
delay(1); //para estabilidad
}
