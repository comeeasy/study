#include<iostream>
using namespace std;

class Simple {
private	:
	static int num_sim;
public	:
	Simple() {
		num_sim++;
		cout << num_sim << "번쨰 Simple 객체" << endl;
	}
};
// class의 static variable은 class 외부에서 initialize 해야한다.
int Simple::num_sim = 0;

class Complex {
private	:
	static int num_com;
public	:	
	Complex() {
		num_com++;
		cout << num_com << "번째 Complex 객체" << endl;
	}
	Complex(Complex& copy) {
		num_com++;
		cout << num_com << "번쨰 Complex 객체" << endl;
	}
};
// 마찬가지로 static 변수이므로 클래스 외부에서 초기화
int Complex::num_com = 0;

int main() {
	Simple s1;
	Simple s2;

	Complex c1;
	Complex c2 = c1;
	Complex();

	return 0;
}
