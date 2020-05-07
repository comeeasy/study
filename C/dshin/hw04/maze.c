// =======================================================

#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

// =======================================================

void print_maze(MAZE* maze) {
    for(int i=0; i<MAX_MAZE_SIZE; ++i) {
        for(int j=0; j<MAX_MAZE_SIZE; ++j) {
            if(i == maze->here_r && j == maze->here_c) printf("* ");
            else    printf("%c ", *(maze->map[i] + j));
        }
        printf("\n");
    }
}

// =======================================================

void push_loc(MAZE* maze, int r, int c) {
    push_stack(maze->stack, r);
    push_stack(maze->stack, c);

    print_stack(maze->stack);
}

// =======================================================

void search(MAZE* maze) {
    char tile;

    //동
    tile = *(maze->map[maze->here_r] + maze->here_c+1);
    if(tile == '0' || tile == 'x') {
        push_loc(maze, maze->here_r, maze->here_c+1);
    }
    //남
    tile = *(maze->map[maze->here_r + 1] + maze->here_c);
    if(tile == '0' || tile == 'x') {
        push_loc(maze, maze->here_r + 1, maze->here_c);
    }
     //서
    tile = *(maze->map[maze->here_r] + maze->here_c-1);
    if(tile == '0' || tile == 'x') {
        push_loc(maze, maze->here_r, maze->here_c-1);
    }
    //북
    tile = *(maze->map[maze->here_r - 1] + maze->here_c);
    if(tile == '0' || tile == 'x') {
        push_loc(maze, maze->here_r-1, maze->here_c);
    }
}
int run_maze(MAZE* maze) {
    if(*(maze->map[maze->here_r] + maze->here_c) == 'x') {
        return FOUND;
    }

    search(maze);
    *(maze->map[maze->here_r] + maze->here_c) = '*';
    maze->here_c = pop_stack(maze->stack);
    maze->here_r = pop_stack(maze->stack);

    if(maze->here_r == ERROR || maze->here_c == ERROR) {
        return FAILED;
    }
    else {
        return FINDING;
    }
}

// =======================================================
