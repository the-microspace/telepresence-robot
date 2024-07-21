from serial import Serial
import serial
import time
from sys import argv

SERIAL_PORT = argv[1] or '/dev/ttyUSB0'
# SERIAL_PORT = 'COM1'
SERIAL_BAUDRATE = 9600
# SERIAL_BAUDRATE = 115200
arduino = Serial(
  port=SERIAL_PORT,
  baudrate=SERIAL_BAUDRATE,
  timeout=1
)

print("Valid messages:")
print('\"1\" - LED On')
print('"2" - LED Off')
print('"exit" - Exit script')

while True:
  # Catch up on messages
  while arduino.in_waiting:
    print(str(arduino.readline().decode('utf-8')).strip())
  # Request next message to send to arduino
  send_to_arduino = input("Enter your message: ")
  # Allow exiting
  if(send_to_arduino == 'exit'):
    arduino.close()
    break
  # Write message
  arduino.write(bytes(send_to_arduino, 'utf-8'))
  # Give the arduino a second to receive the message before looping
  time.sleep(1)
