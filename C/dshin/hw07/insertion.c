// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "insertion.h"

// ======================================================================

void swap(int* x, int* y) {
    int tmp;
    
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void insertion_sort(int list[], int n) {
    for(int i=1; i<n; ++i) {
        for(int j=i; j>0; --j) {
            if(list[j] < list[j-1])
                swap(&list[j], &list[j-1]);
        }
        print_array(list, n);
    }
}

// ======================================================================