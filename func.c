#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

void bin(uint32_t wert)
{
    for (int i = 31; i >= 0; i--) {
        printf("%u", (wert >> i) & 1);
        if (i % 8 == 0 && i != 0)
            printf(" ");
    }
}
void bearbeiten(uint32_t *p, int a)
{
    for (int i = 0; i < a; i++){
        printf("%X\t",*(p));
        if (i>2 && i<5){ *(p+i) = 0xFF;}
        //*(p+i) = 0xef;
    }
     printf("\n%i %s",a,"\n====================================================\n");
}

int main(void)
{
    uint32_t daten[] = {
        0xaa, 0xba, 0xca, 0xda, 0xea, 0xfa, 0xaa
    };
    
    uint16_t daten2[] = { 0xaa, 0xbb, 0xaa, 0xba, 0xca, 0xda, 0xea, 0xfa, 0xaa,0xaa, 0xba, 0xca, 0xda, 0xea, 0xfa, 0xaa, 0xaa, 0xba, 0xca, 0xda, 0xea, 0xfa, 0xaa, 0xaa, 0xba, 0xca, 0xda, 0xea, 0xfa, 0xaa};



    uint32_t *p = daten;
    printf("%zu\n",sizeof(daten));
  
    printf("%zu - %zu",sizeof(daten),sizeof(daten2));
    uint64_t rx = 123456789;

printf("RX: %" PRIu64 "\n", rx);
    
  //  bearbeiten(p, an);
  // for (int i = 0; i < an; i++){ printf("%x  ",*(p+i));}

    p = p + 2;
    *p = 0xAAAA;

    //bearbeiten(p + 2,3);
   // for (int i = 0; i < an; i++){ printf("%x  ",*(p+i));}

    p = daten + 5;
    *p = 0xBBBB;

    // Hier alle Array-Werte ausgeben
    /*
warum ist     uint32_t daten[] = {
        0xaa, 0xba, 0xca, 0xda, 0xea, 0xfa, 0xaa
    };
    
    uint32_t *p = daten;
    printf("%lb\n",sizeof(daten));

sizeof(daten) = 11100 = 28?

Dein Array hat 7 Elemente vom Typ uint32_t.
Ein uint32_t hat 4 Bytes:
7 x 4 = 28 Bytes
    */

    return 0;
}