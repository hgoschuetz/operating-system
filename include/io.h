#ifndef IO_H
#define IO_H

#include "types.h"

static uint8_t __inline__ inbyte(uint16_t port);
static void __inline__ outbyte(uint16_t port, uint8_t data);

#endif
