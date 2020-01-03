/*
	input  : n ( 1<= n <= 90 )
	output : 피보나치 수를 출력 
*/

#include<iostream>
using namespace std;

typedef long long unsigned llu;

llu fibo[91];
void mk_fib() {
	fibo[0] = 0;
	fibo[1] = 1;
	for(int i=2; i<91; ++i) {
		fibo[i] = fibo[i-1] + fibo[i-2];
	}
}

int main() {
	int n;
	cin >> n;
	mk_fib();
	cout << fibo[n] << endl;

	return 0;
}