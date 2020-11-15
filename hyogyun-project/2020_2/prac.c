result = 1;

for(int i=1; i<end; ++i) {
    result *= i;

    if(i >= start) {
        printf("fact(%d)=%d\n", i, result)
    }
}