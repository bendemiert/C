#include <stdio.h>
#include <net/if.h>

int main(void) {
    const char *interface = "wlan1";
    char name[16];

    snprintf(name, sizeof(name), "%s", interface);

    printf("%zu\n",sizeof(name));
    printf("Interface: %s\n", name);
    printf("Pointer interface: %p\n", (void *)interface);
    printf("Array name: %s\n", name);
    printf("Adresse name: %p\n", (void *)name);
    printf("\n--- POINTER ---\n");

printf("interface p:        %p\n", (void*)interface);
printf("interface:          %02x\n", *interface);
printf("&interface p:       %p\n", (void *)&interface);
printf("interface p:        %p\n", interface);
printf("interface s:        %s\n", interface);


printf("name:             %p\n", (void *)name);
printf("&name:            %p\n", (void *)&name);
printf("&name[0]:         %p\n", (void *)&name[1]);

    return 0;
}