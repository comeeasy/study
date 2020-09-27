#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

// ==========================================================

typedef struct _element {
    int key;
    char word[WORD_SIZE];
} element;

element dict[DICT_SIZE];

// ==========================================================

FILE* get_dictionary(FILE* fp, int* file_size) {
    if( !(fp = fopen(DICT_IN, "r")) )  {
        printf("file is not open\n");
        return NULL;
    }

    for(int i=0; i<10; ++i) {
        //fscanf(fp, "%d %s", &(dict[i].key), dict[i].word);
        fread(&dict[i], sizeof(element), 1, fp);

        printf("key: %10d word: %100s\n", dict[i].key, dict[i].word);

        if( dict[i].key == 0 ) {
            *file_size = i;
            break;
        }
    }

    printf("file size = %d\n", *file_size-1);
    return fp;
}

int main() {
    FILE* fp;
    int file_size;

    fp = get_dictionary(fp, &file_size);
    return 0;
}