// 참조자를 이용해서 다음 요구사항에 부합하는 함수를 각각 정의하라
// -> 인자로 전달된 int형 변수의 값을 1씩 증가시키는 함수
// -> 인자로 전달된 int형 변수의 부호를 바꾸는 함수

#include<iostream>
using namespace std;

//////////////////////////////////////////
void add( int& ref );
void chSign( int& ref );
//////////////////////////////////////////

void add( int& ref ) {
	++ref;
}

void chSign(int& ref) {
	ref = -ref;
}

int main() {
	int num = 10;
	
	cout << num << endl;
	add(num);
	cout << num << endl;
	chSign(num);
	cout << num << endl;

	return 0;
}