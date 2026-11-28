
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>

int main(void) {
    char zeichen = 'A';
    const char *text = "Hallo Welt";
    int zahl = -123;
    unsigned int uzahl = 123;
    long lzahl = 123456L;
    unsigned long ulzahl = 123456UL;
    long long llongzahl = 123456789LL;
    unsigned long long ullzahl = 123456789ULL;
    float fwert = 12.5f;
    double dwert = 123.456;
    uint8_t daten[] = {0x12, 0x34, 0x56, 0x78};
    size_t groesse = sizeof(daten);
    ptrdiff_t differenz = 3;
    uint8_t u8 = 255;
    uint16_t u16 = 65535;
    uint32_t u32 = 123456789;
    uint64_t u64 = 1234567890123ULL;
    int8_t s8 = -100;
    int16_t s16 = -12345;
    int32_t s32 = -123456789;
    int64_t s64 = -1234567890123LL;
    double wert = 12.5;
    char wort[] = "Hallo";
    int *p = &zahl;
    const char *lala = "asdf";

    printf("\nDATENTYPEN UND FORMAT-SPEZIFIZIERER\n");
    printf("==========================================\n");

    printf("\n[ char zeichen = 'A' ]\n");
    printf("%-25s -> %-12s %c\n", "zeichen", "%c", zeichen);

    printf("\n[ const char *text = \"Hallo Welt\" ]\n");
    printf("%-25s -> %-12s %s\n", "text", "%s", text);

    printf("\n[ int zahl = -123 ]\n");
    printf("%-25s -> %-12s %d\n", "zahl", "%d", zahl);

    printf("\n[ unsigned int uzahl = 123 ]\n");
    printf("%-25s -> %-12s %u\n", "uzahl", "%u", uzahl);

    printf("\n[ long lzahl = 123456L ]\n");
    printf("%-25s -> %-12s %ld\n", "lzahl", "%ld", lzahl);

    printf("\n[ unsigned long ulzahl = 123456UL ]\n");
    printf("%-25s -> %-12s %lu\n", "ulzahl", "%lu", ulzahl);

    printf("\n[ long long llongzahl = 123456789LL ]\n");
    printf("%-25s -> %-12s %lld\n", "llongzahl", "%lld", llongzahl);

    printf("\n[ unsigned long long ullzahl = 123456789ULL ]\n");
    printf("%-25s -> %-12s %llu\n", "ullzahl", "%llu", ullzahl);

    printf("\n[ float fwert = 12.5f ]\n");
    printf("%-25s -> %-12s %f\n", "fwert", "%f", fwert);

    printf("\n[ double dwert = 123.456 ]\n");
    printf("%-25s -> %-12s %f\n", "dwert", "%f", dwert);

    printf("\nPOINTER UND ADRESSEN\n");
    printf("==========================================\n");

    printf("\n[ int *p = &zahl ]\n");
    printf("%-25s -> %-12s %p Pointer-Adresse\n", "p", "%p", (void *)p);
    printf("%-25s -> %-12s %p Adresse des Pointers\n", "&p", "%p", (void *)&p);
    printf("%-25s -> %-12s %d Wert über Pointer\n", "*p", "%d", *p);

    printf("\n[ const char *lala = \"asdf\" ]\n");
    printf("%-25s -> %-12s %p Pointer-Adresse\n", "lala", "%p", (void *)lala);
    printf("%-25s -> %-12s %p Adresse des Pointers\n", "&lala", "%p", (void *)&lala);
    printf("%-25s -> %-12s %c Erstes Zeichen\n", "*lala", "%c", *lala);
    printf("%-25s -> %-12s %c Zweites Zeichen\n", "*(lala + 1)", "%c", *(lala + 1));
    printf("%-25s -> %-12s %s String-Inhalt\n", "lala", "%s", lala);

    printf("\nGROESSEN UND POINTER-DIFFERENZEN\n");
    printf("==========================================\n");

    printf("\n[ size_t groesse = sizeof(daten) ]\n");
    printf("%-25s -> %-12s %zu Bytes\n", "sizeof(daten)", "%zu", sizeof(daten));
    printf("%-25s -> %-12s %zu Bytes\n", "sizeof(zahl)", "%zu", sizeof(zahl));
    printf("%-25s -> %-12s %zu Bytes\n", "sizeof(p)", "%zu", sizeof(p));
    printf("%-25s -> %-12s %zu Bytes\n", "sizeof(daten[0])", "%zu", sizeof(daten[0]));
    printf("%-25s -> %-12s %zu Elemente\n", "sizeof(daten)/sizeof(daten[0])", "%zu", sizeof(daten) / sizeof(daten[0]));
    printf("%-25s -> %-12s %td\n", "differenz", "%td", differenz);

    printf("\nFESTE INTEGER-TYPEN (inttypes.h)\n");
    printf("==========================================\n");

    printf("\n[ uint8_t u8 = 255 ]\n");
    printf("%-25s -> %-12s %" PRIu8 "\n", "u8", "\"%\" PRIu8", u8);

    printf("\n[ uint16_t u16 = 65535 ]\n");
    printf("%-25s -> %-12s %" PRIu16 "\n", "u16", "\"%\" PRIu16", u16);

    printf("\n[ uint32_t u32 = 123456789 ]\n");
    printf("%-25s -> %-12s %" PRIu32 "\n", "u32", "\"%\" PRIu32", u32);

    printf("\n[ uint64_t u64 = 1234567890123ULL ]\n");
    printf("%-25s -> %-12s %" PRIu64 "\n", "u64", "\"%\" PRIu64", u64);

    printf("\n[ int8_t s8 = -100 ]\n");
    printf("%-25s -> %-12s %" PRId8 "\n", "s8", "\"%\" PRId8", s8);

    printf("\n[ int16_t s16 = -12345 ]\n");
    printf("%-25s -> %-12s %" PRId16 "\n", "s16", "\"%\" PRId16", s16);

    printf("\n[ int32_t s32 = -123456789 ]\n");
    printf("%-25s -> %-12s %" PRId32 "\n", "s32", "\"%\" PRId32", s32);

    printf("\n[ int64_t s64 = -1234567890123LL ]\n");
    printf("%-25s -> %-12s %" PRId64 "\n", "s64", "\"%\" PRId64", s64);

    printf("\nFORMATIERUNG UND BREITE\n");
    printf("==========================================\n");

    printf("\n[ double wert = 12.5 ]\n");
    printf("%-25s -> %-12s %.2f Zwei Nachkommastellen\n", "wert", "%.2f", wert);
    printf("%-25s -> %-12s %08.2f Nullen vorne\n", "wert", "%08.2f", wert);
    printf("%-25s -> %-12s %10.2f Rechtsbündig\n", "wert", "%10.2f", wert);
    printf("%-25s -> %-12s %7d Breite 7\n", "zahl", "%7d", zahl);
    printf("%-25s -> %-12s %-7d Linksbündig, Breite 7\n", "zahl", "%-7d", zahl);
    printf("%-25s -> %-12s %02X Hex, mindestens 2 Stellen\n", "15", "%02X", 15);

    printf("\nHEX UND OKTAL\n");
    printf("==========================================\n");

    printf("%-25s -> %-12s %x Hexadezimal klein\n", "uzahl", "%x", uzahl);
    printf("%-25s -> %-12s %X Hexadezimal gross\n", "uzahl", "%X", uzahl);
    printf("%-25s -> %-12s %o Oktal\n", "uzahl", "%o", uzahl);

    printf("\nSTRING-LAENGE\n");
    printf("==========================================\n");

    printf("\n[ char wort[] = \"Hallo\" ]\n");
    printf("%-25s -> %-12s %zu Bytes inklusive NULL\n", "sizeof(wort)", "%zu", sizeof(wort));
    printf("%-25s -> %-12s %zu Zeichen ohne NULL\n", "strlen(wort)", "%zu", strlen(wort));

    printf("\nENDE DES SPICKZETTELS\n");
    printf("==========================================\n");

    return 0;
}
