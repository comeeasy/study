#include<iostream>
using namespace std;

void SwapPtr( int* (&ref1), int* (&ref2) );

void SwapPtr( int* (&ref1), int* (&ref2) ) {
	int* tmp = ref1;
	ref1 = ref2;
	ref2 = tmp;
}

int main() {
	int num1 = 5, num2 = 10;
	int *ptr1 = &num1, *ptr2 = &num2;

	cout << *ptr1 << ' ' << *ptr2 << endl;
	SwapPtr(ptr1, ptr2);
	cout << *ptr1 << ' ' << *ptr2 << endl;

	return 0;
}