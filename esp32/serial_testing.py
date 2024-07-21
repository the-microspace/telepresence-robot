from serial import Serial
import serial
import time

SERIAL_PORT = '/dev/ttyUSB1'
# SERIAL_PORT = 'COM1'
SERIAL_BAUDRATE = 9600
# SERIAL_BAUDRATE = 115200
arduino = Serial(
  port=SERIAL_PORT,
  baudrate=SERIAL_BAUDRATE,
  timeout=1
)

while True:
  # Catch up on messages
  while arduino.in_waiting:
    print(str(arduino.readline().decode('utf-8')).strip())
  # Request next message to send to arduino
  send_to_arduino = input("Enter your message: ")
  # Write message
  arduino.write(bytes(send_to_arduino, 'utf-8'))
  # Give the arduino a second to receive the message before looping
  time.sleep(1)
