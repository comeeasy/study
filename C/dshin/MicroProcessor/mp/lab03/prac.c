#include <stdio.h>

unsigned getNthBit(unsigned int apsr, int n) {
    int mask = 1 << n;
    return apsr & mask ? 1 : 0;
}

int main() {
    unsigned apsr = 0x00ff00f0;

    for(int i=31; i >= 0 ; --i) {
        printf("%d", getNthBit(apsr, i));
    }
    
    printf("\n");
}