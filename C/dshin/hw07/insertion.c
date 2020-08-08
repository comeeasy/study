// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "insertion.h"

// ======================================================================
// swap 함수
void swap(int* x, int* y) {
    int tmp;
    
    tmp = *x;
    *x = *y;
    *y = tmp;
}
void insertion_sort(int list[], int n) {
    // unsorted index는 정렬되지 않은 오른쪽 요소들의 가장 왼쪽 요소를 가리키며
    // 마지막 요소까지 모두 '정렬된 상태'로 만들어야한다.
    for(int unsorted=1; unsorted<n; ++unsorted) {
        // to_insert는 정렬되지 않은 요소들중 가장 왼쪽에 있는 요소의 index이며
        // 적절히 정렬된 위치로 데려다줄 index이다.
        // 0 인덱스 이전의 값과는 비교할 수 없으므로 0보다 클 때 비교한다.
        for(int to_insert=unsorted; to_insert>0; --to_insert) {
            // 만약 이전의 요소의 값이 더 크다면 swap
            if(list[to_insert] < list[to_insert-1])
                swap(&list[to_insert], &list[to_insert-1]);
            // 그렇지 않으면 아무것도 하지않으므로 to_insert는 1까지 가서 for문을
            // 탈출
        }
        print_array(list, n);
    }
}
// ======================================================================