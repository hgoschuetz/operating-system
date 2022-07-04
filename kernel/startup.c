#include "keyboard.h"
#include "vga.h"

void test()
{
    print_string("Hello, World!\n");
    print_string("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

void kernel_startup()
{
    vga_init();

    test();
}