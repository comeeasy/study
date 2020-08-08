// =========================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ANIMAL_ANSI "animal(ANSI).txt"
#define ANIMAL_UTP  "animal(UTP-8).txt"
#define ANIMAL_WRITE_UTP "animal_new.txt"
#define WORD_SIZE 1024
#define NUM_WORD 36

// =========================================================

#define SWAP(x, y, t)   ((t)=(x)), ((x)=(y)), ((y)=(t))

// =========================================================

typedef struct _word {
    char korean_word[WORD_SIZE];
    char english_word[WORD_SIZE];
    int length_eng_word;
} Word;

// =========================================================

FILE* write_dictionary(FILE* fp, Word words[]);
FILE* get_dictionary(FILE* fp, Word words[]);

// =========================================================

int partition(Word words[], int left, int right) {
    char pivot[WORD_SIZE];
    int compare_left = left+1, compare_right = right;
    Word tmp;

    strcpy(pivot, words[left].english_word);
    while(1) {
        while( strcmp(words[compare_left].english_word, pivot) < 0 && compare_left <= right ) {
            ++compare_left;
        }
        while( strcmp(words[compare_right].english_word, pivot) > 0 && compare_right >= left ) {
            --compare_right;
        }
        if(compare_left > compare_right) break;

        SWAP(words[compare_left], words[compare_right], tmp);
    }

    SWAP(words[left], words[compare_right], tmp);
    return compare_right;
}

void quick_sort(Word words[], int left, int right) {
    if (left < right) { 
        int q = partition(words, left, right);
        quick_sort(words, left, q - 1); 
        quick_sort(words, q + 1, right); 
    }  
}    

// =========================================================

FILE* write_dictionary(FILE* fp, Word words[]) {
    char intro[4][WORD_SIZE];

    if( (fp = fopen(ANIMAL_UTP, "r")) == NULL ) {
        printf("file open error\n");
        return NULL; 
    }
    
    for(int i=0; i<4; ++i) {
        fscanf(fp, "%s", intro[i]);
        intro[0][strlen(intro[i])] = '\t';
        intro[0][strlen(intro[i])] = '\0';
    }

    fclose(fp);

    fp = fopen(ANIMAL_WRITE_UTP, "w");
    if( fp == NULL) printf("file open (write) error\n");

    fprintf(fp, "%s\t\t%s\t\t%s\n", &intro[0][0], &intro[1][0], &intro[2][0]);
    fprintf(fp, "%s\n", &intro[3][0]);

    for(int i=0; i<NUM_WORD; ++i) {
        fprintf(fp, "%s%s%d\n", words[i].korean_word, words[i].english_word, words[i].length_eng_word);
    }

    return fp;
}

FILE* get_dictionary(FILE* fp, Word words[]) {
    char buf[WORD_SIZE];

    if( (fp = fopen(ANIMAL_UTP, "r")) == NULL ) { 
        printf("file open error\n");
        return NULL;   
    }

    for(int i=0; i<4; ++i) {
        fscanf(fp, "%s", buf);
    }

    for(int i=0; i<NUM_WORD; ++i) {
        int len;

        // get korean words
        fscanf(fp, "%s", words[i].korean_word);
        len = strlen(words[i].korean_word);
        if(strlen(words[i].korean_word) <= 12) {   
            words[i].korean_word[len] = '\t';
            words[i].korean_word[len+1] = '\t';
            words[i].korean_word[len+2] = '\0';
        }
        else {
            words[i].korean_word[len] = '\t';
            words[i].korean_word[len+1] = '\0';
        }
    
        // get eng words
        fscanf(fp, "%s", words[i].english_word);
        // get length of eng words
        words[i].length_eng_word = strlen(words[i].english_word);
        len = strlen(words[i].english_word);

        if(strlen(words[i].english_word) <= 9) {
            words[i].english_word[len] = '\t';
            words[i].english_word[len+1] = '\t';
            words[i].english_word[len+2] = '\0';
        }
        else {
            words[i].english_word[len] = '\t';
            words[i].english_word[len+1] = '\0';
        }
        fscanf(fp, "%s", buf);
        buf[0] = '\0';
        printf("%2d : %s%s%d\n", i, words[i].korean_word, words[i].english_word, words[i].length_eng_word);
    }

    return fp;
}

int main() {
    Word words[NUM_WORD];
    FILE* fp;

    fp = get_dictionary(fp, words);
    
    

printf("sorting start\n");

    quick_sort(words, 0, NUM_WORD-1);

printf("sorting ned\n");

    fp = write_dictionary(fp, words);

    fclose(fp);
    return 0;
}