//Este ejemplo replica la entrada del puerto D y saca las salidas al B
//Hasta 8 pulsadores pueden replicarse como salida al puerto b

byte valorD; //variable lectura del puerto D (leemos todo a la vez)

void setup() {
    DDRD=~B11111111;  //Puerto de como INPUT ~ = negacion  y B es valor de BYTE
    DDRB=~B00000000;  //Puerto B como OUTPUT
}

void loop() {
    valorD = PIND; //Leemos todo el puerto almacenado en la variable de entorno PIND  (puerto D)
    PORTB=valorD; //El puerto B coge el valor de D PORT (el puerto entero vale el valor de valorD)
}
