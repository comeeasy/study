#include "sample.h"

Sample* init_sample(Sample* sample) {
    sample = (Sample*)malloc(sizeof(Sample) * FILE_SIZE);

    for(int i=0; i<FILE_SIZE; ++i) {
        (sample + i)->elem = 0;
        (sample + i)->real = 0.0;
        (sample + i)->imaginary = 0.0;
    }

    return sample;
}

Sample* copy_sample(Sample* cp_sample, Sample* sample) {
    memcpy(cp_sample, sample, sizeof(Sample) * FILE_SIZE);
    return cp_sample;
}

Sample* get_sample(Sample* sample) {
    FILE* fp;

    if( !(fp = fopen("sample1.snd", "rb")) ) {
        printf("파일을 여는데 실패했습니다.\n프로그램 종료\n");
        return NULL;
    }

    int i=0;
    while( fscanf(fp, "%c", &((sample + i)->elem) ) != EOF) {
        //printf("elem[%d] = %d is input\n", i, (int)(sample + i)->elem);
        ++i;
    }

    fclose(fp);
    return sample;
}

Sample calculate_X_k(Sample* sample, int k, int N) {
    Sample tmp;
    //int N = end - start;
    double real = 0.0, imaginary = 0.0;

    for(int i=0; i<FILE_SIZE; ++i) {
                // x[n]
        real += ((sample + i)->elem)*cos(2*M_PI*k*i/N);
        //printf("x[%4d]: %5d, N: %d, kn: %12d, cos: %12f\n",i, (sample+i)->elem, N, k*i, cos(2*M_PI*k*i/N));
    }

    for(int i=0; i<FILE_SIZE; ++i) {
                // x[n]
        imaginary -= ((sample + i)->elem)*sin(2*M_PI*k*i/N);
    }

    //printf("real: %12f, imaginary: %12f\n", real, imaginary);

    tmp.elem = 0;
    tmp.real = real;
    tmp.imaginary = imaginary;

    return tmp;
}

Sample* rectangular_func(Sample* sample, int start, int end) {
    for(int i=0; i<FILE_SIZE; ++i) {
        if(i<start || i>=end) {
            (sample+i)->elem = 0;
        }
    }
    return sample;
}

void window(Sample* sample, int N) {
    Sample* cp_sample = init_sample(cp_sample);
    cp_sample = copy_sample(cp_sample, sample);

    Sample* rec_sample = init_sample(rec_sample);
    rec_sample = rectangular_func(cp_sample, 0, 500);
    for(int i=0; i<FILE_SIZE; ++i) *(cp_sample + i) = calculate_X_k(rec_sample, i, N);

    for(int i=0; i<FILE_SIZE; ++i) {
        printf("X[%4d] | real: %12f, imaginary: %12f\n", i, (cp_sample+i)->real, (cp_sample+i)->imaginary);
    }
}

/*
void window(Sample* sample, int N) {
    Sample* cp_sample = init_sample(cp_sample);

    // window size is 500
    if (N == 500) {
        printf("window 500\n");

        for(int i=0; i<10; ++i) {
            for(int j=0; j<500; ++j) {
                *(cp_sample + 500*i + j) = calculate_X_k(sample, 500*i, 500*i + 500, 500*i + j);
            }
        }

        for(int i=0; i<FILE_SIZE; ++i) {
            printf("X[%d] = %10f, %10f\n", i, (cp_sample+i)->real, (cp_sample+i)->imaginary);
        }
    }
    // window size is 1000
    else if(N == 1000) {
        printf("window 1000\n");


        for(int i=0; i<5; ++i) {
            for(int j=0; j<1000; ++j) {
                cp_sample[1000*i + j] = calculate_X_k(sample, 1000*i + j, 1000*i + j + 1000, 1000*i + j);
            }
        }
        for(int i=0; i<FILE_SIZE; ++i) {
            printf("X[%d] = %10f, %10f\n", i, (cp_sample+i)->real, (cp_sample+i)->imaginary);
        }
    }
    // window size is 2000
    else if(N == 2000) {
        printf("window 2000\n");


        for(int i=0; i<2; ++i) {
            for(int j=0; j<2000; ++j) {
                cp_sample[2000*i + j] = calculate_X_k(sample, 2000*i + j, 2000*i + j + 2000, 2000*i + j);
            }
        }
        for(int i=4; i<5; ++i) {
            for(int j=0; j<1000; ++j) {
                cp_sample[1000*i + j] = calculate_X_k(sample, 1000*i + j, 1000*i + j + 1000, 1000*i + j);
            }
        }
        for(int i=0; i<FILE_SIZE; ++i) {
            printf("X[%d] = %10f, %10f\n", i, (cp_sample+i)->real, (cp_sample+i)->imaginary);
        }
    }
    
    free(cp_sample);
}
*/