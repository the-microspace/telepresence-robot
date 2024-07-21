#include "blink.hpp"
#include "misc.hpp"

#include <Arduino.h>
#include <AccelStepper.h>

// #define LED 22

#define DIR_PIN 22
#define STEP_PIN 23
#define STEPS_PER_REVOLUTION 200
#define motorInterfaceType 1

// void setup()
// {
// 	// Declare pins as Outputs
// 	pinMode(STEP_PIN, OUTPUT);
// 	pinMode(DIR_PIN, OUTPUT);
// }
// void loop()
// {
// 	// Set motor direction clockwise
// 	digitalWrite(DIR_PIN, HIGH);

// 	// Spin motor slowly
// 	for(int x = 0; x < STEPS_PER_REVOLUTION; x++)
// 	{
// 		digitalWrite(STEP_PIN, HIGH);
// 		delayMicroseconds(20000);
// 		digitalWrite(STEP_PIN, LOW);
// 		delayMicroseconds(20000);
// 	}
// 	delay(1000); // Wait a second

// 	// Set motor direction counterclockwise
// 	digitalWrite(DIR_PIN, LOW);

// 	// Spin motor quickly
// 	for(int x = 0; x < STEPS_PER_REVOLUTION; x++)
// 	{
// 		digitalWrite(STEP_PIN, HIGH);
// 		delayMicroseconds(10000);
// 		digitalWrite(STEP_PIN, LOW);
// 		delayMicroseconds(10000);
// 	}
// 	delay(1000); // Wait a second
// }

void setup()
{
  // pinMode(LED, OUTPUT); // set digital pin connected to LED as output
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  Serial.begin(9600);
  blinkLED(STEP_PIN, 200);
  blinkLED(STEP_PIN, 200);
  blinkLED(STEP_PIN, 200);
  blinkLED(DIR_PIN, 200);
  blinkLED(DIR_PIN, 200);
  blinkLED(DIR_PIN, 200);
  while(!Serial);
  Serial.println("Input 1 to turn LED on and 2 to off");
}

void loop()
{
  // print_waiting_statement();
  // blinkLED();
  if(Serial.available())
  {
    int state = Serial.parseInt();
    if(state == 1)
    {
      digitalWrite(DIR_PIN, HIGH);
      digitalWrite(STEP_PIN, HIGH);
      Serial.println("LED turned ON");
    }
    else if(state == 2)
    {
      digitalWrite(DIR_PIN, LOW);
      digitalWrite(STEP_PIN, LOW);
      Serial.println("LED turned OFF");
    }
  }
}
