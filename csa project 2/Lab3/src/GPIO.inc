.equ GPIO_OUTPUT_EN, 0x008 # Enable Output to selected pins
.equ GPIO_OUTPUT_VAL, 0x00C # Set Output Value
.equ GPIO_OUTPUT_XOR, 0x040 # inverse logic on selected pins
.equ GPIO_INPUT_EN, 0x04 # Set Input enable for selected pins
.equ GPIO_INPUT_VAL, 0x00 # Read Input value of selected pins
.equ GPIO_INPUT_PULUP, 0x10 # enable pull up

.equ PIN_2, 0x40000 # GPIO pin 2 offset.

.equ GPIO_RGB_PINS, 0x680000 # All 3 LED's bit offset
.equ GPIO_RED_LED, 0x400000 # Red LED offset
.equ GPIO_BLUE_LED, 0x200000 # Blue LED offset
.equ GPIO_GREEN_LED, 0x080000 # Green LED offset

.equ RED_NS, 0x00040000  # PIN 2, red light for north south intersection
.equ RED_EW, 0x80000 # PIN 3 , red light for east west intersection
.equ YELLOW_NS, 0x100000 # PIN 4, yellow light for north south intersection
.equ YELLOW_EW, 0x200000 # PIN 5, yellow light for east west intersection
.equ GREEN_NS, 0x400000 # PIN 6, green light for north south intersection
.equ GREEN_EW, 0x800000 # PIN 7, green light for east west intersection
.equ PED_GREEN, 0x800 // PIN 17, green light for pedestrian
.equ PED_RED, 0x1000 // PIN 18, red light for pedestrian
.equ PUSH_NS, 0x01 # PIN 8, push button for pedestrian at north south intersection
//.equ PUSH_NS2, 0x40000000
.equ PUSH_EW, 0x02 # PIN 9, push button for pedestrian at north south intersection
//.equ PUSH_EW2, 0x10000000

.equ OUTPUT_MASK, 0xFC1800 //to enable the output of leds we have take bit 1 at its pin offset in a 32 bit and written an overall mask for all output LED pins
.equ INPUT_MASK, 0x03 //to enable the input of push buttons we have take bit 1 at its pin offset in a 32 bit and written an overall mask for all input push buttons