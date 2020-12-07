from gpiozero import TrafficLights
from time import sleep

led = TrafficLights(2,3,4)

led.green.on()

on = True

while on:
    sleep(5)
    led.green.off()
    led.amber.on()
    sleep(1)
    led.amber.off()
    led.red.on()
    sleep(5)
    led.amber.on()
    sleep(1)
    led.green.on()
    led.red.off()
    led.amber.off()