#include <stdio.h>
#include <stdint.h>

uint8_t is_minus(int a){
 return -a;
}


int main(void){
int a = 12;
int b = -11;

printf("a:%i\n",is_minus(a));
printf("b:%i\n", is_minus(b));
}
