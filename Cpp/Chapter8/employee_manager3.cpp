#include<iostream>
#include<cstring>
using namespace std;

class Employee {
private	:
	char name[100];
public		:
	Employee(const char* _name) { strcpy(name, _name); }
	void show_your_name() const { cout << "name: " << name << endl; }
};

class Permanent_worker : public Employee {
private	:
	int salary;
public		:
	Permanent_worker(const char* _name, int _salary) : Employee(_name), salary(_salary) {}
	int get_pay() const { return salary; }
	void show_salary_info() const {
		show_your_name();
		cout << "salary: " << salary << endl << endl;
	}
};

class Temporary_worker : public Employee {
private	:
	int worktime;
	int pay_per_time;
public		:
	Temporary_worker(const char* _name, int pay) : Employee(_name), worktime(0), pay_per_time(pay) {}
	void add_work_time(int time) { worktime += time; }
	int get_pay() const { return worktime * pay_per_time; }
	void show_salary_info() const {
		show_your_name();
		cout << "salary: " << get_pay() << endl << endl;
	}
};

class Sales_worker : public Permanent_worker {
private	:
	int sales_result;
	double bonus_ratio;
public		:
	Sales_worker(const char* _name, int money, double ratio) : Permanent_worker(_name, money),
																sales_result(0), bonus_ratio(ratio) {}
	void add_sales_result(int value) { sales_result += value; }
	int get_pay() const { return Permanent_worker::get_pay() + (int)(sales_result*bonus_ratio); }
	void show_salary_info() const {
		show_your_name();
		cout << "salary: " << get_pay() << endl << endl;
	}
};

class Employee_handler {
private	:
	Employee* emp_list[50];
	int emp_num;
public		:
	Employee_handler() : emp_num(0) {}
	void add_employee(Employee* emp) { emp_list[emp_num++] = emp; }
	void show_all_salary_info() const {
		//for(int i=0; i<emp_num; ++i)
		//	emp_list[i]->show_salary_info();
	}
	void show_total_salary() const {
		int sum = 0;
		//for(int i=0; i<emp_num; ++i) 
		//	sum += emp_list[i]->get_salary();
		cout << "Total salary: " << sum << endl;
	}	
	~Employee_handler() {
		for(int i=0; i<emp_num; ++i) {
			delete emp_list[i];
		}
	}
};

int main() {
	// for purpose that manage employees, class construct
	Employee_handler handler;

	handler.add_employee(new Permanent_worker("Kim", 1000));
	handler.add_employee(new Permanent_worker("Lee", 1500));

	Temporary_worker* alba = new Temporary_worker("Jung", 700);
	alba->add_work_time(5);
	handler.add_employee(alba);

	Sales_worker* seller = new Sales_worker("Hong", 1000, 0.1);
	seller->add_sales_result(7000);

	handler.show_all_salary_info();
	handler.show_total_salary();

	return 0;
}