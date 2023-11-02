from machine import Pin, Timer
led = Pin("GP0", Pin.OUT)
led2 = Pin("GP1", Pin.OUT)
led3 = Pin("GP2", Pin.OUT)
led4 = Pin("GP3", Pin.OUT)
timer = Timer()

def blink(timer):
    led.toggle()
    led2.toggle()
    led3.toggle()
    led4.toggle()
    
timer.init(freq=2, mode=Timer.PERIODIC, callback=blink)