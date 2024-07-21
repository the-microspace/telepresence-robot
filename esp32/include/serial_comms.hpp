#include "common.hpp"
#include "misc.hpp"
#include "movement.hpp"

#ifndef SERIAL_COMMS_HPP
#define SERIAL_COMMS_HPP

void setup_serial();
void check_for_messages();
bool command_available();
void process_command();

#endif
