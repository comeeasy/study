#include <stdio.h>

void swap(int* a ,int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertion(int dict[], int low, int high) {
    for(int i=low; i<high; ++i) {
        for(int j=i+1; j>low; --j) {
            if(dict[j] < dict[j-1] )
                swap(&dict[j], &dict[j-1]);
        }
        for(int i=0; i<10; ++i) printf("%d ", dict[i]); printf("\n");

    }
}

int main() {
    int arr[10];

    for(int i=0; i<10; ++i) {
        arr[i] = 10 - i;
    }
    for(int i=0; i<10; ++i) printf("%d ", arr[i]); printf("\n");
    insertion(arr, 0, 9);
    for(int i=0; i<10; ++i) printf("%d ", arr[i]); printf("\n");

    return 0;
}