#include "sample.h"

int main() {
    Sample* sample;     

    sample = init_sample(sample);
    sample = get_sample(sample);
    
    window(sample, 500);

    return 0;
}