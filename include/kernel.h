#ifndef KERNEL_H
#define KERNEL_H

#include "types.h"

uint8_t byte_in(uint16_t port);
void byte_out(uint16_t port, uint8_t data);
char get_input_keycode();
void sleep(uint32_t timer_count);

#endif