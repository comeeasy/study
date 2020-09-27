// =================================================

#include <stdio.h>
#include <stdlib.h>
#include "merge.h"

// =================================================
/*
    왼쪽이나 오른쪽 array에 비교할 값들이 남아있다면 하나씩 값들을
    비교하여 copy array에 저장하는 것이 맞지만 그렇지 않다면 남은 값들을
    하나씩 넣어주면 된다.
*/

int select_func(int list[], int* compare_left, int* compare_right, int mid, int right) {
    // 왼쪽과 오른쪽 모두 비교할 값들이 남아있다면,
    if( *compare_left <= mid && *compare_right <= right ) {
        // 비교하여 적절한 값 return
        if(list[*compare_left] <= list[*compare_right]) return list[(*compare_left)++];
        else                                            return list[(*compare_right)++]; 
    }
    // 아니라면 둘 중에 남아있는 값들을 비교하지 않고 줄줄이 return
    else {
        if(*compare_left > mid) return list[(*compare_right)++];
        else                    return list[(*compare_left)++];
    }
}

void merge(int list[], int left, int mid, int right) {
    // size of list
    // 왼쪽 array와 오른쪽 array의 크기를 합친 크기만큼만
    // 비교하여 새로운 배열에 순서대로 저장할 것이므로 이를 n이라 하자
    int n = right - left + 1;
    // array for sorted
    // 정렬된 값들을 저장할 array
    int* copy = (int*)malloc(sizeof(int)*n);
    // 비교하면서 하나씩 커질 indeics
    // 왼쪽에서 값을 비교할 compare_left
    // 오른쪽에서 값을 비교할 compare_right을 선언한다.
    int compare_left = left, compare_right = mid + 1;

    for(int i=0; i<n; ++i)
        // 왼쪽과 오른쪽 array들의 값을 하나씩 비교하여 순서대로 copy array
        // 에 저장한다. 
        copy[i] = select_func(list, &compare_left, &compare_right, mid, right);
    for(int i=0; i<n; ++i)
        // 다시 원래 list로 저장한 값들을 복사한다. 
        list[i + left] = copy[i];
    
    free(copy);
}
// =================================================