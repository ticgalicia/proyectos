//fuente : https://codiziapp.com/projects/simula-multitasking-en-arduino-con-millis

#define LED1 10

#define LED2 9

#define LED3 8

int POT = A0;



unsigned long previousMillisLed1 = 0;

const long intervalLed1 = 1000;

int ledState1 = LOW; 



unsigned long previousMillisLed2 = 0;

const long intervalLed2 = 500;

int ledState2 = LOW; 



unsigned long previousMillisLed3 = 0;

const long intervalLed3 = 100;

int ledState3 = LOW; 



unsigned long previousMillisPot1 = 0;

const long intervalPot1 = 1000;



unsigned long currentMillis = 0;

void setup() {

  pinMode(LED1, OUTPUT);

  pinMode(LED2, OUTPUT);

  pinMode(LED3, OUTPUT);

  pinMode(POT, INPUT);

  Serial.begin(9600);

}



void loop() {

  currentMillis = millis();

  ledBlink(&currentMillis, &previousMillisLed1, intervalLed1, &ledState1, LED1);

  ledBlink(&currentMillis, &previousMillisLed2, intervalLed2, &ledState2, LED2);

  ledBlink(&currentMillis, &previousMillisLed3, intervalLed3, &ledState3, LED3);



//  if (currentMillisPot1 - previousMillisPot1 >= intervalPot1) {

//    previousMillisPot1 = currentMillisPot1;

//

//    int potValue = analogRead(POT);

//    Serial.println(potValue);

//  }



}



void ledBlink(unsigned long *cMillis, unsigned long *pMillis, const long interval, int *ledState, int LED){  //utilizar apuntadores - pasar la direccion de memoria de cada variable

  if (*cMillis - *pMillis >= interval) {

    *pMillis = *cMillis;



    if (*ledState == LOW) {

      *ledState = HIGH;

    } else {

      *ledState = LOW;

    }

  }

  digitalWrite(LED, *ledState);

}
