#include "blink.hpp"

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
