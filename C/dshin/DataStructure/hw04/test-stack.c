// =======================================================

#include <stdio.h>
#include <stdlib.h>
// 해당 디렉토리에 있는 stack.h라는 파일을 헤더파일로 사용
#include "stack.h"

// =======================================================

int main() {
    int i, r;
    // 스택 선언
    STACK s1;
    printf("===== test-stack =====\n");
    // 위에서 선언한 스택을 초기화 (top <- -1)
    init_stack(&s1);
    // 비어있는 스택 출력
    print_stack(&s1);

    // 0부터 스택 최대 사이즈보다 100큰 값까지 넣을거야
    for(i=0; i<MAX_STACK_SIZE+100; ++i) {
        // push_stack 함수의 return 값이 ERROR인 경우는
        // 스택이 꽉찬 경우이므로 아무것도 하지 않게 된다.
        if(push_stack(&s1, i) == ERROR) break;
        // 그렇지 않고 push가 성공적으로 이루어진 경우
        // 스택의 내용을 출력한다.
        print_stack(&s1);
    }
    // MAX_STACK_SIZE+100번 pop을 수행한다.
    for(i=0; i<MAX_STACK_SIZE+100; ++i) {
        // pop에 실패했을 경우, 즉 스택이 비었을경우
        // 아무것도 하지 않는다.
        if(pop_stack(&s1) == ERROR) break;
        // pop이 성공적으로 이루어진 경우 스택을 출력
        print_stack(&s1);
    }

    // 위 모든 수행이 끝났을 때 스택이 정상적인 상태인지 점검
    // r이 1이 아니라면 top이 -1이 아니라 그 미만 이거나
    // 스택에 무언가 남아있다는것인데 0부터 11가지 정상적으로 push가 되고
    // 112번 pop하여 하나도 남음이 없어야한다. 즉 top이 -1보다 작은 값을
    // 갖지 않는지 확인하는 것이다.
    r = empty_stack(&s1);
    // top이 제 위치에 없다면 ERROR 다시 코드 작성해
    if(r != 1)  printf("ERROR: stack_empty\n");
    // top이 제 위치에 가있으므로 정상 종료
    else        printf("OK: stack_empty\n");

    return EXIT_SUCCESS;
}