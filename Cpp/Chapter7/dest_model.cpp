#include<iostream>
#include<cstring>
using namespace std;

class Person {
private	:
	char* name;
public	:
	Person(const char* _name) {
		name = new char[strlen(_name)+1];
		strcpy(name, _name);
	}
	~Person() {
		delete[] name;
	}
	void what_your_name() const {
		cout << "My name is " << name << endl;
	}
};

class Student : public Person {
private	:
	char* major;
public	:
	Student(const char* _name, const char* _major) : Person(_name) {
		major = new char[strlen(_major)+1];
		strcpy(major, _major);
	}
	~Student() {
		delete[] major;
	}
	void who_are_you() const {
		what_your_name();
		cout << "My major is " << major << endl;
	}
};

int main() {
	Student st1("Kim", "Mathmetics");
	st1.who_are_you();
	Student st2("Hong", "Physics");
	st2.who_are_you();
	return 0;
}