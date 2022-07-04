#include "drivers/keyboard.h"
#include "drivers/io.h"
#include "vga.h"
#include "types.h"

void test()
{
    print_string("Hello, World!");
}

void kernel_startup()
{
    vga_init();

    test();
}