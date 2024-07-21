import serial
import time
from threading import Thread

SERIAL_PORT = '/dev/ttyUSB1'
# SERIAL_PORT = 'COM1'
SERIAL_BAUDRATE = 9600
# SERIAL_BAUDRATE = 115200
arduino = serial.Serial(
  port=SERIAL_PORT,
  baudrate=SERIAL_BAUDRATE,
  timeout=1
)

running = True

# FIXME: Doesn't work well because it messes up the input line
def read_serial():
  while running:
    print(arduino.readline())

def write_serial():
  global running
  while running:
    send_to_arduino = input("Enter your message: ")
    if send_to_arduino == "exit":
      running = False
      break
    arduino.write(bytes(send_to_arduino, 'utf-8'))

read_thread = Thread(target=read_serial)
write_thread = Thread(target=write_serial)
read_thread.start()
write_thread.start()
