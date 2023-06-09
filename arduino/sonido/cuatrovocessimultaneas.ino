//fuente: https://stackoverflow.com/questions/28976608/arduino-how-to-create-two-or-more-tones-simultaneously-on-a-piezo-buzzer
#define PIN 9

/* these magic constants were generated by the following perl script:
   #!/usr/bin/perl -lw
   my $freq = 16000000/256;
   my $A4 = 440;
   print int(128*$freq/$A4*exp(-log(2)*$_/12)) for (-9..2);
*/
const uint16_t frtab[] = {
  30578, 28861, 27241, 25712,
  24269, 22907, 21621, 20408,
  19262, 18181, 17161, 16198
};

#define VOICES 4

struct voice { 
  uint16_t freq;
  int16_t frac;
  uint8_t octave;
  uint8_t off;
  int8_t vol;
  const uint8_t *waveform;
} voice[VOICES];

#define PITCH 50 /* global pitch adjustment */

/* some waveforms. 16 samples each */
const uint8_t square_50[] = {
  0, 0, 0, 0, 0, 0, 0, 0,15,15,15,15,15,15,15,15
};
const uint8_t square_25[] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,15,15,15,15
};
const uint8_t square_12[] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,15,15
};
const uint8_t square_6[] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,15
};
const uint8_t sawtooth[] = {
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15
};
const uint8_t triangle[] = {
  0, 2, 4, 6, 8,10,12,14,15,13,11, 9, 7, 5, 3, 1
};
const uint8_t nicebass[] = {
  0, 8,14,18,22,23,24,25,26,25,24,23,22,18,14, 8
};

void setup() {
  /* TIMER0 is used by the Arduino environment for millis() etc.
   So we use TIMER1.
 */
  pinMode(PIN, OUTPUT);
  /* fast PWM, no prescaler */
  TCCR1A = 0x80;
  TCCR1B = 0x11;
  /* 7-bit precision => 125kHz PWM frequency */
  ICR1H = 0;
  ICR1L = 0x7f;
  /* enable interrupts on TIMER1 overflow */
  TIMSK1 = 1;
  OCR1AH = 0; /* hi-byte is unused */
  for (uint8_t i=0; i<VOICES; i++)
    clear_voice(i);
}

void set_voice(uint8_t v, uint8_t note, uint8_t volume, const uint8_t *waveform) {
  note += PITCH;
  voice[v].octave = note/12;
  voice[v].freq = frtab[note%12];
  voice[v].frac = 0;
  voice[v].off = 0;
  voice[v].waveform = waveform;
  voice[v].vol = volume;
}

void clear_voice (uint8_t v) {
  voice[v].freq = 0;
}

uint8_t s = 0;

ISR(TIMER1_OVF_vect) {
  /* Calculate new data every 4 pulses, i.e. at 125/4 = 31.25kHz.
     Being interrupted unnecessarily is kinda wasteful, but using another timer is messy.
  */
  if (s++ & 3)
    return;

  int8_t i;
  int8_t out = 0;
  for (i=0; i<VOICES; i++) {
    if (voice[i].freq) {
      voice[i].frac -= 128<<voice[i].octave;
      if (voice[i].frac < 0) { /* overflow */
        voice[i].frac += voice[i].freq;
        voice[i].off++;
      }
      /* warning: vol isn't a real volume control, only for square waves */
       out += (voice[i].waveform[voice[i].off & 15]) & voice[i].vol;
    }
  }

  /* out is in the range 0..127. With 4-bit samples this gives us headroom for 8 voices.
     Or we could use more than 4-bit samples (see nicebass).
   */
  OCR1AL = out;
}

/* tune data */
const uint8_t bass[8][4] = {
  { 12, 19, 23, 24 },
  {  5, 12, 19, 21 },
  { 12, 19, 23, 24 },
  {  5, 12, 19, 21 },
  { 14, 16, 17, 21 },
  {  7, 19, 14, 19 },
  { 14, 16, 17, 21 },
  {  7, 19, 14, 19 }
};

const uint8_t melody[2][8][16] = {
  {/* first voice */
    {31, 0, 0, 0, 0, 1, 2, 3,31,29,28,29, 0,28,26,24 },
    { 0, 0, 0, 0, 0, 1, 2, 3,53,54,53,54, 0, 1, 2, 3 },
    {31, 0, 0, 0, 0, 1, 2, 3,31,29,28,29, 5,28, 5,26 },
    { 5,28,24, 0, 0, 1, 2, 3,53,54,56,54, 0, 1, 2, 3 },

    {29, 0, 0, 0, 0, 1, 2, 3,31,29,28,29, 5, 0,28, 5 },
    {28, 5, 0,26, 0, 1, 2, 3,54,56,58,56, 0, 1, 2, 3 },
    {29, 0, 0, 0, 0, 1, 2, 3,31,29,28,29, 5, 0,28, 5 },
    {28, 5, 0,26, 0, 1, 2, 3, 0,19,21,23,24,26,28,29 },
  },

  {/* second voice */
    {24, 0, 0, 0, 0, 1, 2, 3,24,24,24,24, 0,24,24,21 },
    { 0, 0, 0, 0, 0, 1, 2, 3,49,51,49,51, 0, 1, 2, 3 },
    {24, 0, 0, 0, 0, 1, 2, 3,24,24,24,24, 5,24, 5,24 },
    { 5,23,21, 0, 0, 1, 2, 3,49,51,53,51, 0, 1, 2, 3 },

    {26, 0, 0, 0, 0, 1, 2, 3,24,26,24,24, 5, 0,24, 5 },
    {24, 5, 0,24, 0, 0, 0, 0,51,51,54,54, 0, 1, 2, 3 },
    {26, 0, 0, 0, 0, 1, 2, 3,24,26,24,24, 5, 0,24, 5 },
    {24, 5, 0,23, 0, 1, 2, 3, 0, 5, 0,19,21,23,24,26 },  
  }
};

void loop() {
  uint8_t pos, i, j;

  for (pos=0; pos<8; pos++) {
    for (i=0; i<16; i++) {
      /* melody: voices 0 and 1 */
      for (j=0; j<=1; j++) {
        uint8_t m = melody[j][pos][i];
        if (m>10) {
           /* new note */
           if (m > 40) /* hack: new note, keep volume */
             set_voice(j, m-30, voice[j].vol, square_50);
           else /* new note, full volume */
             set_voice(j, m, 15, square_50);
        } else {
          voice[j].vol--; /* fade existing note */
          switch(m) { /* apply effect */
            case 1: voice[j].waveform = square_25; break;
            case 2: voice[j].waveform = square_12; break;
            case 3: voice[j].waveform = square_6; break;
            case 4: clear_voice(j); break; /* unused */
            case 5: voice[j].vol -= 8; break;
          }
          if (voice[j].vol < 0)
            voice[j].vol = 0; /* just in case */
        }
      }

      /* bass: voices 2 and 3 */
      set_voice(2, bass[pos][i%4], 31, nicebass);
      set_voice(3, bass[pos][0]-12, 15-i, sawtooth);

      delay(120); /* time per event */
    }
  }
}
