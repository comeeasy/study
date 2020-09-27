// ==========================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sort.h"

// ==========================================================

typedef struct _element {
    int key;
    char word[WORD_SIZE];
} element;

element dict[DICT_SIZE];

// ==========================================================

void SWAP(int* a, int* b) {
    if(*a == *b) return;

    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

char* characterize(int i, char buf[]) {
    int digit, num_of_digit=0;
    int key = dict[i].key;
    int word_length;

    while(key > 0) {
        digit = key % 10;
        key /= 10;
        buf[num_of_digit] = digit + '0';
        ++num_of_digit;
        //printf("digit %d key %d\n", digit, key);
    }

    //for(int j=0; j<num_of_digit; ++j) printf("buf[%d] = %c\n", j, buf[j]);

    for(int j=0; j<num_of_digit/2; ++j) {
        char tmp = buf[j];
        buf[j] = buf[num_of_digit-1-j];
        buf[num_of_digit-1-j] = tmp;
    }

    buf[num_of_digit] = ' ';
    strcpy(&buf[num_of_digit+1], dict[i].word);
    buf[num_of_digit + strlen(dict[i].word) + 1] = '\n';
    buf[num_of_digit + strlen(dict[i].word) + 2] = '\0';

    //printf("%s", buf);

    return buf;
}

int get_pivot(int low, int high) {
    //printf("%d ", rand()%(high+1) + low);
    return rand()%(high - low +1) + low;
}

int partition(int sorted_index[], int low, int high) {
    int pivot;
    int left = low+1, right = high;

    SWAP(&sorted_index[low], &sorted_index[get_pivot(low, high)]);
    pivot = dict[sorted_index[low]].key;

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
    char buf[WORD_SIZE];

    if(fp == NULL) {
        printf("file errer\n");
    }

    
    for(int i=0; i<file_size; ++i) {
        characterize(sorted_index[i], buf);
        fputs(buf, fp);
    }

    return fp;
}

void sort() {
    FILE* fp;
    int file_size;
    int sorted_index[DICT_SIZE];
    srand(time(NULL));

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
/*
int main() {
    dict[0].key = 202216;
    strcpy(dict[0].word, "Kafkaesque");
    char buf[WORD_SIZE];

    characterize(0, buf);
    return 0;
}
*/
// ==========================================================