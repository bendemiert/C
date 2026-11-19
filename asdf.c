#include <stdio.h>
#include <stdint.h>

int main(void)
{
    const uint8_t daten[] = {
        0x1A, 0x2B, 0x3C, 0x4D, 0x5E
    };

    const uint8_t d = *daten; 
    // AUFGABE 1:
// Gib alle fünf Werte des Arrays daten als Hexadezimalzahlen aus.
   // uint8_t i = 0;
    for(uint8_t i = 0; i<= 4; i++ ){
        printf("d: %d\n",(d + i));
        printf("\tdaten[%d]%X = %d\n",i, daten[i],i);
    }

// AUFGABE 2:
// Erstelle einen Pointer namens p, der auf das erste Element von daten zeigt.
// Gib über diesen Pointer das erste und das dritte Byte aus.
    uint8_t p = *daten;
    printf("erstes byte %b\n", (void *)&p);

// AUFGABE 3:
// Gib folgende drei Speicheradressen aus:
// - p
// - &p
// - &daten
// Verwende für die Adressen %p und den passenden (void *) Cast.

// nachtrag:

const uint8_t daten2[] = {0x1A, 0x2B, 0x3C, 0x4D, 0x5E};
const uint8_t *p2 = daten2;

printf("%p\n", (void *)p2);
printf("%p\n", (void *)&*p2);
/*
Beide Ausgaben zeigen dieselbe Adresse.
- *p greift auf den Wert an der Adresse zu.
- & holt die Adresse dieses Wertes wieder zurück.
- Daher hebt sich &*p praktisch wieder auf.

Merksatz: &*p ist wieder p.
*/

    return 0;
}