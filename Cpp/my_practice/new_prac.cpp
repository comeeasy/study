#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int** dptr;
	int a=1, b=2, c=3, d=4;

	int* ptr = (int*)malloc(sizeof(int));
	ptr = &a;
	dptr = &ptr;

	cout << "after pointing a" << endl;

	ptr = (int*)realloc(ptr, sizeof(int)*2);
	ptr[1] = &b;
	cout << "after pointing b" << endl;

	free(ptr);

	return 0;
}