// =======================================================

#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

// =======================================================

// maze.h에서 선언하였던 char (*map)[MAX_MAZE_SIZE]는 
// char크기(1 byte) * MAX_MAZE_SIZE 개의 크기를 갖는 메모리를
// 가리키는 char형을 가리키는 포인터이다. 따라서 maze->map[r]은
// r번째 row를 가리키며, char형을 가리키는 포인터이므로
// maze->map[r]+c 는 r번째 row에서 c번째 column을 의미한다.
// 따라서 (r,c)를 나타내기 위해 maze->map[r]+c 를 사용하겠다.

// (0,0) 부터 (5,5)까지 차례대로 출력하기 위해 이중 for문 사용
void print_maze(MAZE* maze) {
    // row
    for(int i=0; i<MAX_MAZE_SIZE; ++i) {
        // column
        for(int j=0; j<MAX_MAZE_SIZE; ++j) {
            // 나의 위치를 출력할 차례라면 '*' 출력
            if(i == maze->here_r && j == maze->here_c) printf("* ");
            // 그렇지 않다면 maze->map이 가리키는 메모리의 값을 참조하여 출력
            else    printf("%c ", *(maze->map[i] + j));
        }
        printf("\n");
    }
}

// =======================================================

void push_loc(MAZE* maze, int r, int c) {
    // (r, c)의 위치를 r, c 순서대로 maze안에 선언한 stack에
    // push
    push_stack(maze->stack, r);
    push_stack(maze->stack, c);
    // print stack
    print_stack(maze->stack);
}

// =======================================================

// 북서동남의 방향순서대로 갈 수 있는 방향을 검색해야하는데 
// 스택에 그 위치를 저장하고 다시 pop을 한다. 따라서 북서남동의
// 순서가 아닌 남동서북의 순서대로 넣고 pop하여 북서남동의 순서대로
// 다음 위치를 결정한다.

void search(MAZE* maze) {
    char tile;

    //동
    // 현재위치의 column이 벽에 붙어 있다면 
    if(maze->here_c < MAX_MAZE_SIZE-1) {
        tile = *(maze->map[maze->here_r] + maze->here_c+1);
        if(tile == '0' || tile == 'x') {
            push_loc(maze, maze->here_r, maze->here_c+1);
        }
    }
    //남
    if(maze->here_r < MAX_MAZE_SIZE-1) {
        tile = *(maze->map[maze->here_r + 1] + maze->here_c);
        if(tile == '0' || tile == 'x') {
            push_loc(maze, maze->here_r + 1, maze->here_c);
        }
    }
    //서
    if(maze->here_c > 0) {
        tile = *(maze->map[maze->here_r] + maze->here_c-1);
        if(tile == '0' || tile == 'x') {
            push_loc(maze, maze->here_r, maze->here_c-1);
        }
    }
    //북
    if(maze->here_r > 0) {
        tile = *(maze->map[maze->here_r - 1] + maze->here_c);
        if(tile == '0' || tile == 'x') {
            push_loc(maze, maze->here_r-1, maze->here_c);        
        }
    }
}

int run_maze(MAZE* maze) {
    // 현재 위치가 출구라면 Found
    if(*(maze->map[maze->here_r] + maze->here_c) == 'x') {
        return FOUND;
    }

    // 그렇지 않다면 북서남동의 순서대로 다음 방향을 조사
    search(maze);
    // 현재 위치에 이전 위치를 남기기 위해 '.'을 찍어놓는다.
    *(maze->map[maze->here_r] + maze->here_c) = '.';
    // 스택에서 다음 위치를 pop해 온다 넣을때는
    // r, c 순서대로 넣었으므로 꺼낼때는 c, r의 순서대로 꺼낸다.
    maze->here_c = pop_stack(maze->stack);
    maze->here_r = pop_stack(maze->stack);

    // here_r, here_c 가 ERROR 값을 갖고 있다면
    // stack이 비어 더 이상 pop할 것이 없어 ERROR값을 return
    // 한 것이므로 더 이상 갈 곳이 없음을 의미
    if(maze->here_r == ERROR || maze->here_c == ERROR) {
        return FAILED;
    }
    // 그렇지 않으면 아직 찾는중이므로 계속 진행
    else {
        return FINDING;
    }
}
// =======================================================
