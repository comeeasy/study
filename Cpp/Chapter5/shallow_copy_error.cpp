#include<iostream>
#include<string>
using namespace std;

class Person {
private	:
	string name;
	int age;
public	:
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}
	void show_info() {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
};

int main() {
	Person man1("Lee_dong_woo", 29);
	Person man2 = man1;
	man1.show_info();
	man2.show_info();

	return 0;
}