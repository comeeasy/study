#include <stdlib.h>
#include <stdio.h>
#define _USE_MATH_DEFINES_
#include <cmath>
#include <string.h>

#define FILE_SIZE 5000
// sample frequency
#define Fs 8000
#define PI M_PI

// signed 8 bit 
typedef char element;
typedef struct _Sample {
    element elem;
    double real;
    double imaginary;
} Sample;

// ================================================================

Sample* init_sample(Sample* sample);
Sample* copy_sample(Sample* sample);
Sample* get_sample(Sample* sample);
Sample calculate_X_k(Sample* sample, int k, int N);
Sample* rectangular(Sample* sample, int start, int end);
void window(Sample* sample, int N);