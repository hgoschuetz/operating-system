#include "vga.h"
#include "types.h"

uint16_t *vga_buffer;
uint16_t cursor_x, cursor_y;

uint8_t fg_color = WHITE;
uint8_t bg_color = BLACK;

uint16_t vga_format(unsigned char ch, uint8_t fg_color, uint8_t bg_color)
{
    uint16_t ax = 0;
    uint8_t ah = 0, al = 0;

    ah = bg_color;
    ah <<= 4;
    ah |= fg_color;
    ax = ah;
    ax <<= 8;
    al = ch;
    ax |= al;

    return ax;
}

void print_char(const char ch)
{
    if (ch == '\n')
    {
        cursor_x = 0;
        cursor_y++;
        return;
    }

    vga_buffer[cursor_x + VGA_COLS * cursor_y] = vga_format(ch, fg_color, bg_color);

    cursor_x++;
}

void print_string(const char *str)
{
    while (*str)
        print_char(*str++);
}

void print_int(const int n) {}

void flush_vga_buffer(void)
{
    uint32_t i;
    for (i = 0; i < VGA_BUFSIZE; ++i)
    {
        vga_buffer[i] = vga_format(NULL, NULL, bg_color);
    }
}

void vga_init(void)
{
    vga_buffer = (uint16_t *)VGA_ADDRESS;

    cursor_x = 0;
    cursor_y = 0;

    flush_vga_buffer();
}