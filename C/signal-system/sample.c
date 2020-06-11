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
        ++i;
    }

    fclose(fp);
    return sample;
}

Sample calculate_X_k(Sample* sample, int k, int N) {
    Sample tmp;
    //int N = end - start;
    double real = 0.0, imaginary = 0.0;
    char x[FILE_SIZE];

    for(int i=0; i<FILE_SIZE; ++i) {
        x[i] = (sample+i)->elem;
    }

    for(int i=0; i<FILE_SIZE; ++i) {
                // x[n]
        real += x[i]*cos(2*M_PI*k*i/N);
    }

    for(int i=0; i<FILE_SIZE; ++i) {
                // x[n]
        imaginary -= x[i]*sin(2*M_PI*k*i/N);
    }

    tmp.elem = (sample+k)->elem;
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
    Sample* rec_sample;

    for(int i=0; i<FILE_SIZE/N; ++i) {
            cp_sample = copy_sample(cp_sample, sample);
            rec_sample = rectangular_func(cp_sample, N*i, N*(i+1));
            
            printf("\n=============== window: %d |%d to %d| ===============\n", N, i*N, (i+1)*N);
            printf("\n주파수 성분\nX[k]\n\n");
            for(int k=0; k<FILE_SIZE; ++k) *(cp_sample + k) = calculate_X_k(rec_sample, k, N);

            for(int i=0; i<N; ++i) {
                if( (cp_sample+i)->imaginary > 0.01 || (cp_sample+i)->imaginary < -0.01 || (cp_sample+i)->real > 0.01 || (cp_sample+i)->real < -0.01)
                    printf("X[%4d] | real: %12f, imaginary: %12f\n", i, (cp_sample+i)->real, (cp_sample+i)->imaginary);
                    //printf("%g\n",(cp_sample+i)->imaginary);
            }

            printf("\n진폭 스펙트럼\n|Xk|\n\n");
            for(int i=0; i<N; ++i) {
                if( (cp_sample+i)->imaginary > 0.01 || (cp_sample+i)->imaginary < -0.01 || (cp_sample+i)->real > 0.01 || (cp_sample+i)->real < -0.01)
                    printf("|X_%-4d| = %12f\n", i, sqrt((cp_sample+i)->imaginary*(cp_sample+i)->imaginary  + (cp_sample+i)->real*(cp_sample+i)->real ) );
                    //printf("%g\n", sqrt((cp_sample+i)->imaginary*(cp_sample+i)->imaginary  + (cp_sample+i)->real*(cp_sample+i)->real ) );
            }
            
            printf("\n\n위상 스펙트럼\n<X_k\n\n");
            for(int i=0; i<N; ++i) {
                if( (cp_sample+i)->imaginary > 0.01 || (cp_sample+i)->imaginary < -0.01 || (cp_sample+i)->real > 0.01 || (cp_sample+i)->real < -0.01)
                    printf("<X_%-4d = %3g*PI\n", i, 2*i/(double)N);
                    //printf("%g*PI\n", 2*i/(double)N);
            }

            printf("=======================================================\n");
        }
}