//fuente: https://forum.arduino.cc/t/any-way-to-program-to-play-multiple-tones/76632/6
//Tuve un pequeño y agradable acorde C tocando. 
//Tenga en cuenta que tuve que reproducir un tono separado de cada pin y configuré la placa de prueba como una escalera de resistencia. Reproducir el tono de un pin distorsionó el tono drásticamente.
//

#include <Tone.h>

Tone tone1;
Tone tone2;
Tone tone3;

void setup()
{
  tone1.begin(13);
  tone2.begin(12);
  tone3.begin(11);
  tone1.play(NOTE_C4);
  tone2.play(NOTE_E4);
  tone3.play(NOTE_G4);
}

void loop()
{
}
