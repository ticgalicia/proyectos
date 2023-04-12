//FUente: https://playground.arduino.cc/Code/CapacitiveSensor/

// Entrada: número de pin de Arduino 

// Salida: un número, del 0 al 17 que expresa 

// cuánta capacitancia hay en el pin 

// Cuando toca el pin, o lo que sea que tenga 

// adjunto, el el número aumentará 

#include "pins_arduino.h" // Arduino pre-1.0 necesita este

uint8_t readCapacitivePin(int pinToMeasure) {

  // Variables utilizadas para traducir de Arduino a AVR pin naming 

  volatile uint8_t* port;

  volatile uint8_t* ddr;

  volatile uint8_t* pin;
  
  // Aquí traducimos el número de pin de entrada del 

  // número de pin de Arduino al AVR PORT, PIN, DDR, 

  // y qué bits de esos registros nos interesan. 

  byte bitmask;

  port = portOutputRegister(digitalPinToPort(pinToMeasure));

  ddr = portModeRegister(digitalPinToPort(pinToMeasure));

  bitmask = digitalPinToBitMask(pinToMeasure);

  pin = portInputRegister(digitalPinToPort(pinToMeasure));

 // Descarga el pin primero configurándolo bajo y salida 

  *port &= ~(bitmask);

  *ddr  |= bitmask;

  delay(1);

  uint8_t SREG_old = SREG; //back up the AVR Status Register

  //Evita que el IRQ del temporizador perturbe nuestra medición

  noInterrupts();

  // Hacer que el pin sea una entrada con el pull-up interno en 

  *ddr &= ~(bitmask);

  *port |= bitmask;

  // Ahora vea cuánto tiempo se levanta el alfiler. Este despliegue manual del bucle 

  // disminuye el número de ciclos de hardware entre cada lectura del pin, 

  // aumentando así la sensibilidad. 

  uint8_t cycles = 17;

  if (*pin & bitmask) { cycles =  0;}

  else if (*pin & bitmask) { cycles =  1;}

  else if (*pin & bitmask) { cycles =  2;}

  else if (*pin & bitmask) { cycles =  3;}

  else if (*pin & bitmask) { cycles =  4;}

  else if (*pin & bitmask) { cycles =  5;}

  else if (*pin & bitmask) { cycles =  6;}

  else if (*pin & bitmask) { cycles =  7;}

  else if (*pin & bitmask) { cycles =  8;}

  else if (*pin & bitmask) { cycles =  9;}

  else if (*pin & bitmask) { cycles = 10;}

  else if (*pin & bitmask) { cycles = 11;}

  else if (*pin & bitmask) { cycles = 12;}

  else if (*pin & bitmask) { cycles = 13;}

  else if (*pin & bitmask) { cycles = 14;}

  else if (*pin & bitmask) { cycles = 15;}

  else if (*pin & bitmask) { cycles = 16;}

  // Fin de la sección de tiempo crítico; volver a activar las interrupciones si estaban activadas antes, o dejarlas desactivadas si estaban desactivadas antes de
 
  SREG = SREG_old;

  // Descargue el pin nuevamente configurándolo bajo y salida 

  // Es importante dejar los pines bajos si quiere 

  // poder tocar más de 1 sensor a la vez - si 

  // el sensor se deja alto, cuando toca 

  // dos sensores, su cuerpo transferirá la carga entre 

  // sensores.

  *port &= ~(bitmask);

  *ddr  |= bitmask;

  return cycles;

}
