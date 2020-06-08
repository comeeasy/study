#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {

    // elem queue list
    Queue* sample;
    element tmp_elem;
    FILE* fp;

    sample = init_queue(sample);

    if( !(fp = fopen("sample1.snd", "rb")) ) {
        printf("파일을 여는데 실패했습니다.\n프로그램 종료\n");
        return 0;
    }

    while( fscanf(fp, "%c", &tmp_elem) != EOF) {
        enqueue(sample, tmp_elem);
    }

    fclose(fp);

    return 0;
}