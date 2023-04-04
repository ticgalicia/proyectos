//fuente https://blogs.etsii.urjc.es/dseytr/piano-educativo/
#define DO 261.626 // Frecuencia en hercios de las notas musicales
#define DOs 277.183
#define RE 293.665
#define REs 311.127
#define MI 329.628
#define FA 349.228
#define FAs 369.994
#define SOL 391.995
#define SOLs 415.305
#define LA 440.000
#define SIB 466.164
#define SI 493.883
#define DO2 523.251
#define RE2 587.330

int altavoz = 10;
int altavoz2= 8;
int muxSIG = A4;
int muxS0 = 3;
int muxS1 = 4;
int muxS2 = 5;
int muxS3 = 6;

float notas[] = {DO2, SI, SIB, LA, SOLs, SOL, FAs, FA, MI, REs, RE, DOs, DO};
const float negra = 500;
const float corchea = 250;
const float semicorchea = 125;
const float blanca = 1000;

int botonTetris = 11;
int botonSpider = 9;
int botonTetStatus = 0;
int botonSpiderStatus = 0;
boolean cancionSonando = false;
boolean cancionSonando2 = false;

int buttonAprender = 2;
int buttonStateAprender = 0;
int randomNumber = 0;
int botonPulsadoTeclado = 0;
boolean comprueba = false;
boolean tocado = false;

int ledVerde = 12;
int ledRojo = 13;

const int entradasmux = 16;
int mux[entradasmux] = {0};

void SetMuxChannel(byte channel)
{
  digitalWrite(muxS0, bitRead(channel, 0));
  digitalWrite(muxS1, bitRead(channel, 1));
  digitalWrite(muxS2, bitRead(channel, 2));
  digitalWrite(muxS3, bitRead(channel, 3));
}




void setup() {
  pinMode(muxSIG, INPUT_PULLUP);
  pinMode(muxS0, OUTPUT);
  pinMode(muxS1, OUTPUT);
  pinMode(muxS2, OUTPUT);
  pinMode(muxS3, OUTPUT);
  pinMode(botonTetris, INPUT_PULLUP);
  pinMode(botonSpider, INPUT_PULLUP);
  pinMode(buttonAprender, INPUT_PULLUP);
  pinMode(botonPulsadoTeclado, INPUT_PULLUP);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);

  Serial.begin(9600);
}

void loop()
{

  buttonStateAprender=digitalRead(buttonAprender);
  if(buttonStateAprender==LOW){
      randomNumber = random(0,12);
      comprueba = true;
      tone(altavoz2,notas[randomNumber]);
      delay(500);
  }else{
      noTone(altavoz2);
  }
  
  for (int i = 0; i <= 15; i++) {

    SetMuxChannel(i);

    mux[i] = digitalRead(muxSIG);


        if (mux[i] == LOW)
        {
          tone(altavoz,notas[i]);
          botonPulsadoTeclado = i;
          tocado = true;
          delay(500);
          Serial.print(i);
          Serial.println("....ON");
        }
        else {
           noTone(altavoz);
           Serial.print(i);
           Serial.println(" .   OFF");

        }
 }
 
 comprobar();

botonTetStatus = digitalRead(botonTetris);
  if(botonTetStatus == LOW && cancionSonando==false){
    cancionSonando = true;
    tetrisTheme();
    delay(200);
  }
  else if(botonTetStatus == LOW && cancionSonando == true){
    cancionSonando = false;
    noTone(altavoz2);
  }
  else{
    noTone(altavoz2);
  }

  botonSpiderStatus = digitalRead(botonSpider);
  if(botonSpiderStatus == LOW && cancionSonando2==false){
    cancionSonando2 = true;
    SpidermanTheme();
    delay(200);
  }
  else if(botonSpiderStatus == LOW && cancionSonando2 == true){
    cancionSonando2 = false;
    noTone(altavoz2);
  }
  else{
    noTone(altavoz2);
  }

}

void tetrisTheme(){
  if(cancionSonando == true){
  tone(altavoz2,LA);
  delay(negra);
    tone(altavoz2,MI);
  delay(corchea);
    tone(altavoz2,FA);
  delay(corchea);
    tone(altavoz2,SOL);
  delay(negra);
    tone(altavoz2,FA);
  delay(corchea);
    tone(altavoz2,MI);
  delay(corchea);
    tone(altavoz2,RE);
  delay(negra);
    tone(altavoz2,FA);
  delay(corchea);
    tone(altavoz2,LA);
  delay(negra);
    tone(altavoz2,SOL);
  delay(corchea);
    tone(altavoz2,FA);
  delay(corchea);
    tone(altavoz2,MI);
  delay(negra);
    tone(altavoz2,MI);
  delay(corchea);
    tone(altavoz2,FA);
  delay(corchea);
    tone(altavoz2,SOL);
  delay(negra);
    tone(altavoz2,LA);
  delay(negra);
    tone(altavoz2,FA);
  delay(negra);
    tone(altavoz2,RE);
  delay(negra);
   noTone(altavoz2);
  delay(50);
    tone(altavoz2,RE);
  delay(negra);
    tone(altavoz2,RE);
  delay(negra);
    tone(altavoz2,SOL);
  delay(negra);
   noTone(altavoz2);
  delay(50);
    tone(altavoz2,SOL);
  delay(corchea);
    tone(altavoz2,SIB);
  delay(corchea);
    tone(altavoz2,RE2);
  delay(negra);
    tone(altavoz2,DO2);
  delay(corchea);
    tone(altavoz2,SIB);
  delay(corchea);
    tone(altavoz2,LA);
  delay(negra);
    tone(altavoz2,FA);
  delay(corchea);
    tone(altavoz2,LA);
  delay(negra);
  tone(altavoz2,SOL);
  delay(corchea);
  tone(altavoz2,FA);
  delay(corchea);
  tone(altavoz2,MI);
  delay(negra);
   noTone(altavoz2);
  delay(50);
  tone(altavoz2,MI);
  delay(corchea);
  tone(altavoz2,FA);
  delay(corchea);
  tone(altavoz2,SOL);
  delay(negra);
  tone(altavoz2,LA);
  delay(negra);
  tone(altavoz2,FA);
  delay(negra);
  tone(altavoz2,RE);
  delay(negra);
  noTone(altavoz2);
  delay(50);
  tone(altavoz2,RE);
  delay(negra);
  }

 
 }

 void SpidermanTheme(){
  if(cancionSonando2 == true){
  tone(altavoz2,RE);
  delay(negra);
  tone(altavoz2,FA);
  delay(corchea);
  tone(altavoz2,LA);
  delay(negra);
  delay(corchea);
  noTone(altavoz2);
  delay(altavoz2);
  tone(altavoz2,SOL);
  delay(negra);
  tone(altavoz2,FA);
  delay(corchea);
  tone(altavoz2,RE);
  delay(corchea);
  tone(altavoz2,RE);
  delay(negra);
  noTone(altavoz2);
  delay(negra);
  tone(altavoz2,RE);
  delay(negra);
  tone(altavoz2,FA);
  delay(corchea);
  tone(altavoz2,LA);
  delay(negra);
  tone(altavoz2,SIB);
  delay(corchea);
  tone(altavoz2,LA);
  delay(negra);
  tone(altavoz2,SOL);
  delay(negra);
  tone(altavoz2,FA);
  delay(corchea);
  tone(altavoz2,RE);
  delay(corchea);
  tone(altavoz2,RE);
  delay(negra);
  noTone(altavoz2);
  delay(negra);
  tone(altavoz2,SOL);
  delay(negra);
  tone(altavoz2,SIB);
  delay(corchea);
  tone(altavoz2,RE2);
  delay(corchea);
  tone(altavoz2,RE2);
  delay(negra);
  noTone(altavoz2);
  delay(negra);
  tone(altavoz2,DO2);
  delay(negra);
  tone(altavoz2,SIB);
  delay(corchea);
  tone(altavoz2,SOL);
  delay(negra);
  delay(corchea);
  noTone(altavoz2);
  delay(negra);
  tone(altavoz2,RE);
  delay(negra);
  tone(altavoz2,FA);
  delay(corchea);
  tone(altavoz2,LA);
  delay(negra + corchea);
  noTone(altavoz2);
  delay(negra);
  tone(altavoz2,SOL);
  delay(negra);
  tone(altavoz2,FA);
  delay(corchea);
  tone(altavoz2,RE);
  delay(negra+corchea);
  tone(altavoz2,LA);
  delay(blanca);
  tone(altavoz2,SOLs);
  delay(corchea);
  tone(altavoz2,SOL);
  delay(corchea);
  tone(altavoz2,FA);
  delay(corchea);
  tone(altavoz2,SOL);
  delay(negra);
  tone(altavoz2,FA);
  delay(negra);
  tone(altavoz2,RE);
  delay(blanca*3);
  }
}

void comprobar(){
  if(comprueba = true && tocado == true){
    if(botonPulsadoTeclado != 0 && randomNumber != 0){
      if(botonPulsadoTeclado == randomNumber){
        digitalWrite(ledVerde, HIGH);
        delay(3000);
        digitalWrite(ledVerde, LOW);
      }else{
        digitalWrite(ledRojo, HIGH);
        delay(3000);
        digitalWrite(ledRojo, LOW);
      }
    }
    comprueba = false;
    tocado = false;
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledRojo, LOW);
  }
  
  
}
