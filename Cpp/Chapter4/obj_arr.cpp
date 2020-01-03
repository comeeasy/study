#include<iostream>
#include<cstring>
using namespace std;

class Person {
private	:
	char* name;
	int age;
public	:
	Person(const char* _name, int _age) {
		name = new char[strlen(_name)+1];
		strcpy(name, _name);
		age = _age;
	}
	Person() {
		name = NULL;
		age = 0;
		cout << "Called Person()" << endl;
	}
	void set_person_info(char* _name, int _age) {
		name = _name;
		age = _age;
	}
	void show_info() {
		cout << "이름	: " << name << endl;
		cout << "나이	: " << age << endl << endl;
	}
	~Person() {
		delete[] name;
		cout << "Called destructor" << endl;
	}
};

int main() {
	Person* parr[3];
	char namestr[100];
	char* strptr;
	int age;
	int len;

	for(int i=0; i<3; ++i) {
		cout << "이름: ";
		cin  >> namestr;
		cout << "나이 : ";
		cin  >> age;

		parr[i] = new Person(namestr, age);
	}

	parr[0]->show_info();
	parr[1]->show_info();
	parr[2]->show_info();

	delete parr[0];
	delete parr[1];
	delete parr[2];

	return 0;
}