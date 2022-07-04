#include "kernel.h"

uint8_t row = 0, col = 0;

uint16_t vga_format(unsigned char c, uint8_t fg_color, uint8_t bg_color)
{
  uint16_t ax = 0;
  uint8_t ah = 0, al = 0;

  ah = bg_color;
  ah <<= 4;
  ah |= fg_color;
  ax = ah;
  ax <<= 8;
  al = c;
  ax |= al;

  return ax;
}

void newline()
{
  if (row < N_ROWS - 1)
  {
    row++;
    col = 0;
    return;
  }

  // else: scroll
}

void printc(unsigned char c, uint8_t fg_color, uint8_t bg_color)
{
  if (c == '\n')
  {
    newline();
    return;
  }

  if (col > N_COLS - 1)
  {
    newline();
  }

  vga_buffer[col + N_COLS * row] = vga_format(c, fg_color, bg_color);

  col++;
}

void print(unsigned char *s, uint8_t fg_color, uint8_t bg_color)
{
  uint32_t i;
  for (i = 0; s[i] != '\0'; ++i)
  {
    printc(s[i], fg_color, bg_color);
  }
}

void vga_buffer_clear(uint16_t **vga_buffer, uint8_t bg_color)
{
  uint32_t i;
  for (i = 0; i < BUFSIZE; ++i)
  {
    (*vga_buffer)[i] = vga_format(NULL, NULL, bg_color);
  }
}

void vga_buffer_init()
{
  vga_buffer = (uint16_t *)VGA_ADDRESS;

  vga_buffer_clear(&vga_buffer, BLACK);
}