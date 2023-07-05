/*********************************************************
https://forum.arduino.cc/t/midi-touch-piano-with-two-mpr121/866600
This is a library for the MPR121 12-channel Capacitive touch sensor

Designed specifically to work with the MPR121 Breakout in the Adafruit shop
----> https://www.adafruit.com/products/ 3 1

These sensors use I2C communicate, at least 2 pins are required
to interface

Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!

Written by Limor Fried/Ladyada for Adafruit Industries.
BSD license, all text above must be included in any redistribution
**********************************************************/

#include <Wire.h>
#include <Adafruit_MPR121.h>
#include <Control_Surface.h> // Include the Control Surface library

// Instantiate a MIDI over USB interface
USBMIDI_Interface midi;

//*const uint8_t C4 = 60; // Note number 60 is defined as middle C in the MIDI specification

using namespace MIDI_Notes;

// MIDI address of the note to send
const MIDIAddress noteAddress = {note(C, 1), CHANNEL_1};
const uint8_t velocity = 0x7F;
//*0b1111111; // Maximum velocity (0b1111111 = 0x7F = 127)

#ifndef _BV
#define _BV(bit) (1 << (bit))
#endif

// You can have up to 4 on one i2c bus but one is enough for testing!
Adafruit_MPR121 cap = Adafruit_MPR121();

// Keeps track of the last pins touched
// so we know when buttons are ‘released’
uint16_t lasttouched = 0;
uint16_t currtouched = 0;

void setup() {
midi.begin();
//Control_Surface.begin(); // Initialize Control Surface
Serial.begin(9600);

Serial.println("Adafruit MPR121 Capacitive Touch sensor test");

// Default address is 0x5A, if tied to 3.3V its 0x5B
// If tied to SDA its 0x5C and if SCL then 0x5D
if (!cap.begin(0x5A)) {
Serial.println("MPR121 not found, check wiring?");
while (1);
}
Serial.println("MPR121 found!");
}

void loop() {

midi.update();
// Get the currently touched pads
currtouched = cap.touched();

for (uint8_t i=0; i<12; i++) {
// it if is touched and wasnt touched before, alert!
if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
Serial.print(i); Serial.println(" touched");

midi.sendNoteOn(noteAddress, velocity);

}
// if it was touched and now isnt, alert!
if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
Serial.print(i); Serial.println(" released");

midi.sendNoteOff(noteAddress, velocity);

}
}

// reset our state
lasttouched = currtouched;

}
