#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

// =============================================================

typedef struct _element {
    int key;
    char word[WORD_SIZE];
} element;

element dict[DICT_SIZE];

// =============================================================

FILE* get_dictionary(FILE* fp, int* file_size) {
    if( !(fp = fopen(DICT_IN, "r")) )  {
        printf("file is not open\n");
        return NULL;
    }

    for(int i=0; i<DICT_SIZE; ++i) {
        fscanf(fp, "%d %s", &(dict[i].key), dict[i].word);
        if( dict[i].key == 0 ) {
            *file_size = i;
            break;
        }
    }

    //printf("file size = %d\n", *file_size-1);
    return fp;
}

int main() {
    mode_t mode = S_IRWXU;
    char buf[DICT_SIZE];
    int file_size, n;
    FILE* fp;

    fp = get_dictionary(fp, &file_size);

    int rfd = open("DICT_IN.txt", O_RDONLY, mode);
    if(rfd == -1) {
        printf("error1\n");
        exit(1);
    }

    int wfd = open("DICT_OUT.bak", O_CREAT | O_WRONLY | O_TRUNC, mode);
    if(wfd == -1) {
        printf("error2\n");
        exit(1);
    } 

    while((n = read(rfd, buf, 23) > 0)) {
        if(write(wfd, buf, n) != n)
            printf("error3\n");
    }

    if(n == -1) printf("error4\n");

    close(rfd);
    close(wfd);
    return 0;
}