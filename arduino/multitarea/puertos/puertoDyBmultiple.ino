//Este ejemplo replica la entrada del puerto D y saca las salidas al B
//Hasta 8 pulsadores pueden replicarse como salida al puerto b haciendo cientos de combinaciones posibles.
//Puede implementarse como efectos de luces (mesa de luces)

byte valorD; //variable lectura del puerto D (leemos todo a la vez)

void setup() {
    DDRD=~B11111111;  //Puerto de como INPUT ~ = negacion  y B es valor de BYTE
    DDRB=~B00000000;  //Puerto B como OUTPUT
}

void loop() {
    valorD = PIND; //Leemos todo el puerto almacenado en la variable de entorno PIND  (puerto D)
       if (valorD == B00000001) { //cuando lea esto
            PORTB=B00000000; //El puerto B coge el valor especificado
        }
       if (valorD == B00000010) { //cuando lea esto
            PORTB=B00000010; //El puerto B coge el valor especificado
        }
       if (valorD == B00000011) { //cuando lea esto
            PORTB=B00000011; //El puerto B coge el valor especificado
        }
       if (valorD == B00000100) { //cuando lea esto
            PORTB=B00100100; //El puerto B coge el valor especificado
        }
       if (valorD == B00001000) { //cuando lea esto
            PORTB=B00010010; //El puerto B coge el valor especificado
        }
       if (valorD == B00010000) { //cuando lea esto
            PORTB=B01011010; //El puerto B coge el valor especificado
        }
       if (valorD == B00100000) { //cuando lea esto
            PORTB=B11011010; //El puerto B coge el valor especificado
        }
       if (valorD == B01000000) { //cuando lea esto
            PORTB=B11011010; //El puerto B coge el valor especificado
        }
       if (valorD == B10000000) { //cuando lea esto
            PORTB=B11111111; //El puerto B coge el valor especificado
        }

}
