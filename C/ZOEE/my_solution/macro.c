#include <stdio.h>

#define PI 3.14
#define CIRCLE(r) (r)*(r)*PI
#define AREA(x, y) (x)*(y)

int main() {
    int x, y, r;

    printf("input r : ");
    scanf("%d", &r);

    printf("원의 넓이 : %f\n", CIRCLE(r));

    printf("input x, y : ");
    scanf("%d %d", &x, &y);

    printf("직사각형의 넓이: %d\n", AREA(x, y));

    return 0;
}
