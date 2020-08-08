// ====================================================================== 

#include <stdio.h>
#include <stdlib.h>
#include "bubble.h"

// ====================================================================== 
void bubble_sort(int list[], int n) {
    // for SWAP macro
    int tmp;

    // popped_bubble은 정렬된 요소들의 개수를 의미하며 3.1에서의 설명에서 
    // 펑 터진 버블들은 더 이상 고려하지 않겠다는 의미
    // n-1번만 뽀글뽀글을 하는 이유는 n-1번 하면 마지막 남은 요소는 
    // 이미 정렬된 상태이기 때문이다.
    for(int popped_bubble=0; popped_bubble<n-1; ++popped_bubble) {
        // bubble은 이제 위로 올라가 펑 터질 bubble의 위치(=인덱스)를 의미한다.
        // 0부터 시작하여 n-1개에서 이미 터진 bubble들보다 작은 위치까지만 올라간다.
        for(int bubble=0; bubble<n-1-popped_bubble; ++bubble) {
            // bubble이 데리고 있는 요소가 다음 요소보다 더 크다면 swap (데려감)
            if(list[bubble] > list[bubble+1])
                SWAP(list[bubble], list[bubble+1], tmp);
            // 그렇지 않다면 bubble만 1 증가하여 다음 요소를 bubble에 태워 데려간다.
        }
        print_array(list, n);
    }
}
// ====================================================================== 