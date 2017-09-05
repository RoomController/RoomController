/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;
const int NUM_OF_LEDS = 9;
int on[NUM_OF_LEDS] = {0};
int pins[NUM_OF_LEDS] = {3,4,5,6,7,8,9,10,12};
long resaults[NUM_OF_LEDS] = {0xFF30CF, 0xFF18E7, 0xFF7A85, 0xFF10EF, 0xFF38C7, 0xFF5AA5, 0xFF42BD, 0xFF4AB5, 0xFF52AD};
char serialRead;
void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  for (int i=0; i< NUM_OF_LEDS; i++) {
    pinMode(pins[i],OUTPUT);
  }
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    for (int i=0; i< NUM_OF_LEDS; i++) {
      if (results.value == resaults[i]) {
        if (on[i] == 0) {
          digitalWrite(pins[i],HIGH);
          on[i] = 1;
        } 
        else {
          digitalWrite(pins[i],LOW);
          on[i] = 0;
        }
        break;
      }
    }
    irrecv.resume(); // Receive the next value
  }
  //delay(100);
}
