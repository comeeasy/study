#include <stdio.h>

int main() {
    char c, C;

    printf("insert ch: ");
    scanf("%c", &c);

    C = c - 32;
    printf("%c\n", C);

    return 0;
}
