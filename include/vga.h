#pragma once

#define VGA_ADDRESS 0xB8000
#define VGA_BUFSIZE 1920

#define VGA_ROWS 24
#define VGA_COLS 80

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

void print_char(const char ch);
void print_string(const char *str);
void print_int(const int n);

void vga_init(void);