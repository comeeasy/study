// ====================================================================== 

#include <stdio.h>
#include <stdlib.h>
#include "bubble.h"

// ====================================================================== 

void bubble_sort(int list[], int n) {
    int tmp;

    for(int i=0; i<n-1; ++i) {
        for(int j=0; j<n-1-i; ++j) {
            if(list[j] > list[j+1])
                SWAP(list[j], list[j+1], tmp);
        }
        print_array(list, n);
    }
}

// ====================================================================== 