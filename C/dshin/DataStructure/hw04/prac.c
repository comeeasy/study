#include <stdio.h>
#include <stdlib.h>

#define MAX_MAZE_SIZE 6

char map1[MAX_MAZE_SIZE][MAX_MAZE_SIZE] = {
    {'1','1','1','1','1','1'},
    {'e','0','1','0','0','1'},
    {'1','0','0','0','1','1'},
    {'1','0','1','0','1','1'},
    {'1','0','1','0','0','x'},
    {'1','1','1','1','1','1'}
};

int main() {
    char *pt1[6];
    char (*pt2)[6];

    pt2 = map1;
    //*pt2 = "hello";

    //printf("size of pt1 = %ld\n", sizeof(pt1));
    //printf("size of pt2 = %ld\n", sizeof(pt2));
    
    for(int i=0; i<MAX_MAZE_SIZE; ++i) printf("%p\n", pt2+i);

    return 0;
}