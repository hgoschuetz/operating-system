#ifndef KERNEL_H
#define KERNEL_H

#define NULL 0

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

#define VGA_ADDRESS 0xB8000
#define BUFSIZE 2200

#define N_COLS 80
#define N_ROWS 24

uint16_t *vga_buffer;

enum vga_color
{
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARK_GREY,
    BRIGHT_BLUE,
    BRIGHT_GREEN,
    BRIGHT_CYAN,
    BRIGHT_RED,
    BRIGHT_MAGENTA,
    YELLOW,
    WHITE,
};

void printc(unsigned char c, uint8_t fg_color, uint8_t bg_color);
void print(unsigned char *s, uint8_t fg_color, uint8_t bg_color);

void vga_buffer_clear(uint16_t **vga_buffer, uint8_t bg_color);

void vga_buffer_init();

#endif