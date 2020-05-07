// =======================================================

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// =======================================================

void init_stack(STACK* s) {
    s->top = -1;
}

// =======================================================

void print_stack(STACK* s) {
    int empty_stack(STACK* s);

    if(!empty_stack(s)) {
        printf("(%d:", s->top+1);
        for(int i=0; i<s->top; ++i) {
            printf("%d,", s->data[i]);
        }
        printf("%d)\n", s->data[s->top]);
    }
}

// =======================================================

int empty_stack(STACK* s) {
    return (s->top == -1 ? 1 : 0);
}

// =======================================================

int push_stack(STACK* s, int item) {
    if(s->top < MAX_STACK_SIZE-1) {
        s->data[++s->top] = item;
        return s->top;
    }
    else {
        return ERROR;
    }
}

// =======================================================

int pop_stack(STACK* s) {
    int tmp = s->data[s->top];

    if(!empty_stack(s)) {     
        (s->top)--;
        return tmp;
    }
    else {
        return ERROR;
    }
}

// =======================================================