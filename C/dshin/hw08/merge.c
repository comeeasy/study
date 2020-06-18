// =================================================

#include <stdio.h>
#include <stdlib.h>
#include "merge.h"

// =================================================

int select_func(int list[], int* compare_left, int* compare_right, int mid, int right) {
    if( *compare_left <= mid && *compare_right <= right ) {
        if(list[*compare_left] <= list[*compare_right]) return list[(*compare_left)++];
        else                                            return list[(*compare_right)++]; 
    }
    else {
        if(*compare_left > mid) return list[(*compare_right)++];
        else                    return list[(*compare_left)++];
    }
}

void merge(int list[], int left, int mid, int right) {
    // size of list
    int n = right - left + 1;
    // array for sorted
    int* copy = (int*)malloc(sizeof(int)*n);
    // 비교하면서 하나씩 커질 indeics
    int compare_left = left, compare_right = mid + 1;

    for(int i=0; i<n; ++i) {
        copy[i] = select_func(list, &compare_left, &compare_right, mid, right);
    }
    for(int i=0; i<n; ++i) {
        list[i + left] = copy[i];
    }
    
    free(copy);
}


// =================================================