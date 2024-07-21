from serial import Serial
import serial
import time
from sys import argv

SERIAL_PORT = argv[1] if len(argv) > 1 else '/dev/ttyUSB0'
# SERIAL_PORT = 'COM1'
SERIAL_BAUDRATE = 9600
# SERIAL_BAUDRATE = 115200
try:
  arduino = Serial(
    port=SERIAL_PORT,
    baudrate=SERIAL_BAUDRATE,
    timeout=1
  )
except Exception:
  print("Failed to open #{SERIAL_PORT}, double check that it's plugged in?")
  exit()

print("Valid messages:")
print('\"1\" - LED On')
print('"2" - LED Off')
print('"exit" - Exit script')

def print_arduino():
  try:
    print(str(arduino.readline().decode('utf-8')).strip())
  except UnicodeDecodeError:
    print("Failed to decode message, invalid bytes for utf-8")

while True:
  # Catch up on messages
  while arduino.in_waiting:
    print_arduino()
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
  # Wait until reply
  print_arduino()
