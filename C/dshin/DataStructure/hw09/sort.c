// ==========================================================

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

// ==========================================================

typedef struct _element {
    int key;
    char word[WORD_SIZE];
} element;

element dict[DICT_SIZE];

// ==========================================================

/*
    정렬에서 가장 많이 사용되는 swap함수를 경량화하는게 중요하다고 생각되어
    매크로로도 해보고 포인터로도 해보고 여러가지 방법으로 시행하다가 비트연산이
    가장 빠르다고 생각되어 아래와 같이 swap하는 방법을 떠올렸지만 성능이 그렇게
    향상 되진 않았다.
*/

void SWAP(int* a, int* b) {
    if(*a == *b) return;

    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

/*
    hw08에서 배웠던 quick sort를 그대로 사용할 것이다. 다른 점은 위에서 설명한 바와 같이
    실제로 비교는 정렬된 인덱스 sorted_index를 이용하여 dict에 접근할 것이며 중요한 점은
    비교는 실제 dict[sorted_index].key 로 비교하지만 두 값을 비교할 때는 
    sorted_index만 서로 교환한다는 점이다.
*/

int partition(int sorted_index[], int low, int high) {
    int pivot = dict[sorted_index[low]].key;
    int left = low+1, right = high;

    while(1) {
        // 실제 element의 key값을 비교
        while( dict[sorted_index[left]].key <= pivot && left <= high ) ++left;
        while( dict[sorted_index[right]].key > pivot && right >= low ) --right;
        if(left > right) break;
        // sorted_index를 swap
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
/*
    파일의 크기는 모른다고 가정 하였다.
    처음에는 DICT_SIZE 만큼 모두 불러 읽어 들였는데 더 이상 단어가 존재하지 않으면
    key값으로 0을 읽어 들여서 62 - 64번째 줄처럼 그 값을 file_size라고 한고
    return fp;
*/   
    for(int i=0; i<DICT_SIZE; ++i) {
        fscanf(fp, "%d %s", &(dict[i].key), dict[i].word);
        if( dict[i].key == 0 ) {
            *file_size = i;
            break;
        }
    }

    return fp;
}

FILE* write_dictionary(FILE* fp, int sorted_index[], int file_size) {
    fp = fopen(DICT_OUT, "w");

    if(fp == NULL) {
        printf("file errer\n");
    }
/*
    정렬된 sorted_index를 0부터 file_size-1까지 순서대로 출력한다면 
    위에서 설명했던바와 같이 실제로 정렬한것같은 순서대로 파일에 출력될 것이다.
*/
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

    // 파일을 읽어온다
    fp = get_dictionary(fp, &file_size);
    if(fp == NULL) return;

    // 정렬한다
    quick_sort(sorted_index, 0, file_size-1);

    // 정렬된 사전을 다시 쓴다
    fp = write_dictionary(fp, sorted_index, file_size);

    fclose(fp);
    return;
}

// ==========================================================
