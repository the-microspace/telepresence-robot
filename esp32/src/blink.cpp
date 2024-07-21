#include "blink.hpp"

void setup_blink()
{
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  int blink_speed = 100;
  blinkLED(STEP_PIN, blink_speed);
  blinkLED(STEP_PIN, blink_speed);
  blinkLED(STEP_PIN, blink_speed);
  blinkLED(DIR_PIN, blink_speed);
  blinkLED(DIR_PIN, blink_speed);
  blinkLED(DIR_PIN, blink_speed);
}

void blinkLED(int pin)
{
  blinkLED(pin, 500);
}

void blinkLED(int pin, int delay_length)
{
  digitalWrite(pin, HIGH); // turn LED ON
  delay(delay_length);     // wait for delay_length milliseconds
  digitalWrite(pin, LOW);  // turn OFF the LED
  delay(delay_length);     // wait for delay_length milliseconds
}
