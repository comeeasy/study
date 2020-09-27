#include <stdio.h>

typedef struct point {
    int x, y;
} Point;

Point* insert(Point p1, int x, int y) {
    p1.x = x;
    p1.y = y;

    return &p1;
} 

int main() {
    Point p1;
    Point* p2;

    p2 = insert(p1, 3, 4);

    printf("%d, %d\n", p1.x, p1.y);
    return 0;
}
