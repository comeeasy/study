#include<iostream>
using namespace std;

class Simple	{
private	:
	int num;
public	:
	Simple(int n) : num(n) {}
	Simple(const Simple &copy) : num(copy.num) {
		cout << "Called Simple copy structor" << endl;
	}
	void show_info() {
		cout << "num: " << num << endl;
	}
};

void simple_func(Simple ob) {
	ob.show_info();
}

int main() {
	Simple obj(7);
	cout << "함수 호출 전" << endl;
	simple_func(obj);
	cout << "함수 호출 후" << endl;

	return 0;
}