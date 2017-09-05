#include <IRremote.h>
IRsend irsend;

const int NUM_OF_NUMS = 9;
const char START_OF_TEXT_PRINT = '-';

long numbers[NUM_OF_NUMS] = {0xFF30CF, 0xFF18E7, 0xFF7A85, 0xFF10EF, 0xFF38C7, 0xFF5AA5, 0xFF42BD, 0xFF4AB5, 0xFF52AD};

String getSerialRead()
{
    Serial.setTimeout(100);
    String text = Serial.readString();
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

void printText(String text) {
  Serial.println("printing: ");
  irsend.sendSony(0xFF01FF, 24);
  delay(2000);
  for (int i = 1; i < text.length() && i <= 32; i++) {
    Serial.print("FFFF");
    Serial.println(text[i], HEX);
    int sentVal = 0xFFFF;
    sentVal *= 0x100;
    sentVal += text[i];
    irsend.sendSony(sentVal, 24);
    delay(2000);
  }
  Serial.println("------");
  irsend.sendSony(0xFF01FF, 24);
  delay(2000);
}

void setup()
{
 Serial.begin(9600);
}

void loop() 
{
  
  if (Serial.available()) {
    String command = getSerialRead();
    if (isNumeric(command)) {
      int index = getNumFromText(command);
      if (index < NUM_OF_NUMS && index >= 0) {
        irsend.sendSony(numbers[index], 24);
      }
    } else {
      if(command.equals("off") || command == "o" || command == "O") {
          irsend.sendSony(0xFF906F, 24);
//      } else if (command[0] == START_OF_TEXT_PRINT) {
//        printText(command);
//      } else {
//        String txt = (String)START_OF_TEXT_PRINT;
//        txt += "Command not found";
//        printText(txt);
      }
    }
    delay(100);
  }
}


