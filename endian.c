#include <stdio.h>

int main(void) {
    unsigned int i = 0x12345678;
    i &= 0xFF;
    if (i == 0x78) printf("little endian\n");
    else printf("big endian\n");
}
