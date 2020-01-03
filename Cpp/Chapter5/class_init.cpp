#include<iostream>
using namespace std;

class Simple {
private	:
	int num1, num2;
public	:
	Simple(int n1, int n2) : num1(n1), num2(n2) {}
	Simple(Simple& copy) : num1(copy.num1), num2(copy.num2) {
		cout << "Called Simple(Simple& copy)" << endl;
	}
	void show_info() {
		cout << num1 << endl;
		cout << num2 << endl;
	}
};

int main() {
	Simple sim1(15, 30);

	// Simple sim2(sim1) 으로 호출된다.
	Simple sim2 = sim1;
	sim2.show_info();
	return 0;
}