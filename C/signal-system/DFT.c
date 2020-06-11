#include "sample.h"

int main() {
    Sample* sample;     

    sample = init_sample(sample);
    sample = get_sample(sample);

    for(int i=0; i<1000; ++i) {
        if( (sample+i)->elem != (sample+i+100)->elem )
            printf("nope\n");
    }

    window(sample, 100);
    //window(sample, 500);
    //window(sample, 1000);
    //window(sample, 2000);

    return 0;
}