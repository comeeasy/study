#include<iostream>
using namespace std;

class Base {
private	:
	int base_num;
public	:
	Base() : base_num(20) {
		cout << "Base()" << endl;
	}
	Base(int n) : base_num(n) {
		cout << "Base(int n)" << endl;
	}
	void show_info() {
		cout << base_num << endl;
	}
};

class Derived : public Base{
private	:
	int deriv_num;
public	:
	Derived() : deriv_num(30) {
		cout << "Derived()" << endl;
	}
	Derived(int n) : deriv_num(n) {
		cout << "Derived(int n)" << endl;
 	}
 	Derived(int n1, int n2) : Base(n1), deriv_num(n2) {
 		show_info();
 		cout << deriv_num << endl;
 	}
};

int main() {
	cout << "case1........" << endl;
	Derived dr1;
	dr1.show_info();
	cout << "------------------" << endl;
	cout << "case2........" << endl;
	Derived dr2(12);
	dr2.show_info();
	cout << "------------------" << endl;
	cout << "case3........" << endl;
	Derived dr3(33, 24);
	dr3.show_info();
	return 0;
}
