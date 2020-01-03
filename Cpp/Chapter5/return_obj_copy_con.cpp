#include<iostream>
using namespace std;

class Simple {
private	:
	int num;
public	:
	Simple(int n) : num(n) {}
	Simple(const Simple &copy) : num(copy.num) {}
	Simple& add(int n) {
		num += n;
		return *this;
	}
	~Simple() {
		//cout << "Destroy obj: " << this << endl;
	}
	void simple_func() {
		cout << "simple_func: " << num << endl;
	}
	void simple_func() const {
		cout << "const simple_func: " << num << endl;
	}
};

void your_func(const Simple &ob) {
	ob.simple_func();
}

int main() {
	Simple obj1(7);
	const Simple obj2(7);

	obj1.simple_func();
	obj2.simple_func();

	your_func(obj1);
	your_func(obj2);

	return 0;
}