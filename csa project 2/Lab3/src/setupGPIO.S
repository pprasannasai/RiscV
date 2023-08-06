.section .text
.align 2
.globl setupGPIO
#include "memoryMap.inc"
#include "GPIO.inc"
#define NEW_PIN 0x40000 //GPIO pin 2 offset

setupGPIO:
 addi sp, sp, -16
# allocate a stack frame, moves the stack up by 16 bits
sw ra, 12(sp)
li t0, GPIO_CTRL_ADDR # load GPIO base address

# enable the output
li t1, OUTPUT_MASK
sw t1, GPIO_OUTPUT_EN(t0)

# enable the input
li t2, INPUT_MASK
sw t2, GPIO_INPUT_EN(t0)
sw t2, GPIO_INPUT_PULUP(t0)


# (Enable output on RGP pins so we can write)
 sw x0, GPIO_OUTPUT_VAL(t0)
 lw ra, 12(sp) # return the return address
 addi sp, sp, 16 # deallocate the stack
 ret

