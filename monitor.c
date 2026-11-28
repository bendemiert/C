
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

const char *interface = "wlan0";

int main(void) {
    char pfad[128];

    uint64_t rx = 0;
    uint64_t old_rx = 0;

    double dt, speed, mbps;

    struct timespec old_time, new_time;

    snprintf(pfad, sizeof(pfad),
             "/sys/class/net/%s/statistics/rx_bytes",
             interface);

    // Startwert lesen
    FILE *f = fopen(pfad, "r");

    if (f == NULL) {
        printf("Fehler: %s\n", strerror(errno));
        return 1;
    }

    fscanf(f, "%" SCNu64, &old_rx);
    fclose(f);

    clock_gettime(CLOCK_MONOTONIC, &old_time);

    printf("Interface: %s | Monitoring gestartet\n", interface);

    while (1) {
        // Datei für aktuelle Messung öffnen
        f = fopen(pfad, "r");

        if (f == NULL) {
            printf("\nFehler: %s\n", strerror(errno));
            break;
        }

        fscanf(f, "%" SCNu64, &rx);
        fclose(f);

        clock_gettime(CLOCK_MONOTONIC, &new_time);

        dt = (new_time.tv_sec - old_time.tv_sec)
           + (new_time.tv_nsec - old_time.tv_nsec) / 1e9;

        speed = (double)(rx - old_rx) / dt;
        mbps = speed * 8.0 / 1000000.0;

        printf("\r\033[KRX: %" PRIu64 " bytes | %06.2f B/s\t| %.2f Mbit/s",
               rx, speed, mbps);

        fflush(stdout);

        old_rx = rx;
        old_time = new_time;

        sleep(1);
    }

    return 0;
}
