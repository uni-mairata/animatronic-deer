# imports
import time
from gpiozero import LED, Button, Servo # gpiozero library (installed by default in the Raspberry Pi OS Desktop image)
import RPi.GPIO as GPIO # import GPIO module

# pi initialization
# TODO: fix port constants
# TODO: try coding servos based on --> https://github.com/fervanegas/Test_360servo
leg_servo_front = Servo(0) # TODO: figure out which two legs this controls
leg_servo_back = Servo(0) # TODO: figure out which two legs this controls
head_servo = Servo(0)

# pneumatic piston
GPIO.setmode(GPIO.BCM) # should be able to move pneumatics based on this --> https://raspi.tv/2013/rpi-gpio-basics-5-setting-up-and-using-outputs-with-rpi-gpio
GPIO.setup(port_or_pin, GPIO.OUT) #TODO: replace "port_or_pin"

led = LED(0)
button = Button(0)

PROGRAM_START = False

# based on this script - https://docs.google.com/document/d/1DNoGuv6uL_T2RtTujJc0lmIhl_3DgXTTr4SzQGK93f8/edit
# print lines reflect what audio should be playing before the next line of code is run
print("Start program actions")

# start prorgram once the button is pressed
while (PROGRAM_START == False):
    if button.is_pressed:
        PROGRAM_START = True

# once the button is pressed, start animatronic
if PROGRAM_START:
    # movement initialization
    leg_servo_front.min()
    leg_servo_back.min()
    head_servo.value = 0.0 # reset to face forward (at the left side of the board) TODO: tune value
    GPIO.output(port_or_pin, 0) # reset pneumatic position (if not already manually reset)

    print("Welcome to the creature exhibit at the Georgia state line visitor welcome center.")
    led.on() # white led color
    time.sleep(1) # wait 1 second

    print("As you travel further into Georgia...")
    for i in range(2): # walk cycle TODO: change for loop value to run for the right amount of time
        leg_servo_front.value = 0.0 # TODO: tune to the right value (from -1 to 1 where 0 is midpoint)
        leg_servo_back.value = 0.0 # TODO: tune to the right value
    time.sleep(1)

    head_servo.value = 0.0 # turn deer head toward the viewer # TODO: tune to the right value
    head_servo.value = 0.0 # turn deer head to face forward again # TODO: tune to the right value
    time.sleep(1)

    for i in range(2): # walk cycle TODO: change for loop value to run for the right amount of time
        leg_servo_front.value = 0.0 # TODO: tune to the right value (from -1 to 1 where 0 is midpoint)
        leg_servo_back.value = 0.0 # TODO: tune to the right value

    print("Fluttering nearby, you may see the Eastern Tiger Swallowtail...")
    GPIO.output(port_or_pin, 1)
    time.sleep(3) # TODO: adjust timing

    led.off()
    GPIO.cleanup()
    print("End program actions")
    PROGRAM_START = False