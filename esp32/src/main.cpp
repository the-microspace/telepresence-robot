#include "blink.hpp"
#include "misc.hpp"
#include "serial_comms.hpp"

#include <Arduino.h>
#include <AccelStepper.h>

// #define LED 22

#define DIR_PIN 22
#define STEP_PIN 23
#define STEPS_PER_REVOLUTION 200
#define motorInterfaceType 1

void setup()
{
  setup_blink();
  setup_serial();
}

void loop()
{
  check_for_messages();
  if(command_available())
  {
    process_command();
  }
}
