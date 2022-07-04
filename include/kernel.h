#ifndef KERNEL_H
#define KERNEL_H

#include "types.h"

#define NULL 0

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

uint8_t byte_in(uint16_t port);
void byte_out(uint16_t port, uint8_t data);
char get_input_keycode();
void sleep(uint32_t timer_count);

void printc(unsigned char c, uint8_t fg_color, uint8_t bg_color);
void print(unsigned char *s, uint8_t fg_color, uint8_t bg_color);

void vga_buffer_clear(uint16_t **vga_buffer, uint8_t bg_color);

void vga_buffer_init();

#endif