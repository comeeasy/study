#include <iostream>

#define BOSS 	1
#define CLERK	0
using namespace std;

class List {
private	:
	int num_of_junior;
	Employee* next;	
public	:
	List() : num_of_junior(0) { next = NULL; }
	add(Employee& new_employee) {
		Employee* iterator = this->next;
		for(int i=0; i<num_of_junior; ++i) {
			iterator = iterator->next;
		}
		iterator = &new_employee;
	}
};

class Employee {
private	:
	bool position;
	int salary;
	Employee* boss;
	int num_of_junior;
	List junior;
public	:
	Employee(bool _position, int _salary) : position(_position), salary(_salary), num_of_junior(0) {
		boss = NULL;
		junior = NULL;
	}
	set_boss(Clerk& new_boss) {
		this->boss = &new_boss;
	}
	set_junior(Clerk& new_junior) {
		if(num_of_junior == 0) {
			this->junior = &new_junior;
		}
		else {

		}
	}
}