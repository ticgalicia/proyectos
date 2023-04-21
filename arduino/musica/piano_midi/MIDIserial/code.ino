// Fuente: https://www.youtube.com/watch?v=pIFoOQJEFZ0

//Número de entradas
#include <MIDIUSB.h>
#define numeroDeEntradas 16// Este número corresponde a las entradas que se quiere obtener, funciona en múltiplos de 8, dependiendo que cantidad de
//integrados se esté usando, en el vídeo muestro dos integrados, usando doce entradas digitales, por lo que pongo 16 entradas, si usas mas entradas 
//por ejemplo 3 integrados pues colocas 3*8 = 24.

// Tiempo de espera para repetir loop
#define delayDelCodigo 100
//ancho de pulso
#define anchoDePulso  5

 int clockPin        = 5; // Clock pin del 74hc 165
int pinCargarDatos  = 6;  // Pin carga en paralelo del 74hc165
int pinDato         = 4; // QH Pin salida serie del 74hc165
boolean estadoPasado[numeroDeEntradas];
 
// Mostrar la lista de datos con su estado
 
void setup()
{
    Serial.begin(9600);
 
    // Inicializar los pines digitales
    pinMode(pinCargarDatos, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(pinDato, INPUT);
    digitalWrite(clockPin, LOW); // inicializa reloj en BAJO
    digitalWrite(pinCargarDatos, LOW); // inicializa carga datos a BAJO
    for(int i=0;i< numeroDeEntradas;i++){
      estadoPasado[i]=LOW;
    }
}
 
void loop()
{
    // Lee el estado de todos los bytes
    // Pulso de carga paralela para guardar el estado de las entradas
    digitalWrite(pinCargarDatos, LOW);  // Configuración Básica para leer bits.
    delayMicroseconds(anchoDePulso);     // duracion del pulso
    digitalWrite(pinCargarDatos, HIGH);

    boolean byt[numeroDeEntradas]; // Este es el arreglo del tipo booleano donde se guardarán el valor de las entradas

    //Ciclo para leer el valor de cada entrada.
    for(int i = 0; i < numeroDeEntradas; i++)// leer entradas del 75hc165
    {
        //valorBit = digitalRead(pinDato);
        //valorBytes |= (valorBit << ((numeroDeEntradas-1) - i));
        byt[numeroDeEntradas-1-i]= digitalRead(pinDato);
        /// yea 
        digitalWrite(clockPin, HIGH);
        delayMicroseconds(anchoDePulso);
        digitalWrite(clockPin, LOW);
    }

    // En este punto ya se tienen todos los valores de las entradas en el arreglo, por lo que si quieres usar por ejemplo el valor
    // de la entrada "a" del primer integrado, puedes encontrar dicho valor en byt[0], si es el "c" se encuentra como byt[2],
    // Si por ejemplo quieres averiguar el valor de la entrada c del segundo transistor, la puedes encontrar como byt[10] y así
    // sucesivamente. Recuerda que el orden es  a b c d e f g h , a2 b2 c2 d2 e2 f2 g2 h2, en numeros pues del 0 al 15.
    // La misma lógica para mas integrados.  
    Serial.println("Numero de entradas:");
    for(int i = 0; i< numeroDeEntradas; i++){
      
      //Serial.print(byt[i]);
      if(byt[i]==1){
        Serial.print("Botón ");
        Serial.print(i);
        Serial.println(" presionado.");
      }
    }

    for(int i=0; i< numeroDeEntradas;i++){
      if(byt[i]==HIGH &&  estadoPasado[i]==LOW){
        noteOn(0, 48+i,64);
        MidiUSB.flush();
        estadoPasado[i]= byt[i];
      }
      if(byt[i]==LOW && estadoPasado[i]==HIGH){
        noteOff(0, 48+i,64);
        MidiUSB.flush();
        estadoPasado[i]=byt[i];
      }
    }
    

}
void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}
