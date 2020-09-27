// ==========================================================

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

// ==========================================================

#define SWAP(x, y, t)   ((t) = (x)), ((x) = (y)), ((y) = (t))

// ==========================================================

typedef struct _element {
    int key;
    char word[WORD_SIZE];
} element;

// ==========================================================

int partition(element* words[], int low, int high) {
    //int pivot = *(words+sorted_index[low])->key;
    int pivot = (words[low])->key;
    int left  = low+1, right = high;
    element* tmp;

    while(1) {
        while( (words[left])->key  <= pivot && left <= high ) ++left;
        while( (words[right])->key >  pivot && right >= low ) --right;
        if(left > right) break;
        SWAP(words[left], words[right], tmp);
    }

    SWAP(words[low], words[right], tmp);
    return right;
}

void quick_sort(element* words[], int low, int high) {
    if (low < high) { 
        int q = partition(words, low, high);
        quick_sort(words, low, q - 1); 
        quick_sort(words, q + 1, high); 
    }  
}   

FILE* get_dictionary(FILE* fp, element* words[], int* file_size) {
    if( !(fp = fopen(DICT_IN, "r")) )  {
            printf("file is not open\n");
            return NULL;
        }

    for(int i=0; i<DICT_SIZE; ++i) {
        words[i] = (element*)malloc(sizeof(element));

        fscanf(fp, "%d", &(words[i])->key);
        fscanf(fp, "%s", (words[i])->word);
       if( (words[i])->key == 0 ) {
            *file_size = i;
            break;
        }
    }

    printf("file size = %d\n", *file_size);
    return fp;
}

FILE* write_dictionary(FILE* fp, element* words[], int file_size) {
    fp = fopen(DICT_OUT, "w");

    if(fp == NULL) {
        printf("file errer\n");
    }

    for(int i=0; i<file_size; ++i) {
        fprintf(fp, "%d %s\n", (words[i])->key, (words[i])->word);
    }

    return fp;
}

void delete_elements(element* words[], int file_size) {
    for(int i=0; i<=file_size; ++i) {
        free(words[i]);
    }
}

int main() {
    FILE* fp;
    int file_size;
    element* words[DICT_SIZE];

    // get unsorted dictionary
    fp = get_dictionary(fp, words, &file_size);
    if(fp == NULL) return EXIT_FAILURE;

    // sort
    quick_sort(words, 0, file_size-1);
    
    // write dictionary
    fp = write_dictionary(fp, words, file_size);
    

    delete_elements(words, file_size);
    fclose(fp);
    return 0;
}
