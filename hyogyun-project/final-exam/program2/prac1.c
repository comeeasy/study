#include <stdio.h>
#include <string.h>

int main() {
    FILE* fp;
    char buf[10000];

    fp = fopen("student(UTP-8).txt", "r");
    if(fp == NULL) {
        printf("file error\n");
        return 0;
    }

    fscanf(fp, "%s", buf);
    printf("%s\n", buf);
    fscanf(fp, "%s", buf);
    printf("%s\n", buf);
    fscanf(fp, "%s", buf);
    printf("%s\n", buf);

    return 0;
}