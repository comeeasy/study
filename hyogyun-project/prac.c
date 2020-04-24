#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int i = rand()%10;

    for(int j=0; j<100; ++j) {
        i = rand()%10; // 0 - 9 rand number
        printf("%d\n", i);
    }
    return 0;
}
