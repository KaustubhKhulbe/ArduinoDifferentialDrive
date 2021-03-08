import serial
import syslog
import time
import matplotlib.pyplot as plt
import pygame
import sys

# The following line is for serial over GPIO
port = '/dev/cu.usbmodem14201'

ard = serial.Serial(port, 9600, timeout=5)
x_vals = []
y_vals = []

white = (255, 255, 255)

start_time = time.time()

# while time.time() - start_time < 5:
while True:
    # Serial read section
    msg = ard.readline()
    x = msg.decode("utf-8")
    x = x.strip('\n')
    x = x.strip('\r')

    msg = ard.readline()
    y = msg.decode("utf-8")
    y = y.strip('\n')
    y = y.strip('\r')

    x_val = 0.0
    y_val = 0.0
    try:
        x_val = float(x)
        y_val = float(y)
        print(x_val)
        print(y_val)
        x_vals.append(x_val)
        y_vals.append(y_val)
    except ValueError:
        print("Not a float")

    #plt.pause(0.01)
    plt.plot(x_vals, y_vals, c='blue')
    #plt.scatter(x_vals[-1], y_vals[-1], c='red')

    plt.pause(0.000001)



    '''if len(x_vals) > 70:
        x_vals.pop(0)
        y_vals.pop(0)
    plt.clf()'''

else:
    print("Exiting")
exit()
plt.show()
