#include "kernel.h"

void kernel_startup()
{
    vga_buffer_init();
    print("Hello, World", YELLOW, BLACK);
}