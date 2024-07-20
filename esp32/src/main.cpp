#include <Arduino.h>
#include "blink.hpp"

#define LED 23

void setup()
{
  pinMode(LED, OUTPUT);    // set digital pin connected to LED as output
  Serial.begin(9600);
  blinkLED(200);
  blinkLED(200);
  blinkLED(200);
  while(!Serial);
  Serial.println("Input 1 to turn LED on and 2 to off");
}

void loop()
{
  // blinkLED();
  if(Serial.available())
  {
    int state = Serial.parseInt();
    if(state == 1)
    {
      digitalWrite(LED, HIGH);
      Serial.println("LED turned ON");
    }
    else if(state == 2)
    {
      digitalWrite(LED, LOW);
      Serial.println("LED turned OFF");
    }
  }
}
