#ifndef IO_H
#define IO_H

#include "types.h"

static uint8_t __inline__ inbyte(uint16_t port)
{
    uint8_t ret;
    __asm__ __volatile__("inb %1, %0"
                         : "=a"(ret)
                         : "d"(port));
    return ret;
}

static void __inline__ outbyte(uint16_t port, uint8_t data)
{
    __asm__ __volatile__("outb %0, %1" ::"a"(data), "d"(port));
}

#endif
