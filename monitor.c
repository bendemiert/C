#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>


const char *interface = "wlan1";
char pfad[111];
uint64_t rx;
uint64_t old_rx;
uint64_t speed;

int main(void){
    
    snprintf(pfad, sizeof(pfad),
             "/sys/class/net/%s/statistics/rx_bytes", interface);
    FILE *f = fopen(pfad, "r");
    printf("fopen: %s\n", f ? "OK" : strerror(errno));

    while (1){
        rewind(f);
        fscanf(f, "%lu", &rx);
        speed = old_rx - rx;

        printf("\rRX: %lu bytes speed: %lu", (unsigned long)rx,(unsigned long)speed);
        fflush(stdout);
        sleep(1);
    }

    fclose(f);





    return 0;
}