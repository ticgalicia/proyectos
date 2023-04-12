//fuente: https://gist.github.com/RajatGoyal/8505636
// readCapacitivePin
//  Input: Arduino pin number
//  Output: A number, from 0 to 17 expressing
//  how much capacitance is on the pin
//  When you touch the pin, or whatever you have
//  attached to it, the number will get higher
#include "pins_arduino.h" // Arduino pre-1.0 needs this

int pintoread1=10;
int pintoread2=5;
//Threshold of change in capacitive level
const uint8_t capacitive_threshold1=2;
const uint8_t capacitive_threshold2=2;
//Threshold of for how much time the threshold needs to remain changed for consider a touch.
const int touch_time_thres1=150;
const int touch_time_thres2=150;
//Time elapsed after last touch
int time_elapsed1=0;
int time_elapsed2=0;
//Counter to count touch contact time
int touchedcontacttime1=0;
int touchedcpntacttime2=0;
//Touch button state
int touched1=0;
int touched2=0;
//Time after touch
int timeelapsed_touched1=0;
int timeelapsed_touched2=0;
//Reset time 
int reset_time=1000;
void setup()
{
  //initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop()
{
  uint8_t caprating1=readCapacitivePin(pintoread1);
  Serial.print(" Touch button 1 capacitance = ");
  Serial.println(caprating1);
  delay(1000);
  uint8_t caprating2=readCapacitivePin(pintoread2);
  Serial.print(" Touch button 2 capacitance = ");
  Serial.println(caprating2);
  delay(1000);
  
  /*
  if(caprating1 > capacitive_threshold1)
  {
    touchedcontacttime1+=1;
  }
  else{touchedcontacttime1 = 0;}
  
  if(caprating2 > capacitive_threshold2)
  {
    touchedcpntacttime2+=1;
  }
  else{touchedcpntacttime2=0;}
  
  if(touchedcontacttime1>touch_time_thres1)
  {
    //Positive Touch Found on 1
    timeelapsed_touched1+=1;
    touched1=1;
  }
  
  if(touchedcpntacttime2>touch_time_thres2)
  {
    //Positive Touch Found on 2
    touched2=1;
  }
  
  if(touched1==1)
  {
    //Serial.println(timeelapsed_touched1);
    if(timeelapsed_touched1>reset_time)
    {
        if(touched2==1)
        {
          Serial.println("touched 1 & 2");
        }
        else
        {
          Serial.println("touched only 1");
        }
        touched1=0;
        touched2=0;
        timeelapsed_touched1=0;
    }
  }*/
}

// @ http://playground.arduino.cc/Code/CapacitiveSensor
uint8_t readCapacitivePin(int pinToMeasure) {
  // Variables used to translate from Arduino to AVR pin naming
  volatile uint8_t* port;
  volatile uint8_t* ddr;
  volatile uint8_t* pin;
  // Here we translate the input pin number from
  //  Arduino pin number to the AVR PORT, PIN, DDR,
  //  and which bit of those registers we care about.
  byte bitmask;
  port = portOutputRegister(digitalPinToPort(pinToMeasure));
  ddr = portModeRegister(digitalPinToPort(pinToMeasure));
  bitmask = digitalPinToBitMask(pinToMeasure);
  pin = portInputRegister(digitalPinToPort(pinToMeasure));
  // Discharge the pin first by setting it low and output
  *port &= ~(bitmask);
  *ddr  |= bitmask;
  delay(1);
  // Prevent the timer IRQ from disturbing our measurement
  noInterrupts();
  // Make the pin an input with the internal pull-up on
  *ddr &= ~(bitmask);
  *port |= bitmask;

  // Now see how long the pin to get pulled up. This manual unrolling of the loop
  // decreases the number of hardware cycles between each read of the pin,
  // thus increasing sensitivity.
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

  // End of timing-critical section
  interrupts();

  // Discharge the pin again by setting it low and output
  //  It's important to leave the pins low if you want to 
  //  be able to touch more than 1 sensor at a time - if
  //  the sensor is left pulled high, when you touch
  //  two sensors, your body will transfer the charge between
  //  sensors.
  *port &= ~(bitmask);
  *ddr  |= bitmask;

  return cycles;
}
