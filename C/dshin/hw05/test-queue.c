// =========================================================

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// =========================================================

int main() {
    int item = 10, r;
    QUEUE q1;

    printf("==== test-queue ====\n");

    init_queue(&q1);
    print_queue(&q1);

    for(;;) {
        if(en_queue(&q1, item++) == ERROR) break;
        print_queue(&q1);
        if(en_queue(&q1, item++) == ERROR) break;
        print_queue(&q1);
        if(de_queue(&q1) == ERROR) break;
        print_queue(&q1);
    }

    r = full_queue(&q1);
    if(r != 1)  printf("ERROR: full_queue\n");
    else        printf("OK: full_enqeue\n");

    for(;;) {
        if(de_queue(&q1) == ERROR) break;
        print_queue(&q1);
        if(de_queue(&q1) == ERROR) break;
        print_queue(&q1);
        if(en_queue(&q1, item++) == ERROR) break;
        print_queue(&q1);
    }

    r = empty_queue(&q1);
    if(r != 1)  printf("ERROR: empty_queue\n");
    else        printf("OK: empty_queue\n");

    return EXIT_SUCCESS;
}