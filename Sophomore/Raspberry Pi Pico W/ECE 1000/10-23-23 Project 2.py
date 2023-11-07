from machine import Pin
from utime import sleep
import time

# variable for setting the speed of counting
delayTime = 0.5
delayTimeD = 0.25

# setup the four LEDs
eightPlaceLED = Pin("GP0", Pin.OUT)
fourPlaceLED = Pin("GP1", Pin.OUT)
twoPlaceLED = Pin("GP2", Pin.OUT)
onePlaceLED = Pin("GP3", Pin.OUT)

button = Pin("GP4", Pin.IN, Pin.PULL_UP)

# turn off all LEDs just in case any are on from last run of program
onePlaceLED.off()
twoPlaceLED.off()
fourPlaceLED.off()
eightPlaceLED.off()

def time_in_binary():
    print("0000, 0")
    onePlaceLED.off()
    twoPlaceLED.off()
    fourPlaceLED.off()
    eightPlaceLED.off()
    sleep(delayTime)
    
    if button.value() == 1:
        reverseTime()
        print(reverseTime())
        
    # 0001
    print("0001, 1")
    onePlaceLED.on()
    twoPlaceLED.off()
    fourPlaceLED.off()
    eightPlaceLED.off()
    sleep(delayTime)
    
    if button.value() == 1:
        reverseTime()
        print(reverseTime())
    
    # 0010
    print("0010, 2")
    onePlaceLED.off()
    twoPlaceLED.on()
    fourPlaceLED.off()
    eightPlaceLED.off()
    sleep(delayTime)
    
    if button.value() == 1:
        reverseTime()
        print(reverseTime())
    
    # 0011
    print("0011, 3")
    onePlaceLED.on()
    twoPlaceLED.on()
    fourPlaceLED.off()
    eightPlaceLED.off()
    sleep(delayTime)
    
    if button.value() == 1:
        reverseTime()
        print(reverseTime())
        
    # 0100
    print("0100, 4")
    onePlaceLED.off()
    twoPlaceLED.off()
    fourPlaceLED.on()
    eightPlaceLED.off()
    sleep(delayTime)
    
    if button.value() == 1:
        reverseTime()

    
    # 0101
    print("0101, 5")
    onePlaceLED.on()
    twoPlaceLED.off()
    fourPlaceLED.on()
    eightPlaceLED.off()
    sleep(delayTime)
    
    if button.value() == 1:
        reverseTime()

    
    # 0110
    print("0110, 6")
    onePlaceLED.off()
    twoPlaceLED.on()
    fourPlaceLED.on()
    eightPlaceLED.off()
    sleep(delayTime)
    
    if button.value() == 1:
        reverseTime()

    
    # 0111
    print("0111, 7")
    onePlaceLED.on()
    twoPlaceLED.on()
    fourPlaceLED.on()
    eightPlaceLED.off()
    sleep(delayTime)
    
    if button.value() == 1:
        reverseTime()

    
    # 1000
    print("1000, 8")
    onePlaceLED.off()
    twoPlaceLED.off()
    fourPlaceLED.off()
    eightPlaceLED.on()
    sleep(delayTime)
    
    if button.value() == 1:
        reverseTime()

    
    # 1001
    print("1001, 9")
    onePlaceLED.on()
    twoPlaceLED.off()
    fourPlaceLED.off()
    eightPlaceLED.on()
    sleep(delayTime)
    
    if button.value() == 1:
        reverseTime()

    
    # 1010
    print("1010, 10")
    onePlaceLED.off()
    twoPlaceLED.on()
    fourPlaceLED.off()
    eightPlaceLED.on()
    sleep(delayTime)
    
    if button.value() == 1:
        reverseTime()

    
    # 1011
    print("1011, 11")
    onePlaceLED.on()
    twoPlaceLED.on()
    fourPlaceLED.off()
    eightPlaceLED.on()
    sleep(delayTime)
    
    if button.value() == 1:
        reverseTime()

    
    # 1100
    print("1100, 12")
    onePlaceLED.off()
    twoPlaceLED.off()
    fourPlaceLED.on()
    eightPlaceLED.on()
    sleep(delayTime)
    
    if button.value() == 1:
        reverseTime()

    
    # 1101
    print("1101, 13")
    onePlaceLED.on()
    twoPlaceLED.off()
    fourPlaceLED.on()
    eightPlaceLED.on()
    sleep(delayTime)
    
    if button.value() == 1:
        reverseTime()

    
    # 1110
    print("1110, 14")
    onePlaceLED.off()
    twoPlaceLED.on()
    fourPlaceLED.on()
    eightPlaceLED.on()
    sleep(delayTime)
    
    if button.value() == 1:
        reverseTime()

    
    # 1111
    print("1111, 15")
    onePlaceLED.on()
    twoPlaceLED.on()
    fourPlaceLED.on()
    eightPlaceLED.on()
    sleep(delayTime)
    
    if button.value() == 1:
        reverseTime()

    
def reverseTime():
    # 1111
    print("1111, 15")
    onePlaceLED.on()
    twoPlaceLED.on()
    fourPlaceLED.on()
    eightPlaceLED.on()
    sleep(delayTimeD)
    # 1110
    print("1110, 14")
    onePlaceLED.off()
    twoPlaceLED.on()
    fourPlaceLED.on()
    eightPlaceLED.on()
    sleep(delayTimeD)
    # 1101
    print("1101, 13")
    onePlaceLED.on()
    twoPlaceLED.off()
    fourPlaceLED.on()
    eightPlaceLED.on()
    sleep(delayTimeD)
    # 1100
    print("1100, 12")
    onePlaceLED.off()
    twoPlaceLED.off()
    fourPlaceLED.on()
    eightPlaceLED.on()
    sleep(delayTimeD)
    # 1011
    print("1011, 11")
    onePlaceLED.on()
    twoPlaceLED.on()
    fourPlaceLED.off()
    eightPlaceLED.on()
    sleep(delayTimeD)
    # 1010
    print("1010, 10")
    onePlaceLED.off()
    twoPlaceLED.on()
    fourPlaceLED.off()
    eightPlaceLED.on()
    sleep(delayTimeD)
    #1001
    print("1001, 9")
    onePlaceLED.on()
    twoPlaceLED.off()
    fourPlaceLED.off()
    eightPlaceLED.on()
    sleep(delayTimeD)
    # 1000
    print("1000, 8")
    onePlaceLED.off()
    twoPlaceLED.off()
    fourPlaceLED.off()
    eightPlaceLED.on()
    sleep(delayTimeD)
    # 0111
    print("0111, 7")
    onePlaceLED.on()
    twoPlaceLED.on()
    fourPlaceLED.on()
    eightPlaceLED.off()
    sleep(delayTimeD)
    # 0110
    print("0110, 6")
    onePlaceLED.off()
    twoPlaceLED.on()
    fourPlaceLED.on()
    eightPlaceLED.off()
    sleep(delayTimeD)
    # 0101
    print("0101, 5")
    onePlaceLED.on()
    twoPlaceLED.off()
    fourPlaceLED.on()
    eightPlaceLED.off()
    sleep(delayTimeD)
    # 0100
    print("0100, 4")
    onePlaceLED.off()
    twoPlaceLED.off()
    fourPlaceLED.on()
    eightPlaceLED.off()
    sleep(delayTimeD)
    # 0011
    print("0011, 3")
    onePlaceLED.on()
    twoPlaceLED.on()
    fourPlaceLED.off()
    eightPlaceLED.off()
    sleep(delayTimeD)
    # 0010
    print("0010, 2")
    onePlaceLED.off()
    twoPlaceLED.on()
    fourPlaceLED.off()
    eightPlaceLED.off()
    sleep(delayTimeD)
    # 0001
    print("0001, 1")
    onePlaceLED.on()
    twoPlaceLED.off()
    fourPlaceLED.off()
    eightPlaceLED.off()
    sleep(delayTimeD)
    print("0000, 0")
    onePlaceLED.off()
    twoPlaceLED.off()
    fourPlaceLED.off()
    eightPlaceLED.off()
    sleep(delayTimeD)

while True:
    if button.value() == 0:
        time_in_binary()
    else:
        reverseTime()
