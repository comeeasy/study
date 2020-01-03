#include<iostream>
using namespace std;

class Simple {
private	:
	int num1;
	mutable int num2;
public	:
	Simple(int n1, int n2) : num1(n1), num2(n2) {}
	void show_info() {
		cout << num1 << ", " << num2 << endl;
	}
	void copy_to_num2() const {
		num2 = num1;
	}
};

int main() {
	Simple s1(1, 2);
	s1.show_info();
	s1.copy_to_num2();
	s1.show_info();
	return 0;
}