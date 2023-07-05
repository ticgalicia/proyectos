// GT_EMULE.
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
int pin2, pin3, pin4, pin5, pin6, pin7, pin8, pin9;         
int tones[] = {62, 63, 64, 65, 66, 67, 68, 72};              //Set up the notes
int Cur_tone = 0;                                            //Variable that will take the tone of the table (array).

void setup()
{
  MIDI.begin();                     
  Serial.begin(9600);               
  pinMode(2, INPUT); pinMode(3, INPUT); pinMode(4, INPUT); pinMode(5, INPUT); pinMode(6, INPUT);
  pinMode(7, INPUT); pinMode(8, INPUT); pinMode(9, INPUT);     //set button pins as input
}

void loop()
{
  pin2 = digitalRead(2); pin3 = digitalRead(3); pin4 = digitalRead(4); pin5 = digitalRead(5); pin6 = digitalRead(6); pin7 = digitalRead(7);
  pin8 = digitalRead(8); pin9 = digitalRead(9);           //link the state of button to what the arduino read

  if (pin9 == LOW)          // IF REAR BUTTON IS PRESSED --->> AND... 
  {                         // ALL PRESSED
    if (pin8 == LOW && pin7 == LOW && pin6 == LOW && pin5 == LOW && pin4 == LOW && pin3 == LOW && pin2 == LOW)
    {
    Cur_tone = tones[0];
    MIDI.sendNoteOff(0,0,1);
    MIDI.sendNoteOn(Cur_tone,127,1);
    delay(10);
    } //set note tone to ...
      if (pin8 == LOW && pin7 == LOW && pin6 == LOW && pin5 == LOW && pin4 == LOW && pin3 == LOW && pin2 == HIGH)
      {
      Cur_tone = tones[1]; 
      MIDI.sendNoteOff(0,0,1);
      MIDI.sendNoteOn(Cur_tone,127,1);
      delay(10);
      }//set note tone to ...
       if (pin8 == LOW && pin7 == LOW && pin6 == LOW && pin5 == LOW && pin4 == LOW && pin3 == HIGH && pin2 == HIGH)
       {
       Cur_tone = tones[2];
       MIDI.sendNoteOff(0,0,1);
       MIDI.sendNoteOn(Cur_tone,127,1);
       delay(10);
       }//set note tone to ...
        if (pin8 == LOW && pin7 == LOW && pin6 == LOW && pin5 == LOW && pin4 == HIGH && pin3 == HIGH && pin2 == HIGH)
        {
        Cur_tone = tones[3];
        MIDI.sendNoteOff(0,0,1);
        MIDI.sendNoteOn(Cur_tone,127,1);
        delay(10);
        }//set note tone to ...
          if (pin8 == LOW && pin7 == LOW && pin6 == LOW && pin5 == HIGH && pin4 == HIGH && pin3 == HIGH && pin2 == HIGH)
          {
          Cur_tone = tones[4];
          MIDI.sendNoteOff(0,0,1);
          MIDI.sendNoteOn(Cur_tone,127,1);
          delay(10);
          }//set note tone to ...
            if (pin8 == LOW && pin7 == LOW && pin6 == HIGH && pin5 == HIGH && pin4 == HIGH && pin3 == HIGH && pin2 == HIGH)
            {
            Cur_tone = tones[5];
            MIDI.sendNoteOff(0,0,1);
            MIDI.sendNoteOn(Cur_tone,127,1);
            delay(10);
            }//set note tone to ...
              if (pin8 == LOW && pin7 == HIGH && pin6 == HIGH && pin5 == HIGH && pin4 == HIGH && pin3 == HIGH && pin2 == HIGH)
              {
              Cur_tone = tones[6];
              MIDI.sendNoteOff(0,0,1);
              MIDI.sendNoteOn(Cur_tone,127,1);
              delay(10);
              }//set note tone to ...
                  if (pin8 == HIGH && pin7 == HIGH && pin6 == HIGH && pin5 == HIGH && pin4 == HIGH && pin3 == HIGH && pin2 == HIGH)
                  {
                  Cur_tone = tones[7];
                  MIDI.sendNoteOff(0,0,1);
                  MIDI.sendNoteOn(Cur_tone,127,1);
                  delay(10);
                  }
    
  }       
  else             // IF REAR BUTTON IS NOT PRESSED --->> AND....
  { if (pin8 == HIGH && pin7 == LOW && pin6 == HIGH && pin5 == HIGH && pin4 == HIGH && pin3 == HIGH && pin2 == HIGH)
      {
      Cur_tone = tones[8];
      MIDI.sendNoteOn(Cur_tone,127,1);
      } //set note tone to .....
    
   else
   {    MIDI.sendNoteOff(0,0,1);
   }
   }
   
delay(100);
}
 
