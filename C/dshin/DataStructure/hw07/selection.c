//======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "selection.h"

//======================================================================

void selection_sort(int list[], int n) {
    int min_index;  // 적절한 값이 들어있는 index를 저장하기 위한 변수
    int tmp;        // SWAP 매크로를 이용하기 위한 임시 변수

    // 마지막 원소 전까지의 값만을 비교하면 되므로 마지막 인덱스인
    // n-1보다 1작은 값까지 start로 설정한다.
    // start는 적절한 값들이 들어있지 않은 index들의 시작점을 의미한다.
    for(int start=0; start<n-1; ++start) {
        // start에 들어있는 요소가 가장 작다고 가정한다.
        min_index = start;

        // start 부터 end까지 반복할 compare index
        // compare index는 start부터 end까지 각 값들을 비교해 적절한 값을 찾는
        // 역할을 한다.
        for(int compare=start+1; compare<n; ++compare) {
            // 가장 작다고 생각한 index의 값보다 compare에 있는 요소가 더 작다면
            // 그때의 compare가 min_index가 된다.
            if(list[compare] < list[min_index])
                min_index = compare;
        }
        // start 자리에 적절한 값을 넣어주고 값을 바꾼다.
        SWAP(list[min_index], list[start], tmp);
        print_array(list, n);
    }
}

//======================================================================

void selection_sort_recur(int list[], int start, int end) {
    int min_index, t;

    if(start == end) return;

    min_index = start;
    for(int i=start; i<end; ++i) {
        if(list[min_index] > list[i]) min_index = i;
    }    
    SWAP(list[start], list[min_index], t);

    print_array(list, end);
    selection_sort_recur(list, start+1, end);
}

//======================================================================
