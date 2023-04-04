//fuente: https://www.youtube.com/watch?v=A7h-iWN-d08
//Canal de YouTube -> RobotUNO
//Piano con platanos

int melodia1 = 250;
int melodia2 = 500;
int melodia3 = 750;
int melodia4 = 1000;
int melodia5 = 1250;
int melodia6 = 1500;
int zumbador = 8;
int numeroTonos = 1;

int aux=1010; //Calibracion

void setup() {
 Serial.begin(9600);
 pinMode(zumbador, OUTPUT);
}

void loop() {
   Serial.print("Analog 1: ");
   Serial.println(analogRead(0));
   Serial.print("Analog 2: ");
   Serial.println(analogRead(1));
   Serial.print("Analog 3: ");
   Serial.println(analogRead(2));
   Serial.print("Analog 4: ");
   Serial.println(analogRead(3));
   Serial.print("Analog 5: ");
   Serial.println(analogRead(0));
   Serial.print("Analog 6: ");
   Serial.println(analogRead(0));
   Serial.print("\n\n");
 
   if(analogRead(0)<aux){
      tone(zumbador, melodia1);
      delay(500);
      noTone(zumbador);
   }
   if(analogRead(1)<aux){
      tone(zumbador, melodia2);
      delay(500);
      noTone(zumbador);
   }
   if(analogRead(2)<aux){
      tone(zumbador, melodia3);
      delay(500);
      noTone(zumbador);
   }
   if(analogRead(3)<aux){
      tone(zumbador, melodia4);
      delay(500);
      noTone(zumbador);
   }
   if(analogRead(4)<aux){
      tone(zumbador, melodia5);
      delay(500);
      noTone(zumbador);
   }
   if(analogRead(5)<aux){
      tone(zumbador, melodia6);
      delay(500);
      noTone(zumbador);
   }
  
  //delay(500);
}
