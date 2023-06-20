/*
 *  - Ejemplo reproducción mp3 con arduino nano, uno
 *  Funciones principales
 *  myDFPlayer.next(); //Reproduce el siguiente archivo mp3 
 *  myDFPlayer.previous(); // Reproduce el anterior archivo mp3
 *  myDFPlayer.play(1); //Reproduce el primer archivo mp3
 *  myDFPlayer.loop(1); //Reproduce infinitamente el primer archivo mp3
 *  myDFPlayer.pause(); //pause 
 *  myDFPlayer.start(); //reproduce desde la pausa 
 *  
*/

#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;


void setup()
{
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);

  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Error inicializando modulo mp3:"));
    Serial.println(F("1.Porfavor revisa las conexiones!"));
    Serial.println(F("2.Porfavor inserta memoria microSD!"));
    while(true){
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("Inicialización correcta DFPlayer."));
  
  myDFPlayer.volume(25);  //Set volume value. From 0 to 30
  myDFPlayer.play(1);  //Play the first mp3
}

void loop()
{
 
  
}
