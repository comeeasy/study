#include<iostream>
#include<cstring>

#define STRING_LEN 100
using namespace std;

class Person {
private	:
	int age;
	char name[STRING_LEN];
public	:
	Person(int _age, const char* _name) : age(_age) {
		strcpy(name, _name);
	}
	void what_your_name() const {
		cout << "My name is " << name << endl;
	}
	void how_old_are_you() const {
		cout << "I'm " << age << endl;
	}
};

class Univ_student : public	Person {
private	:
	char major[STRING_LEN];
public	:
	Univ_student(const char* _name, int _age, const char* _major) : Person(_age, _name) {
		strcpy(major, _major);
	}
	void who_are_you() const {
		what_your_name();
		how_old_are_you();
		cout << "My major is " << major << endl << endl;
	}
};

int main() {
	Univ_student stu1("Lee", 22, "Computer Science");
	stu1.who_are_you();

	Univ_student stu2("Yoon", 21, "Electronic Engineering");
	stu2.who_are_you();

	return 0;
}