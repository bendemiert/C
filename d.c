#include <stdio.h>
#include <stdint.h>

int main(){
    const char in[] = "wlan0";
    const char *in2 = "wlan0";


    printf("%c\n",*in);
    printf("%p\n",&in);
    printf("%s\n",in);

    printf("%s","\n====================================\n");
    
    printf("%p\n",(void*)in2);
    printf("%p\n",&in2);
    printf("%s\n",in2);
    printf("%c\n",*in2);

    
const char *ine = "asdf";
printf("%s\n", ine);       // asdf
printf("%c\n", *ine);      // a
printf("%p\n", (void *)ine);  // Adresse des Strings
printf("%p\n", (void *)&ine); // Adresse der Pointer-Variable
    
   return 0;

}