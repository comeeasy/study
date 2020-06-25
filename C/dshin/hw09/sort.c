// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

// ======================================================================

typedef struct {
    int key;
    char word[WORD_SIZE];
} element;

element dict[DICT_SIZE];

// ======================================================================

void SWAP(int* a, int* b) {
    if(*a == *b) return;

    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int partition(int sorted_index[], int low, int high) {
    int pivot = dict[sorted_index[low]].key;
    int left = low+1, right = high;

    while(1) {
        while( dict[sorted_index[left]].key <= pivot && left <= high ) ++left;
        while( dict[sorted_index[right]].key > pivot && right >= low ) --right;
        if(left > right) break;
        SWAP( &sorted_index[left], &sorted_index[right]);
    }

    SWAP( &sorted_index[low], &sorted_index[right]);
    return right;
}

void quick_sort(int sorted_index[], int low, int high) {
    if (low < high) { 
        int q = partition(sorted_index, low, high);
        quick_sort(sorted_index, low, q - 1); 
        quick_sort(sorted_index, q + 1, high); 
    }  
}   


FILE* get_dictionary(FILE* fp, int* file_size) {
    if( !(fp = fopen(DICT_IN, "r")) )  {
        printf("file is not open\n");
        return NULL;
    }

    for(int i=0; i<DICT_SIZE; ++i) {
        fscanf(fp, "%d %s", &(dict[i].key), dict[i].word);
        if( dict[i].key == 0 ) {
            *file_size = i;
            break;
        }
    }

    //printf("file size = %d\n", *file_size-1);
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
    quick_sort(sorted_index, 0, file_size-1);

    // write dictionary
    fp = write_dictionary(fp, sorted_index, file_size);

    fclose(fp);
    return;
}

// ======================================================================
