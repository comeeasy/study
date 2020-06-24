// ==========================================================

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

// ==========================================================

typedef struct _element {
    int key;
    char word[WORD_SIZE];
} element;

// ==========================================================

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


int partition(element* words, int sorted_index[], int low, int high) {
    int pivot = (words+sorted_index[low])->key;
    int left = low+1, right = high;

    while(1) {
        while( (words+sorted_index[left])->key  <= pivot && left <= high ) ++left;
        while( (words+sorted_index[right])->key >  pivot && right >= low ) --right;
        if(left > right) break;
        swap( &(sorted_index[left]) , &(sorted_index[right]));
    }

    swap( &(sorted_index[low]), &(sorted_index[right]));
    return right;
}

void quick_sort(element* words, int sorted_index[], int low, int high) {
    if (low < high) { 
        int q = partition(words, sorted_index, low, high);
        quick_sort(words, sorted_index, low, q - 1); 
        quick_sort(words, sorted_index, q + 1, high); 
    }  
}   


FILE* get_dictionary(FILE* fp, element* words, int* file_size) {
    if( !(fp = fopen(DICT_IN, "r")) )  {
        printf("file is not open\n");
        return NULL;
    }

    for(int i=0; i<DICT_SIZE; ++i) {
        fscanf(fp, "%d", &((words+i)->key));
        fscanf(fp, "%s", (words+i)->word);
        if( (words+i)->key == 0 ) {
            *file_size = i;
            break;
        }
    }

    printf("file size = %d\n", *file_size-1);
    return fp;
}

FILE* write_dictionary(FILE* fp, element* words, int sorted_index[], int file_size) {
    fp = fopen(DICT_OUT, "w");

    if(fp == NULL) {
        printf("file errer\n");
    }

    for(int i=0; i<file_size; ++i) {
        fprintf(fp, "%d %s\n", (words+sorted_index[i])->key, (words+sorted_index[i])->word);
    }

    return fp;
}

int main() {
    FILE* fp;
    int file_size;
    element* words;
    int sorted_index[DICT_SIZE];

    // init words, sorted_index
    words = (element*)malloc(sizeof(element) * DICT_SIZE);
    for(int i=0; i<DICT_SIZE; ++i) sorted_index[i] = i;

    // get unsorted dictionary
    fp = get_dictionary(fp, words, &file_size);
    if(fp == NULL) return EXIT_FAILURE;

    // sort
    quick_sort(words, sorted_index, 0, file_size-1);

    // write dictionary
    fp = write_dictionary(fp, words, sorted_index, file_size);

    fclose(fp);
    free(words);
    return 0;
}

// ==========================================================