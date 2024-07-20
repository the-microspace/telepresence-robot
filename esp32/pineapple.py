import serial
import time

SERIAL_PORT = '/dev/ttyUSB0'
SERIAL_BAUDRATE = 9600
# SERIAL_BAUDRATE = 115200
arduino = serial.Serial(
  port=SERIAL_PORT,
  baudrate=SERIAL_BAUDRATE,
  timeout=.1)


def write_read(x):
    arduino.write(bytes(x,  'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return  data


while True:
    num = input("Enter a number: ")
    value  = write_read(num)
    print(value)
