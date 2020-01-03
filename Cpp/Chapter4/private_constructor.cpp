#include<iostream>
using namespace std;

class AAA {
private	:
	int num;
public	:
	AAA()	: num(0) {}
	AAA& create_init_obj(int n) const {
		AAA* ptr = new AAA(n);
		return *ptr;
	}
	void show_info() const { cout << num << endl; }
private	:
	AAA(int n)	:	num(n) {}
};

int main() {
	AAA base;
	base.show_info();

	AAA &obj1 = base.create_init_obj(3);
	obj1.show_info();

	AAA &obj2 = base.create_init_obj(12);
	obj2.show_info();

	return 0;
}