// =======================================================

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// =======================================================

int main() {
    int i, r;
    STACK s1;

    printf("===== test-stack =====\n");

    init_stack(&s1);
    print_stack(&s1);

    for(i=0; i<MAX_STACK_SIZE+100; ++i) {
        if(push_stack(&s1, i) == ERROR) break;
        print_stack(&s1);
    }

    for(i=0; i<MAX_STACK_SIZE+100; ++i) {
        if(pop_stack(&s1) == ERROR) break;
        print_stack(&s1);
    }

    r = empty_stack(&s1);
    if(r != 1)  printf("ERROR: stack_empty\n");
    else        printf("OK: stack_empty\n");

    return EXIT_SUCCESS;
}