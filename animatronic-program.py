# imports
import time
from gpiozero import LED, Button, Servo # gpiozero library (installed by default in the Raspberry Pi OS Desktop image)

# TODO: fix port constants
leg_servo_front = Servo(0)
leg_servo_back = Servo(0)
led = LED(0)
button = Button(0)

program_start = False

# based on this script - https://docs.google.com/document/d/1DNoGuv6uL_T2RtTujJc0lmIhl_3DgXTTr4SzQGK93f8/edit
# print lines reflect what audio should be playing before the next line of code is run
print("Start program")

# start prorgram once the button is pressed
if button.is_pressed:
    program_start = True
else: 
    program_start = False

# once the button is pressed -
while (program_start):
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

    led.off()
    print("End program")