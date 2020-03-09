#include "./header/my_heap.h"

/*
      힙을 구현하기 위해선 배열을 이용한 이진 트리를 사용할 것이다.
      힙의 기본 구조는 부모 노드가 자식노드보다 크면 된다(== Max heap)
      or 작으면 된다.(== Min heap).

      root노드의 index 값은 1이다. 왜냐하면 index에 *2를 하면 왼쪽 자식,
      *2 + 1 을 하면 오른쪽자식으로 가게되며, 어떠한 자식노드에서도 /2 를 하면
      부모노드의 index가 나오기 때문이다.

      my_heap.h 에 배열의 최대크기를 MAX_COMPO로 설정해 놓았다

      upheap함수는 새로운 요소를 추가할 때 맨 밑에서부터 insertion sort
      의 방식으로 아래에서부터 올라와 자신의 자리에 올때까지 부모노드와 값을
      교환한다.

       downheap 함수는 힙에서 요소를 삭제할 때 가장 밑에 있는 요소를 root로 가져와
       내려가면서 자신의 자리를 찾는다.
*/

// k번쨰 요소를 upheap, 보통 요소를 추가할 때 사용하므로 ++n 이 들어갈
void up_heap(int container[], int k) {
    int v = container[k];

    // 부모 노드가 더 작다면
    while(container[k/2] <= v) {
        // insertrion and reindexing
        container[k] = container[k/2];
        k /= 2;
    }
    // assign appropriate value
    container[k] = v;
}
// 마지막 요소를 root 요소와 교환한 뒤 사용할 것이다.
//  자신의 자리까지 내려가는 함수
void down_heap(int container[], int n) {
    int checker, k=1; // for compare
    int v = container[1]; // root component

    // n이 마지막 요소의 index이므로 n/2가 마지막 요소의 부모 노드
    // --> n/2까지가 internal node
    while(k <= n/2) {
        // checker를 먼저 자식노드로 보냄
        checker = k<<1;
        // 왼쪽 자식, 오른쪽 자식중 누가 큰지 결정
        if(container[checker] < container[checker+1]) ++checker;
        if(v >= container[checker]) break;
        container[k] = container[checker];
        k = checker;
    }
    container[k] = v;
}

heap::heap() : n(0) {
    container[0] = INT_MAX;
    for(int i=1; i<MAX_COMPO; ++i) container[i] = 0;
}

void heap::push(int key) {
    container[++n] = key;
    up_heap(container, n);
}
int heap::top() const {return container[1];}
void heap::pop() {
    container[1] = container[n--];
    down_heap(container, n);
}
int is_2_square(int i) {
    while(i%2 == 0) i /= 2;
    if(i == 1) return 1;
    else       return 0;
}
void heap::show_heap() const {
    for(int i=1; i<=n; ++i) {
        cout << container[i] << ' ';
        if(is_2_square(i+1)) cout << endl;
    }
    cout << endl;
}
