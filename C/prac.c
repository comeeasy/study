#include <stdio.h>

int main() {
	unsigned i = 0x00000A00;

	while(i > 0x0000000f) {
		i *= 0x000000ff;
		//printf("%08x\n", i);
		i >>= 8;
		printf("%f\n\n", i / (float)256);
	}

	return 0;
}

