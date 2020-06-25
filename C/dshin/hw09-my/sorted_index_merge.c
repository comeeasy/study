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

// ==========================================================

int select_func(element* list[], int sorted_index[], int* compare_left, int* compare_right, int mid, int right) {
    if( *compare_left <= mid && *compare_right <= right ) {
        if(list[sorted_index[*compare_left]]->key <= list[sorted_index[*compare_right]]->key)   
            return sorted_index[(*compare_left)++];
        else                                                        
            return sorted_index[(*compare_right)++]; 
    }
    else {
        if(*compare_left > mid) return sorted_index[(*compare_right)++];
        else                    return sorted_index[(*compare_left)++];
    }
}

void merge(element* list[], int sorted_index[], int left, int mid, int right) {
    int n = right - left + 1;
    int* copy = (int*)malloc(sizeof(int) * n);
    int compare_left = left, compare_right = mid + 1;

    for(int i=0; i<n; ++i)
        copy[i] = select_func(list, sorted_index, &compare_left, &compare_right, mid, right);
    for(int i=0; i<n; ++i) 
        sorted_index[i + left] = copy[i];
    
    free(copy);
}

void merge_sort(element* list[], int sorted_index[], int left, int right) {                   
    int mid;                                                         
    if (left < right) {                                              
        mid = (left + right) / 2;                                    
        merge_sort(list, sorted_index, left, mid);                             
        merge_sort(list, sorted_index, mid + 1, right);                        
        merge(list, sorted_index, left, mid, right);                               
    }                                                                
}   

FILE* get_dictionary(FILE* fp, element* words[], int* file_size) {
    if( !(fp = fopen(DICT_IN, "r")) )  {
        printf("file is not open\n");
        return NULL;
    }

    for(int i=0; i<DICT_SIZE; ++i) {
        words[i] = (element*)malloc(sizeof(element)); 

        fscanf(fp, "%d", &((words[i])->key));
        fscanf(fp, "%s", (words[i])->word);
        if( (words[i])->key == 0 ) {
            *file_size = i;
            break;
        }
    }

    printf("file size = %d\n", *file_size-1);
    return fp;
}

FILE* write_dictionary(FILE* fp, element* words[], int sorted_index[], int file_size) {
    fp = fopen(DICT_OUT, "w");

    if(fp == NULL) {
        printf("file errer\n");
    }

    for(int i=0; i<file_size; ++i) {
        fprintf(fp, "%d %s\n", (words[sorted_index[i]])->key, (words[sorted_index[i]])->word);
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
    int sorted_index[DICT_SIZE];

    // init words, sorted_index
    for(int i=0; i<DICT_SIZE; ++i) sorted_index[i] = i;

    // get unsorted dictionary
    fp = get_dictionary(fp, words, &file_size);
    if(fp == NULL) return EXIT_FAILURE;

    // sort
    merge_sort(words, sorted_index, 0, file_size-1);

    // write dictionary
    fp = write_dictionary(fp, words, sorted_index, file_size);

    delete_elements(words, file_size);
    fclose(fp);
    return 0;
}

// ==========================================================