// ======================================================================
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include<string.h>


#define   MAX_LIST_LENGTH      1024*512
#define _CRT_SECURE_NO_WARNINGS


// ======================================================================

typedef struct {
  int key;
  char word[WORD_SIZE];
} element;

element dict[DICT_SIZE];

void quick_sort(element * list, int left, int right);
int partition(element * list, int left, int right);

// ======================================================================

void SWAP(element* arr, int a, int b)
{
    // 한 배열이 뭉탱이로 옮겨진다.
    element temp;
    temp = arr[a];
    arr[a] =arr[b];
    arr[b]=temp;
}
int partition(element * list, int left, int right)
{
    int low, high, pivot, temp;
    
    low=left;
    high=right+1;
    pivot=left;

    do {
     do
       low++;
     while (low<=right && list[low].key<list[pivot].key);
     do
       high--;
     while (high>=left && list[high].key>list[pivot].key);
     if (low<high)
       SWAP(list, low, high);
     }  while (low<high);
    SWAP (list, left, high);
    return high;
}

void quick_sort(element * list, int left, int right)
{
  if (left < right) {
   int q = partition(list, left, right);
    quick_sort(list, left, q - 1);
    quick_sort(list, q+1, right);
  }
}

void sort (void)
{
  // DICT_IN 읽어서 메모리의 배열 dict에 저장
  int i;

  FILE *fp = fopen(DICT_IN,"r");
  if (fp!=NULL)
    for (i=0 ; i<DICT_SIZE; i++) {
       fscanf(fp, "%d %s", &dict[i].key, dict[i].word);
    }

  // sorting
   element *sorted=dict;

  quick_sort(sorted, 0, DICT_SIZE - 1);

  // DICT_OUT만들기
  fp = fopen(DICT_OUT, "w");
  if (fp!=NULL)
    for(i=0 ; i<DICT_SIZE; i++)
        if (sorted[i].key!=0)
            fprintf(fp, "%d %s\n",sorted[i].key, sorted[i].word);
  fclose(fp);

}

// ======================================================================