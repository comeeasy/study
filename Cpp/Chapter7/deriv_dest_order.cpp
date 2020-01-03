#include<iostream>
using namespace std;

class Base {
private	:
	int base_num;
public	:
	Base(int n) : base_num(n) {
		cout << "Base(): " << base_num << endl;
	}
	~Base() {
		cout << "~Base(): " << base_num << endl;
	}
};

class Derived : public Base {
private	:
	int deriv_num;
public	:
	Derived(int n) : Base(n), deriv_num(n) {
		cout << "Derived(): " << deriv_num << endl;
	}
	~Derived() {
		cout<< "~Derived(): " << deriv_num << endl;
	}
};

int main() {
	Derived dr1(15);
	Derived dr2(27);
	return 0;
}