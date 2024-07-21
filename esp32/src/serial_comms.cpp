#include "serial_comms.hpp"

String current_command = "";
boolean command_ready = false;
char start_marker = '<';
char end_marker = '>';

void setup_serial()
{
  Serial.begin(SERIAL_BAUDRATE);
  while(!Serial); // Wait for Serial connection
  Serial.println("<setup>");
  Serial.flush();
}

void check_for_messages()
{
  static boolean receiving = false;
  char next_character;
  while(Serial.available() && command_ready == false)
  {
    next_character = Serial.read();

    if(receiving)
    {
      if(next_character == end_marker)
      {
        receiving = false;
        command_ready = true;
      } else {
        current_command += next_character;
      }
    } else if (next_character == start_marker) {
      receiving = true;
    }
  }
}

bool command_available()
{
  return command_ready;
}

/*
<led,led_state(true/false)>
<move,direction(forward/backward),distance_in_inches(float)>
<rotate,direction(left/right),angle_in_degrees(int)>
<stop,hold_position(true/false)>
*/
void process_command()
{
  String command_flag = getValue(current_command, ',', 0);
  if(command_flag == "led")
  {
    String led_state = getValue(current_command, ',', 1);
    if(led_state == "true")
    {
      digitalWrite(DIR_PIN, HIGH);
      digitalWrite(STEP_PIN, HIGH);
      Serial.println("LED turned ON");
    } else if(led_state == "false") {
      digitalWrite(DIR_PIN, LOW);
      digitalWrite(STEP_PIN, LOW);
      Serial.println("LED turned OFF");
    } else {
      Serial.println("Invalid led command: <" + current_command + ">");
    }
  } else if(command_flag == "move") {
    String direction = getValue(current_command, ',', 1);
    float distance_in_inches = getValue(current_command, ',', 2).toFloat();
    if(direction == "forward") {
      move(distance_in_inches);
    } else if(direction == "backward") {
      move(-distance_in_inches);
    } else {
      Serial.println("Invalid move command: <" + current_command + ">");
    }
  } else if(command_flag == "rotate") {
    String direction = getValue(current_command, ',', 1);
    int angle_in_degrees = getValue(current_command, ',', 2).toInt();
    if(direction == "right") {
      rotate(angle_in_degrees);
    } else if(direction == "left") {
      rotate(-angle_in_degrees);
    } else {
      Serial.println("Invalid move command: <" + current_command + ">");
    }
  } else if(command_flag == "stop") {
    String hold_position = getValue(current_command, ',', 1);
    if(hold_position == "true") {
      stop(true);
    } else if(hold_position == "false") {
      stop(false);
    } else {
      Serial.println("Invalid stop command: <" + current_command + ">");
    }
  } else {
    Serial.println("Unknown command received: <" + current_command + ">");
  }
  current_command = "";
  command_ready = false;
}
