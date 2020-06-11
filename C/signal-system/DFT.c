#include "sample.h"

int main() {
    Sample* sample;     

    sample = init_sample(sample);
    sample = get_sample(sample);

    //window(sample, 100);
    window(sample, 500);
    window(sample, 1000);
    window(sample, 2000);

    return 0;
}