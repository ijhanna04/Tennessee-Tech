from machine import Pin
import time

button = Pin("GP4", Pin.IN, Pin.PULL_UP)

while True:
    if button.value() == 1:
        print("Button is Pressed")
    else:
        print("Button is not Pressed")
    time.sleep(0.1)