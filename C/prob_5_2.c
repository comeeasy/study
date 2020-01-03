/*
	음수를 입력하여
	-8645 를 입력하면 5468- 이 출력되게하는 프로그램을 짜세요
*/

#include<stdio.h>

int my_pow(int low, int high) {
	if(high == 0) return 1;

	int tmp=1;
	for(int i=0; i<high; ++i) tmp *= low;
	return tmp;
}

int main() {
	int num, num_to_digit, result = 0;
	int num_of_digit=0;
	int digit = 0;

	scanf("%d", &num);
	num = (-1)*num;
	num_to_digit = num;

	while( num_to_digit != 0) {
		num_to_digit /= 10;
		++digit;
	}

	printf("digit: %d, num: %d, num_to_digit: %d\n", digit, num, num_to_digit);

	while( num != 0 ) {
		result += (num % 10)*my_pow(10, digit-1);
		num /= 10;
		--digit;
	}
	printf("%d-\n", result);

	return 0;
}