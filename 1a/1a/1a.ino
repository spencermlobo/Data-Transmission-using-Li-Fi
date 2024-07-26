#include<LiquidCrystal.h>


#define ldr A0

int val;
int val2;
String duration;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(ldr, INPUT_PULLUP);
  Serial.print("from LiFi App..");
  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = digitalRead(ldr);
  while(val == 0)
  {
    int val2 = digitalRead(ldr);
    duration += val2;
    if(duration == "001")
    {
      Serial.println("Received message: hi");
    }
    if(duration == "0001")
    {
      Serial.println("Received message: hello");
    }
    if(duration == "00001")
    {
      Serial.println("Received message: how are you?");
    }
    if(duration == "000001")
    {
      Serial.println("Received message: I am fine");
    }
    if(duration == "0000001")
    {
      Serial.println("Received message: ok");
      Serial.print("ok");
    }
    if(duration == "00000001")
    {
      Serial.println("Received message: good morning");
    }
    if(duration == "000000001")
    {
      Serial.println("Received message: good afternoon");
    }
    if(duration == "0000000001")
    {
      Serial.println("Received message: good evening");
    }
    if(duration == "00000000001")
    {
      Serial.println("Received message: thank you");
    }
    if(duration == "000000000001")
    {
      Serial.println("Received message: sorry");
    }
    if(val2 == 1)
    {
      duration = "";
      break;
    }
    delay(200);
  }
}
