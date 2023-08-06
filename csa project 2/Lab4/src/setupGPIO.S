.section .text
.align 2
.globl setupGPIO
#include "memoryMap.inc"
#include "GPIO.inc"
//#define NEW_PIN 0x40000 //GPIO pin 2 offset
// LED_1,
//  LED_2,
//  LED_3,
//  OPEN_LED,
//  CLOSE_LED,
//  MOVING_LED,
//  OPEN_BTN,
//  CLOSE_BTN,
//  GO_BTN,
//  FLR1_BTN,
//  FLR2_BTN,
//  FLR3,BTN
/*
#define LED_1 0x40000
#define  LED_2 0x20000
#define  LED_3 0x10000
#define  OPEN_LED 0x8000
#define  CLOSE_LED 0x4000
#define  MOVING_LED 0x2000
#define  OPEN_BTN 0x00
#define  CLOSE_BTN 0x80000000
#define  GO_BTN 0x40000000
#define  FLR1_BTN 0x20000000
#define  FLR2_BTN 0x10000000
#define  FLR3_BTN 0x8000000
*/
setupGPIO:
 addi sp, sp, -16
# allocate a stack frame, moves the stack up by 16 bits
 sw ra, 12(sp)
 li t0, GPIO_CTRL_ADDR # load GPIO base address
# li t1, NEW_PIN  # load address of pin 2 into t1
# sw t1, GPIO_OUTPUT_EN(t0)
# write the GPIO RGP pins to GPIO Enable offset
# (Enable output on RGP pins so we can write)
li t1, OUTPUT_MASK
sw t1, GPIO_OUTPUT_EN(t0)

li t2, INTPUT_MASK
sw t2, GPIO_INPUT_EN(t0)
sw t2, GPIO_INPUT_PULUP(t0)

sw x0, GPIO_OUTPUT_VAL(t0)
lw ra, 12(sp) # return the return address
addi sp, sp, 16 # deallocate the stack
ret