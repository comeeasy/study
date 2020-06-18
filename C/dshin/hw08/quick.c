// ==============================================================

#include <stdio.h>
#include <stdlib.h>
#include "quick.h"

// ==============================================================

int partition(int list[], int left, int right) {
    int pivot = list[left];
    int compare_left = left+1, compare_right = right, tmp;

    while(1) {
        //for(int i=left; i<=right; ++i) printf("%d ", list[i]); printf("\n");

        while( list[compare_left]  <= pivot && compare_left <= right ) ++compare_left;
        while( list[compare_right] >  pivot && compare_right >= left ) --compare_right;
        if(compare_left > compare_right) break;
        SWAP(list[compare_left], list[compare_right], tmp);

        //printf("swaq %d %d\n", list[compare_right], list[compare_left]);
    }
    SWAP(list[left], list[compare_right], tmp);

    return compare_right;
}

// ==============================================================