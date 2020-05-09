// =======================================================

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// =======================================================

/*
    top은 stack의 가장 위에 있는 요소의 index를 가리킨다. 
    top을 -1로 하는 이유는 만약 top을 0으로하게 된다면
    array의 0번째 인덱스에 요소가 존재 한다는 의미이므로
    정말 아무것도 없다는 것을 나타내기 위해 index 범위 밖인
    -1로 설정한것이다.

*/
void init_stack(STACK* s) { 
    s->top = -1;
}

// =======================================================

void print_stack(STACK* s) {
    // 16. 스택이 비어있는지 확인하기 위해 사용할 함수를 프로토타입 선언
    int empty_stack(STACK* s);

    // 스택이 비지 않았다면 (empty_stack은 만약 스택이 비었다면 1을 return할 것이다.)
    if(!empty_stack(s)) {
        // 스택의 요소의 수는 1부터 시작하는데 top은 0부터 시작하므로 
        // 요소의 개수를 나타내기 위해 top+1을 개수로 사용한다.
        printf("(%d:", s->top+1);
        // iterator를 설정해 0부터 top까지의 요소를 모두 출력한다.
        for(int i=0; i<s->top; ++i) {
            printf("%d,", s->data[i]);
        }
        printf("%d)\n", s->data[s->top]);
    }
    // 스택이 비었다면 아무것도 없음을 출력
    else {
        printf("(0: )\n");
    }
}

// =======================================================

int empty_stack(STACK* s) {
    // 스택이 비었다면 1을, 아니라면 0을 return
    return (s->top == -1 ? 1 : 0);
}

// =======================================================

int push_stack(STACK* s, int item) {
    // 스택이 꽉차지 않았다면
    // array의 마지막 요소는 MAX_STACK_SIZE-1 이므로
    // top이 MAX_STACK_SIZE-1 라면 스택이 꽉찬것이다.
    // 따라서 이 값보다 작다면 스택은 꽉차지 않은것이다.
    if(s->top < MAX_STACK_SIZE-1) {
        // 먼저 top을 1증가 시킨다음 그 자리에 item을 저장
        s->data[++s->top] = item;
        // top을 return
        // 즉 스택의 가장 위에 있는 요소의 index를 return
        return s->top;
    }
    // 스택이 꽉 찼다면
    else {
        return ERROR;
    }
}

// =======================================================

int pop_stack(STACK* s) {
    // 스택이 비지 않았다면
    if(!empty_stack(s)) {  
        // 스택 가장 위에 있는 값을 return
        // 그 값을 지우지 않는 이유는
        // push를 하더라도 자연스레 값이 덮어 씌워질 것이고
        // top이 한 칸 이전을 가리키기 때문에 잘못 접근하지 
        // 않기 떄문이다.   
        return s->data[s->top--];
    }
    // 스택이 비었다면 꺼낼 값이 없기 때문에 return ERROR
    else {
        return ERROR;
    }
}

// =======================================================