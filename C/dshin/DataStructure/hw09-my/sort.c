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

void sort() {
    FILE* fp;
    element words[DICT_WORD];

     if( !(fp = fopen(DICT_IN, "r")) )  {
        printf("file is not open\n");
        return NULL;
    }

    fread(words, sizeof(element), 1, fp);
    printf("%d %s\n", words[0]->key, words[0]->word);
    
    fclose(fp);
    return 0;
}

// ==========================================================