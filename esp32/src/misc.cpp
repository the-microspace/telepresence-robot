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

// All hail String getValue!
String getValue(String data, char separator, int index) {
  int foundSeparators = 0;
  int substringIndices[] = { 0, -1 };
  int lastIndex = data.length() - 1;

  // Loop through each character in the string
  for (int i = 0; i <= lastIndex && foundSeparators <= index; i++) {
    // Check if the current character is the separator or the end of the string
    if (data.charAt(i) == separator || i == lastIndex) {
      foundSeparators++;
      substringIndices[0] = substringIndices[1] + 1;
      // Update the end index for the substring
      substringIndices[1] = (i == lastIndex) ? i + 1 : i;
    }
  }

  if (foundSeparators > index) {
    // Return the substring if the desired index was found
    return data.substring(substringIndices[0], substringIndices[1]);
  } else {
    // Return an empty string if the index is out of bounds
    return "";
  }
}
