.equ GPIO_OUTPUT_EN, 0x008 # Enable Output to selected pins
.equ GPIO_OUTPUT_VAL, 0x00C # Set Output Value
.equ GPIO_OUTPUT_XOR, 0x040 # inverse logic on selected pins
.equ GPIO_INPUT_EN, 0x04 # Set Input enable for selected pins
.equ GPIO_INPUT_VAL, 0x00 # Read Input value of selected pins
.equ GPIO_INPUT_PULUP, 0x10 # enable pull up
.equ NEW_PIN, 0x40000 # GPIO pin 2 offset.
.equ GPIO_RGB_PINS, 0x680000 # All 3 LED's bit offset
.equ GPIO_RED_LED, 0x400000 # Red LED offset
.equ GPIO_BLUE_LED, 0x200000 # Blue LED offset
.equ GPIO_GREEN_LED, 0x080000 # Green LED offset 

.equ PIN_2, 0x40000 # GPIO pin 2 offset.

.equ LED_1, 0x40000 # PIN 2, led light corresponding to floor 1
.equ  LED_2, 0x80000 # PIN 3, led light corresponding to floor 2
.equ  LED_3, 0x100000 # PIN 4, led light corresponding to floor 3
.equ  OPEN_LED, 0x04 # PIN 10, led light corresponding to opening of elevator doors
.equ  CLOSE_LED, 0x400000 # PIN 6, led light corresponding to closing of elevator doors
.equ  MOVING_LED, 0x800000 # PIN 7, led light corresponding to moving of elevator 
.equ  OPEN_BTN, 0x01 # PIN 8, push button corresponding to opening of elevator doors
.equ  CLOSE_BTN, 0x02 # PIN 9, push button corresponding to closing of elevator doors
.equ  GO_BTN, 0x800 # PIN 17, push button corresponding to moving of elevator
.equ  FLR1_BTN, 0x1000 # PIN 18, push button corresponding to floor 1
.equ  FLR2_BTN, 0x2000 # PIN 19, push button corresponding to floor 2
.equ  FLR3_BTN, 0x200000 # PIN 5, push button corresponding to floor 3

.equ OUTPUT_MASK, 0xdc0004 # to enable the output of leds we have take bit 1 at its pin offset in a 32 bit and written an overall mask for all output LED pins
.equ INTPUT_MASK, 0x203803 # to enable the input of push buttons we have take bit 1 at its pin offset in a 32 bit and written an overall mask for all input push buttons
