//fuente: https://forum.arduino.cc/t/unir-dos-codigos-de-programa-y-ejecutarlos-simultaneamente-motor-y-sonido/401225/3

//MOTOR
const byte pot = A0;
unsigned int val = 0;
const byte mot = 3;

//SONIDOS
const byte pinTono = 4;
const byte delaySonido = 100; // El delay que originalmente programaste para la duración de tone.
unsigned int i = 20; // Es la variable i que se declaraba en el for
unsigned long tiempo = 0; // Guarda el momento en que se cambió la frecuencia del tono.

void setup() {
 pinMode(mot, OUTPUT);
 pinMode(pinTono, OUTPUT);
}

void loop() {
 loopMotor();
 loopSonido();
 // Para visualizar mejor como se fusionan dos programas, es mejor separar los "loop" de cada uno, en funciones.
}

void loopMotor() {
 val = analogRead(pot);
 val = map (val, 0 , 1023, 0 , 255);
 analogWrite (mot, val);
}
// No hay delay, no hay bucles/ciclos; entonces se queda igual.

void loopSonido() {
 
 if (millis() - tiempo >= delaySonido) {
   tiempo = millis();
   // For es un bucle o ciclo; entonces si se usa, no se podrá variar la velocidad del motor hasta que se salga.
   // Esta función se llama constantemente, entonces es posible usar una alternativa al for. 
   tone (pinTono, i);
   // No se puede usar delay, sino el programa se bloquea. Para eso está el if del principio.
   i += 50;
   if (i > 2400) { i = 20; }
 }
}
