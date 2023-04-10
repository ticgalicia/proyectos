//Fuente: https://hetpro-store.com/TUTORIALES/potenciometro-digital-mcp4022/

int cs =6;
int ud=7;
int decremento=5;
int incremento=4;

int inc;
int dec;
void setup() {
pinMode(cs,OUTPUT);
pinMode(ud,OUTPUT);
pinMode(decremento, INPUT);
pinMode(incremento, INPUT);
digitalWrite(cs, HIGH);
digitalWrite(ud, HIGH);


delay(100);
}

void loop() {
  inc=digitalRead(decremento);
  delay(100);
 if(inc==HIGH)
 {
  digitalWrite(ud, HIGH);
   delay(10 );
  digitalWrite(cs, HIGH);
  delay(10);
  digitalWrite(cs, LOW);
  delay(100);
   digitalWrite(ud, LOW);
   delay(10);
   digitalWrite(ud, HIGH);
   delay(10);
     digitalWrite(ud, LOW);
   delay(10);
    digitalWrite(cs, HIGH);
   delay(100);
  }
dec=digitalRead(incremento);
  delay(100);
 if(dec==HIGH){
    digitalWrite(cs, HIGH);
    delay(10);
    digitalWrite(cs, LOW);
    delay(100);
    digitalWrite(ud, LOW);
    delay(10);
    digitalWrite(ud, HIGH);
    delay(10);
    digitalWrite(ud, LOW);
    delay(10);
    digitalWrite(cs, HIGH);
   delay(100);
    }  
}
