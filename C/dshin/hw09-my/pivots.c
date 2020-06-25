// ==========================================================

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

// ==========================================================

typedef struct _element {
    int key;
    char word[WORD_SIZE];
} element;

typedef struct pivots {
    int left_pivot_index;
    int pivot;
    int right_pivot_index;
} Pivots; 

element dict[DICT_SIZE];

#define SWAP(x, y, t)   ((t) = (x)), ((x) = (y)), ((y) = (t))

// ==========================================================


Pivots partition(int sorted_index[], int low, int high, int pivot_index) {
    //int pivot = dict[sorted_index[low]].key;
    //int pivot_index = get_pivot(sorted_index, low, high);
    //int pivot_index = (low + high) / 2;
    int pivot;
    int left = low+1, right = high, tmp;
    Pivots pivots;

    SWAP(sorted_index[low], sorted_index[pivot_index], tmp);
    pivot = dict[sorted_index[low]].key;

    while(1) {
        while( dict[sorted_index[left]].key <= pivot && left <= high ) {
            if(dict[sorted_index[left]].key == ((pivot + low) / 2)) pivots.left_pivot_index = left;
            ++left;
        }
        while( dict[sorted_index[right]].key > pivot && right >= low ) {
            if(dict[sorted_index[right]].key == ((pivot + high) / 2)) pivots.right_pivot_index = right;
            --right;
        }
        
        if(left > right) break;
        SWAP( sorted_index[left], sorted_index[right], tmp);

        if(dict[sorted_index[left]].key == ((pivot + low) / 2)) pivots.left_pivot_index = left;
        if(dict[sorted_index[right]].key == ((pivot + high) / 2)) pivots.right_pivot_index = right;
    }

    SWAP( sorted_index[low], sorted_index[right], tmp);
    if(dict[sorted_index[left]].key == ((pivot + low) / 2)) pivots.left_pivot_index = left;
    if(dict[sorted_index[right]].key == ((pivot + high) / 2)) pivots.right_pivot_index = right;
    pivots.pivot = right;

    return pivots;
}

void quick_sort(int sorted_index[], int low, int high, int pivot_index) {
    printf("left %10d right %10d\n", low, high);

    if (low < high) { 
        Pivots q = partition(sorted_index, low, high, pivot_index);
        quick_sort(sorted_index, low, q.pivot - 1, q.left_pivot_index); 
        quick_sort(sorted_index, q.pivot + 1, high, q.right_pivot_index); 
    }  
}   


FILE* get_dictionary(FILE* fp, int* file_size) {
    if( !(fp = fopen(DICT_IN, "r")) )  {
        printf("file is not open\n");
        return NULL;
    }

    for(int i=0; i<DICT_SIZE; ++i) {
        fscanf(fp, "%d", &(dict[i].key));
        fscanf(fp, "%s", dict[i].word);
        if( dict[i].key == 0 ) {
            *file_size = i;
            break;
        }
    }

    printf("file size = %d\n", *file_size-1);
    return fp;
}

FILE* write_dictionary(FILE* fp, int sorted_index[], int file_size) {
    fp = fopen(DICT_OUT, "w");

    if(fp == NULL) {
        printf("file errer\n");
    }

    for(int i=0; i<file_size; ++i) {
        fprintf(fp, "%d %s\n", dict[sorted_index[i]].key, dict[sorted_index[i]].word);
    }

    return fp;
}

void sort() {
    FILE* fp;
    int file_size;
    int sorted_index[DICT_SIZE];

    for(int i=0; i<DICT_SIZE; ++i) sorted_index[i] = i;

    // get unsorted dictionary
    fp = get_dictionary(fp, &file_size);
    if(fp == NULL) return;

    // sort
    quick_sort(sorted_index, 0, file_size-1, 0);

    // write dictionary
    fp = write_dictionary(fp, sorted_index, file_size);

    fclose(fp);
    return;
}

// ==========================================================