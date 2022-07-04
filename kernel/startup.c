#include "kernel.h"
#include "keyboard.h"

void test()
{
    print("Hello, World!", YELLOW, BLACK);
}

void kernel_startup()
{
    vga_buffer_init();
}