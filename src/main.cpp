#include <Arduino.h>

#define LED 23

void setup() {
  pinMode(LED, OUTPUT);    // set digital pin connected to LED as output
}

void loop() {
  digitalWrite(LED, HIGH); // turn LED ON
  delay(1000);                    //wait for 500 milliseconds
  digitalWrite(LED, LOW);  // turn OFF the LED
  delay(1000);                    //wait for 500 milliseconds
}
