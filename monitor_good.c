#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


const char *interface = "wlan0";
char pfad[111];


int main(void){
    uint64_t rx;
    double speed;
    uint64_t old_rx = 0;
    struct timespec old_time, new_time;

    snprintf(pfad, sizeof(pfad),
             "/sys/class/net/%s/statistics/rx_bytes", interface);
    FILE *f = fopen(pfad, "r");
    printf("fopen: %s\n", f ? "OK" : strerror(errno));


    //-------- TimeFuck
    clock_gettime(CLOCK_MONOTONIC, &old_time);
    double dt;

    while (1){
        rewind(f);
        fscanf(f, "%lu", &rx);

        //------- TimeFuck2
        clock_gettime(CLOCK_MONOTONIC, &new_time);

        dt = (new_time.tv_sec - old_time.tv_sec)
          + (new_time.tv_nsec - old_time.tv_nsec) / 1e9;
        speed = (rx - old_rx) / dt;
     
        old_time = new_time;
        //------- endTimeFucks 

        printf("\rRX: %lu bytes speed: %.2f",(unsigned long)rx,speed);
        fflush(stdout);
        sleep(1);
    }

    fclose(f);





    return 0;
}