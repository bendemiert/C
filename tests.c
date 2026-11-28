
#include <stdio.h>
#include <stdint.h>

void _p(uint16_t value)
{
    for (int i = 15; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
        if (i == 8)
            printf(" ");
    }
    printf("\n");
}

int main(void)
{
    uint8_t packet2 = 0x34;
    uint8_t packet3 = 0x12;

    _p(packet2);
    _p(packet3);
    uint16_t buf = packet2 | packet3;
    _p(buf);
    return 0;

    uint8_t *p = &packet3;

    uint16_t original = *p;
    uint16_t shifted = (uint16_t)*p << 8;
    uint16_t result = shifted | packet2;

        _p(original);
    // printf("ORIGINAL packet3:\n");
    // printf("BIN: "); _p(original);
    // printf("\nHEX: 0x%04X", original);
    // printf("\nDEC: %u\n\n", original);

    // printf("SHIFTED packet3 << 8:\n");
    _p(shifted);
    printf("\n");
    _p(shifted);
    _p(packet2);
    _p(result);

    // printf("\nHEX: 0x%04X", shifted);
    // printf("\nDEC: %u\n\n", shifted);
    // _p(packet2);
    // printf("RESULT shifted | packet2:\n");
    // printf("BIN: "); _p(result);
    // printf("\nHEX: 0x%04X", result);
    // printf("\nDEC: %u\n", result);

    

    return 0;
}
