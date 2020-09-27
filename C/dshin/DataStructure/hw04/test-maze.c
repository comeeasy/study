// =======================================================
#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
// =======================================================
// map 지정
char map1[MAX_MAZE_SIZE][MAX_MAZE_SIZE] = {
    {'1','1','1','1','1','1'},
    {'e','0','1','0','0','1'},
    {'1','0','0','0','1','1'},
    {'1','0','1','0','1','1'},
    {'1','0','1','0','0','x'},
    {'1','1','1','1','1','1'}
};
// =======================================================
int main() {
    // 
    // r 은 run_maze함수에서 반환할
    // FOUND FINDING FAIL 을 받을 변수이다.
    // step은 횟수를 의미한다.
    int r, step = 1;
    // maze를 받을 구조체 변수 선언
    MAZE maze1;

    // 위에서 만든 미로의 (0,0)(첫 번째 row, 첫 번째 column) 
    // 메모리를 가리키는 주소를 초기값으로 줌 
    maze1.map = map1;
    // maze의 stack에 메모리를 할당하고 초기화
    maze1.stack = malloc(sizeof(STACK));
    init_stack(maze1.stack);
    // 현재 위치 초기화
    maze1.here_r = 1;
    maze1.here_c = 0;

    for(;;) {
        printf("==step %d ==\n", step++);
        print_maze(&maze1);

        // 미로를 탈출하면서 목적지에 도착하였는지
        // 이 미로는 탈출할 수 없는지, 아직 찾고 있는중인지를
        // 매 loop마다 그 결과를 받는다.
        r = run_maze(&maze1);
        // 미로를 탈출할 수 없다면
        if(r == FAILED) {
            printf("FAILED!\n");
            break;
        }
        // 목적지에 도착하였다면
        if(r == FOUND) {
            printf("FOUND!\n");
            break;
        }
        // 그렇지 않다면 다시 loop 수행
    }
    return EXIT_SUCCESS;
}
// =======================================================
