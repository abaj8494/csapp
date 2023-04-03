#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;
        // if you think about it a char is just a byte

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

// functions to dangerously typecast into a bytepointer

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

int main(int argc, char *argv[])
{
    if (argc != 2) {fprintf(stderr, "Usage %s <num>\n", argv[0]); return 1;}
    int i = atoi(argv[1]);
    int f = atof(argv[1]);
    int *ip = &i;

    show_int(i);
    show_float(f);
    show_pointer(ip);
}
