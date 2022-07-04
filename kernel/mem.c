#include "mem.h"
#include "types.h"

unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count)
{
    uint32_t i;
    for (i = 0; i < count; ++i)
        dest[i] = src[i];
    return dest;
}

unsigned char *memset(unsigned char *dest, unsigned char val, int count)
{
    uint32_t i;
    for (i = 0; i < count; ++i)
        dest[i] = val;
    return dest;
}