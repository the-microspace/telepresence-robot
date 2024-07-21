#include "misc.hpp"

void print_waiting_statement()
{
  static unsigned long int last_message_time = millis();
  unsigned long int current_time = millis();
  unsigned long int delta_time = current_time - last_message_time;
  if(delta_time > 2500)
  {
    Serial.println("Waiting for serial input...");
    last_message_time = millis();
  }
}
