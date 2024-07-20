#include "blink.hpp"

void blinkLED()
{
  blinkLED(500);
}

void blinkLED(int delay_length)
{
  digitalWrite(LED, HIGH); // turn LED ON
  delay(delay_length);     // wait for delay_length milliseconds
  digitalWrite(LED, LOW);  // turn OFF the LED
  delay(delay_length);     // wait for delay_length milliseconds
}
