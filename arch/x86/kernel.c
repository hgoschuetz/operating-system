#include "kernel.h"
#include "types.h"
#include "keyboard.h"

uint8_t row = 0, col = 0;

uint8_t byte_in(uint16_t port)
{
    uint8_t ret;
    asm volatile("inb %1, %0"
                 : "=a"(ret)
                 : "d"(port));
    return ret;
}

void byte_out(uint16_t port, uint8_t data)
{
    asm volatile("outb %0, %1"
                 : "=a"(data)
                 : "d"(port));
}

char get_input_keycode()
{
    char ch = 0;
    while ((ch = byte_in(KEYBOARD_PORT)) != 0)
    {
        if (ch < 0)
            return ch;
    }
    return ch;
}

void wait_for_input(uint32_t timer_count)
{
    while (1)
    {
        asm volatile("nop");
        timer_count--;
        if (timer_count <= 0)
            break;
    }
}

void sleep(uint32_t timer_count)
{
    wait_for_input(timer_count);
}