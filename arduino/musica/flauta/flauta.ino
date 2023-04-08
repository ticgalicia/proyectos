//fuente: https://interorganic.com.ar/josx/Flauta.pdf

void setup()
{
  pinMode( 10 , INPUT);
  pinMode( 3 , INPUT);
  pinMode( 9 , INPUT);
  pinMode( 8 , INPUT);
  pinMode( 7 , INPUT);
  pinMode( 6 , INPUT);
  pinMode( 5 , INPUT);
  pinMode( 4 , INPUT);
}

void loop()
{
  if (( digitalRead( 10 ) && ( digitalRead( 3 ) && !( ( digitalRead( 10 ) && ( digitalRead( 9 ) && digitalRead( 3 ) ) ) ) ) ))
  {
    tone(11, 524.0, 100.0);
  }
  else
  {
    noTone(10);
    noTone(3);
  }
  if (( digitalRead( 9 ) && ( digitalRead( 10 ) && ( digitalRead( 3 ) && !( ( digitalRead( 9 ) && ( digitalRead( 10 ) && ( digitalRead( 8 ) && digitalRead( 3 ) ) ) ) ) ) ) ))
  {
    tone(11, 494.0, 100.0);
  }
  if (( digitalRead( 8 ) && ( digitalRead( 9 ) && ( digitalRead( 10 ) && ( digitalRead( 3 ) && !( ( digitalRead( 8 ) && ( digitalRead( 9 ) && ( digitalRead( 10 ) && ( digitalRead( 3 ) && digitalRead( 7 ) ) ) ) ) ) ) ) ) ))
  {
    tone(11, 440.0, 100.0);
  }
  if (( digitalRead( 7 ) && ( digitalRead( 9 ) && ( digitalRead( 10 ) && ( digitalRead( 3 ) && ( digitalRead( 8 ) && !( ( digitalRead( 7 ) && ( digitalRead( 9 ) && ( digitalRead( 10 ) && ( digitalRead( 3 ) && ( digitalRead( 8 ) && digitalRead( 6 ) ) ) ) ) ) ) ) ) ) ) ))
  {
    tone(11, 392.0, 100.0);
  }
  if (( digitalRead( 6 ) && ( digitalRead( 9 ) && ( digitalRead( 10 ) && ( digitalRead( 3 ) && ( digitalRead( 8 ) && ( digitalRead( 7 ) && !( ( digitalRead( 6 ) && ( digitalRead( 9 ) && ( digitalRead( 10 ) && ( digitalRead( 3 ) && ( digitalRead( 8 ) && ( digitalRead( 7 ) && digitalRead( 5 ) ) ) ) ) ) ) ) ) ) ) ) ) ))
  {
    tone(11, 349.0, 100.0);
  }
  if (( digitalRead( 6 ) && ( digitalRead( 9 ) && ( digitalRead( 10 ) && ( digitalRead( 3 ) && ( digitalRead( 8 ) && ( digitalRead( 7 ) && ( digitalRead( 5 ) && !( ( digitalRead( 9 ) && ( digitalRead( 10 ) && ( digitalRead( 3 ) && ( digitalRead( 8 ) && ( digitalRead( 7 ) && ( digitalRead( 5 ) && ( digitalRead( 4 ) && digitalRead( 6 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ))
  {
    tone(11, 330.0, 100.0);
  }
  if (( digitalRead( 9 ) && ( digitalRead( 10 ) && ( digitalRead( 4 ) && ( digitalRead( 8 ) && ( digitalRead( 7 ) && ( digitalRead( 5 ) && ( digitalRead( 6 ) && !( ( digitalRead( 9 ) && ( digitalRead( 10 ) && ( digitalRead( 3 ) && ( digitalRead( 8 ) && ( digitalRead( 7 ) && ( digitalRead( 5 ) && ( digitalRead( 4 ) && digitalRead( 6 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ))
  {
    tone(11, 294.0, 100.0);
  }
  if (( digitalRead( 10 ) && ( digitalRead( 3 ) && ( digitalRead( 8 ) && ( digitalRead( 7 ) && ( digitalRead( 5 ) && ( digitalRead( 4 ) && ( digitalRead( 6 ) && digitalRead( 9 ) ) ) ) ) ) ) ))
  {
    tone(11, 262.0, 100.0);
  }
}
