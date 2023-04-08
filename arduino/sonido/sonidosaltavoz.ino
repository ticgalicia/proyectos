int buzzerPin = 9; // pin para el altavoz (conecto en serie una resistencia superior a 150 ohmios para proteger la salida de Arduino)

void setup()
{
  pinMode(buzzerPin, OUTPUT); //inicializo el pin del altavoz para que sea salida
  analogWrite(buzzerPin, 0); //lo mismo con el pin del altavoz
}

void loop()
{
  tone(buzzerPin, 261, 200); //envío un tono al pin del altavoz con frecuencia 261 (do) y duración 200 milisegundos. 
   delay(300); //espero 300 milisegundos desde que empezó el comnado anterior (por eso la espera es de 100 hasta el siguiente tono)
  tone(buzzerPin, 261, 200);
   delay(300);
  tone(buzzerPin, 293, 400);
  delay(500);
  tone(buzzerPin, 261, 300);
   delay(400);
  tone(buzzerPin, 349, 300);
   delay(400);
  tone(buzzerPin, 329, 400);
  delay(3000);
}
