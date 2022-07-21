# a USB-RS232 (ultimate solutions, blue box) is required to make the connection
# no driver needed for Linux system
# recognized as ttyUSB0 when plugged in
# XDM2041 goes into remote mode upon receiving 'SYSTem:REMote'
#
# also works with direct RS232 connection with optiplex 7040
# recognized as ttyS0 under Linux
# 'sudo dmesg|grep ttyS' to find out

import csv
import serial, time
import serial.tools.list_ports

# with serial.Serial('/dev/ttyS0',115200,timeout=5) as ser:
# 	ser.write(b'SYSTem:REMote\r')
# 	ser.write(b'*IDN?\r')
# 	line=ser.readline()
# 	print(line.decode('utf-8'))

# 	ser.write(b'CONF:VOLT\r')

# 	ser.write(b'FUNC?\r')
# 	line=ser.readline()
# 	print(line.decode('utf-8'))

# 	ser.write(b'MEAS?\r')
# 	line=ser.readline()
# 	print(line.decode('utf-8'))

class DMM(serial.Serial):
	def __init__(self):
		super().__init__()

		self.port = '/dev/ttyS0'
		self.baudrate = 115200
		self.timeout = 5
		self.open()

		self.write(b'SYSTem:REMote\r')
		self.write(b'*IDN?\r')
		line=self.readline()
		print(line.decode('utf-8'))

		self.write(b'CONF:VOLT\r')

	def measure_volt(self):
		self.write(b'MEAS?\r')
		line = self.readline()
		ret = line.decode('utf-8')
		return ret

class Arduino(serial.Serial):
    def __init__(self):
        super().__init__()

        self.arduino_port = None

        for port in serial.tools.list_ports.comports():
            if port.pid == 0x7523 and port.vid == 0x1a86:
                self.arduino_port = port.device

        if self.arduino_port is None:
            raise ValueError('Device not found')

        self.port = self.arduino_port
        self.baudrate = 115200
        self.timeout = 10
        self.open()

def main():
	arduino = Arduino()
	dmm = DMM()

	f = open('02.csv', 'w')	
	writer = csv.writer(f)

	print(arduino.readline())

	arduino.write(b'0')

	while True:
		arduino.write(b'+')
		time.sleep(5)
		ret=dmm.measure_volt()
		writer.writerow([ret])
		print(ret)
		time.sleep(5)


if __name__ == "__main__":
    main()