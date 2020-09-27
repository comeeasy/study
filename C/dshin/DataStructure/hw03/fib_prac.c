#include <stdio.h>
#include <stdlib.h>

long fib_log(long n);

long fib(long n) {
    if(n == 1) return 1;
    else {
        return fib_log(n/2) + fib_log(n - n/2);
    }
}

long fib_log(long n) {
    long i, result;
    static int tabs=0;

    tabs++;
    for(i=0; i<tabs-1; ++i) printf()
}
