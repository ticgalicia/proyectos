//fuente: https://forum.arduino.cc/t/hacer-dos-cosas-simultaneas/248040/4
//El siguiente ejemplo hace dos cosas simultaneas usando la función millis().

//1 - led 12 parpadea cada 5 segundos
//2 -led 13 parpadea cada segundo.

// Parametros del pin 12 
const int pinLed12 = 12;
long intervalo1 = 5000;
long timer1 = millis();
int estadoPin12 = LOW;

// Parametros del pin 13  
const int pinLed13 = 13;
long intervalo2 = 1000;
long timer2 = millis();
int estadoPin13 = LOW;

void setup() {
  pinMode(pinLed12, OUTPUT); //pin 12 como salida
  pinMode(pinLed13, OUTPUT); //pin 13 como salida
}

void loop() {
  
  if ( (millis() - timer1) > intervalo1){
    parpadeo_12(); //invoca rutina de parpadeo pin 12
  }
  if ( (millis() - timer2) > intervalo2){
    parpadeo_13(); //invoca rutina de parpadeo pin 13
  }
}

void parpadeo_12(){ //rutina de parpadeo pin 12
  if (estadoPin12 == LOW)
      estadoPin12 = HIGH;
    else
      estadoPin12 = LOW;
    digitalWrite(pinLed12, estadoPin12);
    timer1 = millis();
}

void parpadeo_13(){ //rutina de parpadeo pin 13
  if (estadoPin13 == LOW)
      estadoPin13 = HIGH;
    else
      estadoPin13 = LOW;
    digitalWrite(pinLed13, estadoPin13);
    timer2 = millis();
}
