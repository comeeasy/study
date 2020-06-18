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
        // 바꿔야할 수도 있는 index를 왼쪽에서부터 탐색한 후 대기
        while( list[compare_left]  <= pivot && compare_left <= right ) ++compare_left;
        // 위와 마찬가지이다.
        while( list[compare_right] >  pivot && compare_right >= left ) --compare_right;
        // 만약 low, high가 크로스 되었다면 왼쪽 array와 오른쪽 array가 구분 된 것이므로 break
        if(compare_left > compare_right) break;
        // 그렇지 않다면 두 값은 서로 바뀌어야하므로 swap
        SWAP(list[compare_left], list[compare_right], tmp);
    }

    // while문을 탈출했다는 것은 왼쪽과 오른쪽이 구별 되었다는 것이므로
    // pivot값을 그 사이에 넣어주고 high를 return한다. 이유는 위에서
    // 위에서 설명하였던것처럼 high가 pivot이 위치하기 적절하기 때문이다.
    SWAP(list[left], list[compare_right], tmp);
    return compare_right;
}
// ==============================================================