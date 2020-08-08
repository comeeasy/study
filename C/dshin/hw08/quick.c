// ==============================================================

#include <stdio.h>
#include <stdlib.h>
#include "quick.h"

// ==============================================================
int partition(int list[], int left, int right) {
    // list의 가장 왼쪽에 있는 값을 pivot값으로 설정한다.
    int pivot = list[left];
    // low, high를 각각 compare_left, compare_right이라 하였고
    // 아래와 같이 초기화 하였다.
    int compare_left = left+1, compare_right = right, tmp;

    while(1) {
        while( list[compare_left]  <= pivot && compare_left <= right ) ++compare_left;
        while( list[compare_right] >  pivot && compare_right >= left ) --compare_right;
        if(compare_left > compare_right) break;
        SWAP(list[compare_left], list[compare_right], tmp);
    }

    SWAP(list[left], list[compare_right], tmp);
    return compare_right;
}
// ==============================================================