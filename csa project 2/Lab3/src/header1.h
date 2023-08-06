#define DELAY 200
#define ON 0x01
#define OFF 0x00
#define NUM_LEDS 0x03

#define RED_LED 0x400000
#define BLUE_LED 0x200000
#define GREEN_LED 0x080000
#define NEW_PIN 0x40000

#define RED_NS 0x00040000  // PIN 2
#define RED_EW 0x80000 // PIN 3
#define YELLOW_NS 0x100000 //PIN 4
#define YELLOW_EW 0x200000 // PIN 5
#define GREEN_NS 0x400000 // PIN 6
#define GREEN_EW 0x800000 // PIN 7
#define PED_GREEN 0x800 // PIN 17
#define PED_RED 0x1000 // PIN 18
#define PUSH_NS 0x01 // PIN 8
#define PUSH_EW 0x02 // PIN 9

//#define PUSH_NS2 0x40000000

//#define PUSH_EW2 0x10000000

void setupGPIO();
int setLED(int color, int state);
void delay(int milliseconds);