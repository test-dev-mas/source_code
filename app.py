# no class

import gi, serial, time
import serial.tools.list_ports

gi.require_version("Gtk", "3.0")
from gi.repository import Gtk


def read_i2c_addr():
    pass

def actuate_relay_1(relay_1):
    # ser.write(b'\x30')
    pass

def actuate_relay_2(relay_2):
    # ser.write(b'\x31')
    pass

def read_adc_1(adc_1):
    # ser.write(b'\x32')
    # # i2c controller sends three bytes, higher byte/lower byte/carriage return
    # a = b''
    # while True:
    #     b = ser.read(1)
    #     if  int.from_bytes(b, 'little') == 0x0D:
    #         break
    #     a += b
    # # assemble higher/lower byte into integer
    # adc_reading = a[1]|a[0]<<8
    # # convert to voltage (4.84 is measured at VREF pin on Arduino)
    # adc_volt = adc_reading * 4.84 / 1024
    # # print to label on button press
    # adc_value_1.set_text(f'{adc_volt:.3f}V')
    pass

def main():
    pass

app = Gtk.Window(title="PD3603A")

app.set_border_width(10)

panel1 = Gtk.Frame()

panel1.set_label_align(0.5,0.5)

panel1.set_shadow_type(Gtk.ShadowType.NONE)

grid = Gtk.Grid(column_homogeneous=True,row_homogeneous=True,column_spacing=10,row_spacing=10)

grid.attach(panel1,0,0,1,2)

app.add(grid)

#####################################################################################################
entry_1 = Gtk.Entry()
button_1 = Gtk.Button(label="Write Registers")





grid_1 = Gtk.Grid(column_homogeneous=True,row_homogeneous=True,column_spacing=10,row_spacing=10)

grid_1.attach(button_1,0,0,1,1)
grid_1.attach(entry_1,0,1,1,1)

panel1.add(grid_1)


app.set_size_request(250,250)
app.connect("destroy", Gtk.main_quit)
app.show_all()
Gtk.main()

    # while True:
    #     arduino.write(b'hell world!')
    #     time.sleep(1)

# if __name__ == "__main__":
#     main()