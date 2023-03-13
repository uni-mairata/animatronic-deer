# imports
import time
from gpiozero import LED, Button, Servo # gpiozero library (installed by default in the Raspberry Pi OS Desktop image)

# TODO: fix port constants
# TODO: try coding servos based on --> https://github.com/fervanegas/Test_360servo
leg_servo_front = Servo(0)
leg_servo_back = Servo(0)
head_servo = Servo(0)
# figure out how to code pneumatics
led = LED(0)
button = Button(0)

PROGRAM_START = False

# based on this script - https://docs.google.com/document/d/1DNoGuv6uL_T2RtTujJc0lmIhl_3DgXTTr4SzQGK93f8/edit
# print lines reflect what audio should be playing before the next line of code is run
print("Start program")

# start prorgram once the button is pressed
if button.is_pressed:
    PROGRAM_START = True
else:
    PROGRAM_START = False

# once the button is pressed -
while PROGRAM_START:
    # initialization
    leg_servo_front.min()
    leg_servo_back.min()

    print("Welcome to the creature exhibit at the Georgia state line visitor welcome center.")
    led.on() # white led color
    time.sleep(1) # wait 1 second

    print("As you travel further into Georgia...")
    for i in range(2): # walk cycle TODO: change for loop value to run for the right amount of time
        leg_servo_front.value = 0.0 # TODO: tune to the right value (from -1 to 1 where 0 is midpoint)
        leg_servo_back.value = 0.0 # TODO: tune to the right value
        print("Testing servo loop" + str(i))
    head_servo = 0.0 # TODO: tune to the right value

    print("Fluttering nearby, you may see the Eastern Tiger Swallowtail...")

    led.off()
    print("End program")