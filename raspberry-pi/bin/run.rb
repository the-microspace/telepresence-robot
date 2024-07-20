require 'serialport'

serial = SerialPort.new('/dev/ttyUSB0', 9600)

loop do
  serial.write('1')
  sleep(1)
  serial.write('2')
  sleep(1)
end
