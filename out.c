#include <stdio.h>
#include <stdint.h>




int main(void){
    uint8_t d = 26;
    uint8_t *p = &d;

    printf("d    = %u\n", (unsigned int)d);    // Wert von d
    printf("&d   = %p\n", (void *)&d);         // Adresse von d
    printf("p    = %p\n", (void *)p);          // Adresse, die in p gespeichert ist (d)
    printf("*p   = %u\n", (unsigned int)*p);   // Wert an der Adresse von p
    printf("&p   = %p\n", (void *)&p);         // Adresse der Pointer-Variable p
    printf("*&d = %u\n", (unsigned int)*&d);   // Adresse von d dereferenziert: Wert von d

    return 0;
}