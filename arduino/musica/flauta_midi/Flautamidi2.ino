// Fuente: https://forum.arduino.cc/t/flauta-digital/502341
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
//int b2 = 2; int b3 = 3; int b4 = 4; int b5 = 5; int b6 = 6; int b7 = 7; int b8 = 8; int b12 = 12; //set up all the variable for the pins
int pin2 = 0; 
int pin3 = 0; 
int pin4 = 0; 
int pin5 = 0; 
int pin6 = 0; 
int pin7 = 0; 
int pin8 = 0; 
int pin12 = 0;//initialize all state of button to 0 just incase

//NOTES         'c',   'd',   'e',  'f'  'g', 'a',  'b',  'C'
int tones[] = { 62, 63, 64, 65, 66, 67, 68, 69, 72};              //Establece las notas
int Cur_tone = 0;                                                 //Variable q cogerá el tono de la tabla (array).

void setup()
{
  MIDI.begin();                     
  Serial.begin(9600);               
  pinMode(2, INPUT); 
  pinMode(3, INPUT); 
  pinMode(4, INPUT); 
  pinMode(5, INPUT); 
  pinMode(6, INPUT);
  pinMode(7, INPUT); 
  pinMode(8, INPUT); 
  pinMode(12, INPUT);    //set button pins as input
}

void loop()
{
  pin2 = digitalRead(2); 
  pin3 = digitalRead(3); 
  pin4 = digitalRead(4); 
  pin5 = digitalRead(5); 
  pin6 = digitalRead(6); 
  pin7 = digitalRead(7);
  pin8 = digitalRead(8); 
  pin12 = digitalRead(12);               //link the state of button to what the arduino read

  if((pin12 == LOW)) //if pressed Rear button.
  {
    if (pin2 == LOW && pin3 == LOW && pin4 == LOW && pin5 == LOW && pin6 == LOW && pin7 == LOW && pin8 == LOW)
    {
    Cur_tone = tones[0];
    MIDI.sendNoteOn(Cur_tone,127,1);
    } //set note tone to C
      if (pin2 == LOW && pin3 == LOW && pin4 == LOW && pin5 == LOW && pin6 == LOW && pin7 == LOW && pin8 == HIGH)
      {
      Cur_tone = tones[1]; 
      MIDI.sendNoteOn(Cur_tone,127,1);
      }//set note tone to D
       if (pin2 == LOW && pin3 == LOW && pin4 == LOW && pin5 == LOW && pin6 == LOW && pin7 == HIGH && pin8 == HIGH)
       {
       Cur_tone = tones[2];
       MIDI.sendNoteOn(Cur_tone,127,1);
       }//set note tone to E
        if (pin2 == LOW && pin3 == LOW && pin4 == LOW && pin5 == LOW && pin6 == HIGH && pin7 == HIGH && pin8 == HIGH)
        {
        Cur_tone = tones[3];
        MIDI.sendNoteOn(Cur_tone,127,1);
        }//set note tone to F
          if (pin2 == LOW && pin3 == LOW && pin4 == LOW && pin5 == HIGH && pin6 == HIGH && pin7 == HIGH && pin8 == HIGH)
          {
          Cur_tone = tones[4];
          MIDI.sendNoteOn(Cur_tone,127,1);
          }//set note tone to G
            if (pin2 == LOW && pin3 == LOW && pin4 == HIGH && pin5 == HIGH && pin6 == HIGH && pin7 == HIGH && pin8 == HIGH)
            {
            Cur_tone = tones[5];
            MIDI.sendNoteOn(Cur_tone,127,1);
            }//set note tone to A
              if (pin2 == LOW && pin3 == HIGH && pin4 == HIGH && pin5 == HIGH && pin6 == HIGH && pin7 == HIGH && pin8 == HIGH)
              {
              Cur_tone = tones[6];
              MIDI.sendNoteOn(Cur_tone,127,1);
              }//set note tone to B
                  if (pin2 == HIGH && pin3 == HIGH && pin4 == HIGH && pin5 == HIGH && pin6 == HIGH && pin7 == HIGH && pin8 == HIGH)
                  {
                  Cur_tone = tones[7];
                  MIDI.sendNoteOn(Cur_tone,127,1);
                  }//set note tone to higher C
    
  }       
  else             //in case no button is pressed.
  { 
    if((pin12 == HIGH)) 
      {if (pin2 == HIGH && pin3 == LOW && pin4 == HIGH && pin5 == HIGH && pin6 == HIGH && pin7 == HIGH && pin8 == HIGH)
      {
      Cur_tone = tones[8];
      MIDI.sendNoteOn(Cur_tone,127,1);
      } //set note tone to .....
      }
   else
   {    MIDI.sendNoteOff(20,0,1);
   }
delay(100);
}
}
