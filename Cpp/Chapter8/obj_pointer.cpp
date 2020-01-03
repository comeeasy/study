/*
	C++ 에서 어떤 클래스의 포인터는
	어떤 클래스를 직접, 간적적으로 상속하는 derived class를 참조할 수 있다.
*/

#include <iostream>
using namespace std;

class Person {
public	:
	void sleep() { cout << "Slepp" << endl; }
};
class Student : public Person {
public	:
	void study() { cout << "Study" << endl; }
};
class Parttime_student : public Student {
public	:
	void work() { cout << "Work" << endl; }
};

int main() {
	Person* ptr1 = new Student();
	Person* ptr2 = new Parttime_student();
	Student* ptr3 = new Parttime_student();
	ptr1->sleep();
	ptr2->sleep();
	ptr3->study();
	return 0;
}
