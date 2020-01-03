#include<iostream>
using namespace std;

class Base {
private		:
	int num1;
protected	:
	int num2;
public		:
	int num3;

	Base() : num1(1), num2(2), num3(3) {}
};

class Derived : protected Base {};

int main() {
	Derived	drv;
	// 20행에서 컴파일 에러 발생, Base를 protected 로 선언했기 때문이다.
	cout << drv.num3 << endl;
	return 0;
}