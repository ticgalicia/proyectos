//Fuente: http://ixora.io/itp/pcomp/experiments-with-sound/
//fUENTE: https://youtu.be/lsEIqzg-ypA

const int FREQ0 = 523;
const int FREQ1 = 1046;
void setup() {
  // configurar pines de entrada/salida...

  // calcular el número de microsegundos entre cambios ALTO/BAJO en la forma de onda
  pause0 = 1000000 / (2 * FREQ0);
  pause1 = 1000000 / (2 * FREQ1);
}

void loop() {
  unsigned long t = micros();

  // avanzar a la próxima vez que tenemos que voltear un poco
  int pause = min(pause0 - t % pause0, pause1 - t % pause1);
  delayMicroseconds(pause);
  t += pause;

  // si se presiona un botón, determine si su onda es ALTA o BAJA en función de un
  // número par o impar de retrasos de pausa transcurridos
  bool wave0 = button0 && (t / pause0 % 2);
  bool wave1 = button1 && (t / pause1 % 2);

  // establece el pin digital 0 en ALTO si uno de wave0 o wave1 es ALTO
  // establece el pin digital 1 en ALTO si tanto wave0 como wave1 son ALTOS
  // Nota: ALTO == verdadero
  // Nota: los pines digitales 0 y 1 nunca se configuran en ALTO al mismo tiempo, pero podrían hacerlo.
  digitalWrite(SPEAKER_PIN_0, wave0 ^ wave1);
  digitalWrite(SPEAKER_PIN_1, wave0 & wave1);

  // lee los pines de ambos botones y compara los valores con ALTO para ver si están siendo presionados
  button0 = digitalRead(BUTTON_PIN_0) == HIGH;
  button1 = digitalRead(BUTTON_PIN_1) == HIGH;
}
