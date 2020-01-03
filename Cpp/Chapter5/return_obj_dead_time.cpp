#include<iostream>
using namespace std;

class Simple {
private	:
	int num;
public	:
	Simple(int n) : num(n) {
		cout << "new obj: " << this << endl;
	}
	Simple(const Simple& copy) : num(copy.num) {
		cout << "new copy obj: " << this << endl;
	}
	~Simple() {
		cout << "Destruct obj: " << this << endl;
	}
};

Simple simple_func(Simple ob) {
	cout << "parm ADR    : " << &ob << endl;
	return ob;
}

int main() {
	Simple obj(7);
	simple_func(obj);
	// 인자로 obj이 들어갔는데 이를 원함수의 ob로 복사한다.
	// 이후 return 할 때도 새로운 임시객체를 이용하여 복사했던 그 ob객체를 다시 복사하고
	// return 후 소멸, ob도 차례로 소멸된다.

	cout << endl;
	Simple ref = simple_func(obj);
	cout << "Return obj:    " << &ref << endl;

	return 0;
}