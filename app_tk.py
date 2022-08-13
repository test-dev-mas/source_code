import csv
import serial
import serial.tools.list_ports
import tkinter as tk
from tkinter import ttk

d0 = 0x3C
d1 = 0x71

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

class Model():
    pass

class View(ttk.Frame):
    def __init__(self, parent):
        super().__init__(parent)

        # label
        self.label1 = ttk.Label(self, text='Register D0:')
        self.label1.grid(column=0, row=0, pady=10)
        self.label2 = ttk.Label(self, text='Register D1:')
        self.label2.grid(column=0, row=1, pady=10)
        self.label3 = ttk.Label(self)
        self.label3.grid(column=1, row=0, pady=10)
        self.label4 = ttk.Label(self)
        self.label4.grid(column=1, row=1, pady=10)

        # entry
        self.voltage_level = tk.StringVar()
        self.entry = ttk.Entry(self, textvariable=self.voltage_level)
        self.entry.grid(column=0, row=2, columnspan=2, padx=10, pady=10)

        # button
        self.button = ttk.Button(self, text='Write', command=self.write_button)
        self.button.grid(column=0, row=3, columnspan=2, padx=10, pady=10)

    def write_button(self):
        var = float(self.voltage_level.get())

        if var < 5.0:
            d1 = 0x70
        else:
            d1 = 0x71

class App(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title('PD3603A POWER SUPPLY TEST')

        view = View(self)
        view.grid(column=0, row=0)

if __name__ == '__main__':
    app = App()
    app.mainloop()