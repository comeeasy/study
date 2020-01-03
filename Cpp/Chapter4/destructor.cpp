#include<iostream>
#include<string>
using namespace std;

class Person {
private	:
	string name;
	int age;
public	:
	Person(string _name, int _age) : name(_name), age(_age) {}
	void show_info() const {
		cout << name << endl;
		cout << age << endl;
	}
	~Person() {
		//delete[] name;
		cout << "called destructor!" << endl;
	}
};

int main() {
	Person man1("lee dong woo", 29);
	Person man2("jang dong gun", 41);

	man1.show_info();
	man2.show_info();

	return 0;
}