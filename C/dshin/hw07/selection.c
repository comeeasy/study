//======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "selection.h"

//======================================================================

void selection_sort(int list[], int n) {
    int min_index;
    int tmp;

    for(int i=0; i<n-1; ++i) {
        min_index = i;
        for(int j=i+1; j<n; ++j) {
            if(list[j] < list[min_index])
                min_index = j;
        }
        SWAP(list[min_index], list[i], tmp);
        print_array(list, n);
    }
}