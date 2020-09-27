// =======================================================
#include <stdio.h>
#include <stdlib.h>
// strcpy, strlen 함수를 사용하기 위한 라이브러리
#include <string.h>
// 해당 소스코드가 있는 디렉토리의 match.h를 include
#include "match.h"
// =======================================================
void match(char* expr) {
    // stack 선언
    STACK stack;
    // 새로운 변수 str에 expr+1만큼의 메모리를 할당한다.
    // +1을 한 이유는 '\0' 때문이다.
    char* str = (char*)malloc(sizeof(char)*strlen(expr)+1);
    char tmp;
    
    // str에 expr를 옮긴다.
    strcpy(str, expr);
    // stack 초기화
    init_stack(&stack);

    // index를 0부터 str의 길이만큼 반복
    for(int i=0; i<strlen(str); ++i) {
        // 왼쪽 괄호라면
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
            tmp = push_stack(&stack, str[i]);
            // 스택에 push를 시도했는데 return값으로 ERROR값을 받으면
            // 즉 스택이 꽉 차있으면
            if(tmp == ERROR) {
                // ERROR문구를 출력하고 종료
                printf("FAIL at %d\n", i);
                return;
            }  
        }
        // 오른쪽 괄호라면
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']') {
            // 비교할 스택의 가장 위에 있는 요소를 받아온다.
            tmp = pop_stack(&stack);
            // 오른쪽 괄호가 나와서 이전에 들어가있어야할 왼쪽 괄호를 
            // pop했는데 없다? 그러면 FAIL 그리고 함수 종료
            if(tmp == ERROR) {
                printf("FAIL at %d\n", i);
                return;
            }
            // pop이 성공했어도 match가 안될 수 있다.
            else {
                if((str[i] == ')' && tmp != '(')||
                   (str[i] == '}' && tmp != '{')||
                   (str[i] == ']' && tmp != '[') ) {
                    // 그렇다면 FAIL, 함수 종료
                    printf("FAIL at %d\n", i);
                    return;
                } 
            }
        } 
    }
    
    // 모든 문자를 비교하여 for문을 탈출했는데  
    // stack에 괄호가 남아있다면 왼쪽괄호가 오른쪽 괄호보다 많다는 것
    // 따라서 잘못된 괄호이다.

    // 만약 스택이 비어있다면 MATCH
    if(empty_stack(&stack) == 1) printf("MATCH\n");
    // 그렇지 않다면 FAIL
    else                         printf("FAIL at %ld\n", strlen(str));
    // 메모리 해제
    free(str);
}

// =======================================================