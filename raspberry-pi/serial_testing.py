from serial import Serial, SerialException
from time import sleep
from sys import argv

SERIAL_PORT = argv[1] if len(argv) > 1 else '/dev/ttyUSB0'
SERIAL_BAUDRATE = 9600

def print_arduino_next_line():
  try:
    print(str(arduino.readline().decode('utf-8')).strip())
  except UnicodeDecodeError:
    print("Failed to decode message, invalid bytes for utf-8")

if __name__ == '__main__':
  print('Running. Press CTRL-C to exit. Valid commands: <led>, <move>, <rotate>, <stop>')
  try:
    with Serial(SERIAL_PORT, SERIAL_BAUDRATE, timeout=1) as arduino:
      sleep(1) # Wait for Serial to open
      if arduino.isOpen():
        print("{} connected!".format(arduino.port))
        try:
          arduino.dtr = False
          arduino.rts = False
          sleep(1)
          arduino.flushInput()
          while True:
            # Catch up on messages
            while arduino.in_waiting:
              print_arduino_next_line()
            # Request next message to send to arduino
            send_to_arduino = input("Enter command: ")
            # Write message
            arduino.write(bytes(send_to_arduino, 'utf-8'))
            # Give the arduino a second to receive the message before looping
            arduino.flush()
            sleep(1)
            # Wait until reply
            print_arduino_next_line()
        except KeyboardInterrupt:
          print("\n\nCTRL-C caught, exiting.")
          arduino.flush()
          arduino.close()
          exit()
  except SerialException:
    print("Failed to open {}, double check port?".format(SERIAL_PORT))
    exit()
else:
  print('This is only intended to be run as a CLI script.')
