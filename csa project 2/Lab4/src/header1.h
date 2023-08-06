#define DELAY 200
#define ON 0x01
#define OFF 0x00
#define NUM_LEDS 0x03
#define RED_LED 0x400000
#define BLUE_LED 0x200000
#define GREEN_LED 0x080000
#define NEW_PIN 0x40000

#define LED_1 0x40000 // PIN 2
#define  LED_2 0x80000 //PIN 3
#define  LED_3 0x100000 // PIN 4
#define  OPEN_LED 0x04 // PIN 10
#define  CLOSE_LED 0x400000 // PIN 6
#define  MOVING_LED 0x800000 // PIN 7
#define  OPEN_BTN 0x01 // PIN 8
#define  CLOSE_BTN 0x02 // PIN 9
#define  GO_BTN 0x800 // PIN 17
#define  FLR1_BTN 0x1000 // PIN 18
#define  FLR2_BTN 0x2000 // PIN 19
#define  FLR3_BTN 0x200000 // PIN 5

void setupGPIO();
int setLED(int color, int state);
void delay(int milliseconds);