#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

int main(void)
{
    uint8_t paket[] = {
        0x10, 0x20, 0x30, 0x40,
        0x50, 0x60, 0x70, 0x80
    };

    uint8_t *start = paket;
    uint8_t *ende  = paket + 118;

    ptrdiff_t diff = start - ende;
    ptrdiff_t diff2 = ende -start;
    printf("%td %td", diff,diff2);
}