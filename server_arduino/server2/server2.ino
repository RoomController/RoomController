#include <IRremote.h>
IRsend irsend;

const int NUM_OF_NUMS = 9;
long numbers[NUM_OF_NUMS] = {0xFF30CF, 0xFF18E7, 0xFF7A85, 0xFF10EF, 0xFF38C7, 0xFF5AA5, 0xFF42BD, 0xFF4AB5, 0xFF52AD};

String getSerialRead()
{
    String text = "";
    //int serialRead = ;
    while (Serial.available()) {
      text += (char)Serial.read();
      //serialRead = Serial.read();
    }
    return text;
}

bool isNumeric(String text) {
  int i = 0;
  char dig = text[i];
  while (dig != '\0') {
    if (dig > '9' || dig < '0') {
      return false;
    }
    i++;
    dig = text[i];
  }
  return true;
}

int getNumFromText(String text) {
  int i = 0;
  int num = 0;
  char dig = text[i];
  while (dig != '\0') {
    num *= 10;
    num += (int)text[i] - '0';
    i++;
    dig = text[i];
  }
  return num;
}

void setup()
{
 Serial.begin(9600);
}

void loop() 
{
  
  if (Serial.available()) {
    String command = getSerialRead();
    Serial.println(command);
    if (isNumeric(command)) {
      int index = getNumFromText(command);
      if (index < NUM_OF_NUMS && index >= 0) {
        irsend.sendSony(numbers[index], 24);
      }
    } else {
      long value;
      if(command.equals("off")) {
          value = 0xFF906F;
          irsend.sendSony(value, 24);
      } else {
          
      }
    }
    delay(100);
  }
}


