
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <pcap.h>

#define INTERFACE "wlan1"
#define PACKETS 3

int main(void)
{
    char errbuf[PCAP_ERRBUF_SIZE];

    pcap_t *handle = pcap_open_live(
        INTERFACE, 65535, 1, 1, errbuf
    );

    if (handle == NULL) {
        fprintf(stderr, "Fehler: %s\n", errbuf);
        return 1;
    }

    if (pcap_datalink(handle) != DLT_IEEE802_11_RADIO) {
        fprintf(stderr, "Kein Radiotap-Format!\n");
        pcap_close(handle);
        return 1;
    }

    for (int p = 1; p <= PACKETS; ) {
        struct pcap_pkthdr *header;
        const u_char *packet;

        int result = pcap_next_ex(handle, &header, &packet);

        if (result == 0)
            continue;

        if (result == -1) {
            fprintf(stderr, "pcap Fehler: %s\n",
                    pcap_geterr(handle));
            break;
        }

        if (result == -2)
            break;

        printf("\n========== PAKET %d ==========\n", p);
        printf("pcap_next_ex: %d\n", result);
        printf("Aufgezeichnet: %u Bytes\n", header->caplen);
        printf("Ursprünglich:  %u Bytes\n", header->len);

        if (header->caplen >= 4) {
            uint16_t rt_len =
                packet[2] | ((uint16_t)packet[3] << 8);

            if (rt_len <= header->caplen &&
                header->caplen - rt_len >= 2) {
                const uint8_t *frame = packet + rt_len;

                printf("Frame Control: %02X %02X\n",
                       frame[0], frame[1]);
            } else {
                printf("Kein vollständiger WLAN-Frame\n");
            }
        }

        for (uint32_t i = 0; i < header->caplen; i++) {
            // if (i % 16 == 0)
            //     printf("\n%04X: ", i);

            unsigned char c = packet[i];
            //printf("%02X ", packet[i]);
            if (isprint(c)) {
               // printf("%c\n", c);
            } else {
                printf("");
            }
            //printf("%c", c);
        }
for (int i = 72; i < 100; i++) {
    printf("%d: %02X (%c)\n", i, packet[i],
           isprint((unsigned char)packet[i]) ? packet[i] : '.');
}
        printf("\n");
        printf("P72:\t%c\n", packet[72]);
        printf("Packet36: %2X\nPacket37:%2X\n", packet[36],packet[37]);
        fflush(stdout);
        p++;
    }

    pcap_close(handle);
    printf("\nFertig.\n");

    return 0;
}
