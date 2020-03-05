#include <stdio.h>
#include <stdlib.h>

// kind of insertion sorting
void upheap(int a[], int k) {
    int v;

    v = a[k];
    a[0] = INT_MAX;
    // if parent node's key is smaller than of child
    while(a[k/2] <= v) {
        a[k] = a[k/2];
        k /= 2;
    }
    a[k] = v;
}

// kind of insertion sort
void downheap(int a[], int n, int k) {
    int v = a[k];
    // if a[k] is inner node
    while(k <= n/2) {
        i = k << 1;
        if(i < n && a[i] < a[i+1]) ++i;
        if(v >= a[i]) break;

        a[k] = a[i];
        k = i;
    }
    a[k] = v;
}

void insert(int a[], int* n, int v) {
    a[++(*n)] = v;
    upheap(a, *n);
}

int extract(int a[], int* n) {
    int v = a[1];
    a[1] = a[(*n)--];
    downheap(a, *n, 1);
    return v;
}

void heap_sort(int a[], int n) {
    int hn=0;
    for(int i=1; i<=n; ++i) insert(a, &hn, a[i]);
    for(int i=hn; i>=n; --i) a[i] = extract(a, &hn);
}
