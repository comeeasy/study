#include <stdio.h>

int main() {
    int x = 0;
    int y = 2013124124;

    x ^= y;
    y ^= x;
    x ^= y;

    printf("x %d y %d\n", x, y);
    return 0;
}