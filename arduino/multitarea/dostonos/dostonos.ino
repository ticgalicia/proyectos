//Fuente: https://forum.arduino.cc/t/arduino-tone-library-playing-multiple-tones-simultaneouly/513566

/*
* Dual Tones - Simultaneous tone generation.
* plays notes 'a' through 'g' sent over the Serial Monitor.
* lowercase letters for the first tone and uppercase for the second.
* 's' stops the current playing tone.
*/
#include <Tone.h>
int notes[] = { NOTE_A3,
                NOTE_B3,
                NOTE_C4,
                NOTE_D4,
                NOTE_E4,
                NOTE_F4,
                NOTE_G4 };
// You can declare the tones as an array
Tone notePlayer[4];

void setup(void)
  {
    Serial.begin(9600);
    notePlayer[0].begin(43);
    notePlayer[1].begin(45);
    notePlayer[2].begin(47);
    notePlayer[3].begin(49);
  
  }
void loop(void)
{
  char c;
  if(Serial.available())
    {
    c = Serial.read();
      switch(c)
      {
        case 'a'...'g':
          notePlayer[0].play(notes[c - 'a']);
          Serial.println(notes[c - 'a']);
          break;
        case 's':
          notePlayer[0].stop();
          break;
        case 'A'...'G':
          notePlayer[1].play(notes[c - 'A']);
          Serial.println(notes[c - 'A']);
          break;
        case 'S':
          notePlayer[1].stop();
          break;
        case 'p':
          notePlayer[2].play(notes[0]);
          Serial.println(notes[0]);
          break;
        case 'q':
          notePlayer[2].stop();
          break;

          case 'x':
          notePlayer[3].play(notes[0]);
          Serial.println(notes[0]);
          break;
        case 'y':
          notePlayer[3].stop();
          break;
    , 
        }
    }
}
