from machine import Pin
import time
from utime import sleep

#Pin definitions
button_2 = Pin(0, Pin.IN)
button_1 = Pin(5, Pin.IN)
tracker = Pin(1, Pin.IN)
led_red = Pin(9, Pin.OUT)
led_green = Pin(10, Pin.OUT)
buzzer = Pin(6, Pin.OUT)
ir_receiver = Pin(16, Pin.OUT)
#ir transmitter

#Loop forever
while True:

    # tracker
    #print(f'Location: {tracker.value()}')
    
    #button
    if button_1.value() == 1:
        led_green.value(1)
        sleep(.05)
        led_green.value(0)
        buzzer.value(1)
        sleep(.5)
        buzzer.value(0)     
        
    if button_2.value() == 1:
        led_red.value(1)
        sleep(.05)
        led_red.value(0)
        buzzer.value(1)
        sleep(.25)
        buzzer.value(0)
        sleep(.25)
        buzzer.value(1)
        sleep(.25)
        buzzer.value(0)
        

       
    #ir receiver
    try:
            if ir_receiver.value() == 0:
                led_red.value(0)
            if ir_receiver.value() == 1:
                led_red.value(1)
                print("signal received")
            sleep(.05)
    except KeyboardInterrupt:
        break
        

        
    