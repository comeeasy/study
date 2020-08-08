// =========================================================

#include <stdio.h>
#include <string.h>         // strcmp, strcpy, strlen 사용
#include <stdlib.h>

// =========================================================

#define ANIMAL_ANSI          "animal.txt"
#define ANIMAL_WRITE    "animal_new.txt"
#define WORD_SIZE           1024
#define NUM_WORD            36

// =========================================================

#define SWAP(x, y, t)   ((t)=(x)), ((x)=(y)), ((y)=(t))

// =========================================================

typedef struct _word {
    char korean_word[WORD_SIZE];
    char english_word[WORD_SIZE];
    int length_eng_word;
} Word;

// =========================================================

// 파일 입력
void write_dictionary(Word words[]);
// 파일 불러오기
void get_dictionary(Word words[]);
// 단어 정렬할 함수 삽입 정렬로 정렬
void insertion_sort(Word words[], int n);
// =========================================================

void insertion_sort(Word words[], int n) {
    Word tmp;

    for(int unsorted=1; unsorted<n; ++unsorted) {
        for(int to_insert=unsorted; to_insert>0; --to_insert) {
            // 
            if(strcmp(words[to_insert].english_word, words[to_insert-1].english_word) < 0)
                SWAP(words[to_insert], words[to_insert-1], tmp);
        }
    }
}
// =========================================================




void write_dictionary(Word words[]) {
    FILE* fp = fopen(ANIMAL_WRITE, "w");

    // 파일을 불러 읽고 에러가 있는지 체크
    if( fp == NULL) {
        printf("file open (write) error\n");
        return;
    }

    // 상단 메뉴 출력
    fprintf(fp, "한글\t\t영어\t\t철자수\n");
    fprintf(fp, "=================================================\n");

    for(int i=0; i<NUM_WORD; ++i) {
        // 한글 단어 출력
        // 4글자 단어 까지는 2번 탭
        if( strlen(words[i].korean_word) <= 12 )    
            fprintf(fp, "%s\t\t", words[i].korean_word);
        // 5글자 부터는 1번만 탭
        else                                        
            fprintf(fp, "%s\t", words[i].korean_word);

        // write english word
        // 9자 이하로는 2번 탭
        if( strlen(words[i].english_word) <= 9 )    
            fprintf(fp, "%s\t\t", words[i].english_word);
        // 10자 부터는 1번만 탭
        else                                        
            fprintf(fp, "%s\t", words[i].english_word);

        // 철자 수 입력
        fprintf(fp, "%d\n", strlen(words[i].english_word));
    }
   
    fclose(fp);
}
void get_dictionary(Word words[]) {
    FILE* fp;
    char buf[WORD_SIZE];

    // check file error
    if( (fp = fopen(ANIMAL_UTP, "r")) == NULL ) { 
        printf("file open error\n");
        return;   
    }

    // 상단 메뉴 버리기
    for(int i=0; i<4; ++i) fscanf(fp, "%s", buf);
    
    for(int i=0; i<NUM_WORD; ++i) {
        // get Korean word 
        fscanf(fp, "%s", words[i].korean_word);
        // get English word
        fscanf(fp, "%s", words[i].english_word);
        // '-' 버리기
        fscanf(fp, "%s", buf);
    }

    fclose(fp);
}

int main() {
    Word words[NUM_WORD];

    // 파일 읽어서 words에 저장
    get_dictionary(words);
    // 정렬
    insertion_sort(words, NUM_WORD);
    // 정렬된 array들을 다시 파일에 입력
    write_dictionary(words);

    return 0;
}