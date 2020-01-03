#include<iostream>
using namespace std;

class Simple {
private	:
	int numl
public	:
	Simple(int n) : num(n) {}
	Simple& add_num(int n) {
		num += n;
		return *this;
	}
	void simple_func() {
		cout << "simple_func(): " << num << endl;
	}
	void simple_func() const {
		cout << "const simple_func(): " << num << endl;
	}
};

void your_func(const Simple& obj) {
	obj.simple_func();
}

int main() {
	Simple obj1(2);
	const Simple obj2(7);

	obj1.simple_func();
	obj2.simple_func();

	your_func(obj1);
	your_func(obj2);

	return 0;
}