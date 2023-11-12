from machine import Pin
import time

sound_sensor = Pin(0, Pin.IN, Pin.PULL_DOWN)	# Define pin 0 as input port, to accept digital input
led = Pin("LED", Pin.OUT)	# Define LED as output port, to indicate digital trigger reached

while True:
    led.off()	# Led is off by default
    if sound_sensor.value() == 1:	# Check for if sound is detected
        print("Sound Detected")
        led.on()
        time.sleep(2)
    time.sleep(.1)	# Slight pause to not overwhelm the serial interface