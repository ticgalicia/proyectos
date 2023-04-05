// Written by Brett Hagman - bhagman@wiring.org.co
// Dual Tone Example for the Arduino/Wiring Tone Library

#include <Tone.h>

#define REST -1

Tone MTone;
Tone HTone;

int16_t melody[][2] =
{
  { NOTE_B3,  150  },
  { REST,     150  },
  { NOTE_A4,  150  },
  { REST,     150  },
  { NOTE_GS4, 1200 },
  { REST,     120  },
  { NOTE_G4,  150  },
  { NOTE_FS4, 120  },
  { NOTE_F4,  120  },
  { NOTE_E4,  150  },
  { REST,     150  },
  { NOTE_GS3, 150  },
  { REST,     150  },
  { NOTE_E4,  250  },
  { NOTE_B3,  320  },
  { REST,     700  },
  { NOTE_B3,  150  },
  { REST,     150  },
  { NOTE_A4,  150  },
  { REST,     150  },
  { NOTE_GS4, 1200 },
  { REST,     120  },
  { NOTE_G4,  150  },
  { NOTE_FS4, 120  },
  { NOTE_F4,  120  },
  { NOTE_E4,  150  },
  { REST,     150  },
  { NOTE_GS3, 150  },
  { REST,     150  },
  { NOTE_E4,  250  },
  { NOTE_B3,  320  },
  { REST,     700  }
};


int16_t harmony[][2] =
{
  { NOTE_B3,  150  },
  { REST,     150  },
  { NOTE_A4,  150  },
  { REST,     150  },
  { NOTE_GS4, 1200 },
  { REST,     120  },
  { NOTE_G4,  150  },
  { NOTE_FS4, 120  },
  { NOTE_F4,  120  },
  { NOTE_E4,  150  },
  { REST,     150  },
  { NOTE_GS3, 150  },
  { REST,     150  },
  { NOTE_E4,  250  },
  { NOTE_B3,  320  },
  { REST,     700  },
  { NOTE_B3,  150  },
  { REST,     150  },
  { NOTE_A4,  150  },
  { REST,     150  },
  { NOTE_GS4, 1200 },
  { REST,     120  },
  { NOTE_G4,  150  },
  { NOTE_FS4, 120  },
  { NOTE_F4,  120  },
  { NOTE_E4,  150  },
  { REST,     150  },
  { NOTE_GS3, 150  },
  { REST,     150  },
  { NOTE_E4,  250  },
  { NOTE_B3,  320  },
  { REST,     700  }
};

int mrows;
int hrows;


void setup()
{
  MTone.begin(13);
  HTone.begin(12);

  Serial.begin(9600);
  Serial.println(F("Dual Tone Test 1"));

  // Calculate the number of rows in our arrays
  mrows = sizeof(melody) / sizeof(melody[0]);
  hrows = sizeof(harmony) / sizeof(harmony[0]);
}


// Just a simple debug serial output function.
void printNote(const char *channel, int note, int duration)
{
  Serial.print(channel);
  Serial.print(' ');
  if (note > 0)
    Serial.print(note, DEC);
  else
    Serial.print(F("Rest"));
  Serial.print(' ');
  Serial.println(duration, DEC);
}


void loop()
{
  static int mi = 0;
  static int hi = 0;
  // Time To Next Melody Note
  static int ttnmn = 0;
  // Time To Next Harmony Note
  static int ttnhn = 0;

  int mdur;
  int hdur;

  // If we have more notes to play in the melody, and we're ready to play on this channel
  if (mi < mrows && ttnmn <= 0)
  {
    mdur = melody[mi][1];

    // If it is a note, play it.
    if (melody[mi][0] > 0)
    {
      MTone.play(melody[mi][0], mdur);
    }
    // Otherwise, it's a rest - do nothing

    printNote("Melody", melody[mi][0], mdur);

    // Get ready to play the next note.
    mi++;
    ttnmn = mdur;
  }

  // If we have more notes to play in the harmony, and we're ready to play on this channel
  if (hi < hrows && ttnhn <= 0)
  {
    hdur = harmony[hi][1];

    // If it is a note, play it.
    if (harmony[hi][0] > 0)
    {
      HTone.play(harmony[hi][0], hdur);
    }
    // Otherwise, it's a rest - do nothing
    
    printNote("Harmony", harmony[hi][0], hdur);

    // Get ready to play the next note.
    hi++;
    ttnhn = hdur;
  }

  // If we've run out of notes to play on both channels
  if (mi >= mrows && hi >= hrows)
  {
    // Last tone(s)/rest(s) is/are playing, but we're done

    Serial.println(F("Done!"));
    for (;;);
  }

  // This is here to aid the min() selection below
  // i.e. when either channel has finished, consider the next note much further away than the other.
  if (mi >= mrows)
    ttnmn = 32000;
  if (hi >= hrows)
    ttnhn = 32000;

  // Find out how much time we need until the next note on either channel.
  int dtime = min(ttnmn, ttnhn);

  if (dtime > 0)
  {
    delay(dtime);
    ttnmn -= dtime;
    ttnhn -= dtime;
  }
}
