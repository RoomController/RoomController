#include <IRremote.h>
IRsend irsend;

const int NUM_OF_LEDS = 9;
long results[NUM_OF_LEDS] = {0xFF30CF, 0xFF18E7, 0xFF7A85, 0xFF10EF, 0xFF38C7, 0xFF5AA5, 0xFF42BD, 0xFF4AB5, 0xFF52AD};
char serialRead;

void setup()
{
 Serial.begin(9600);
}

void loop() 
{
  if (Serial.available()) {
    serialRead = Serial.read();
    int index = (int)serialRead - '0';
    irsend.sendSony(results[index], 24);
    delay(100);
  }
}
