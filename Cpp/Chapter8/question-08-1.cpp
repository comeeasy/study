#include<iostream>
#include<cstring>
using namespace std;

namespace RISK_LEVEL {
	enum {
		RISK_A = 30, RISK_B = 20, RISK_C = 10
	};
}

class Employee {
private	:
	char name[100];
public		:
	Employee(const char* _name) { strcpy(name, _name); }
	void show_your_name() const { cout << "name: " << name << endl; }
	virtual int get_pay() const = 0;
	virtual void show_salary_info() const = 0;
};

class Permanent_worker : public Employee {
private	:
	int salary;
public		:
	Permanent_worker(const char* _name, int _salary) : Employee(_name), salary(_salary) {}
	int get_pay() const { 
		return salary; 
	}
	void show_salary_info() const {
		show_your_name();
		cout << "salary: " << salary << endl << endl;
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
	int get_pay() const { 
		return (Permanent_worker::get_pay() + (int)(sales_result*bonus_ratio)); 
	}
	void show_salary_info() const {
		show_your_name();
		cout << "salary: " << get_pay() << endl;
	}
};

class Foreign_sales_worker : public Sales_worker {
private	:
	const int risk_ratio;
public		:
	Foreign_sales_worker(const char* _name, int salary, double ratio, int risk) : Sales_worker(_name, salary, ratio),
																							risk_ratio(risk) {}
	int get_risk_pay() const {
		return (Sales_worker::get_pay())*(risk_ratio/100.0);
	}															
	int get_pay() const {
		return Sales_worker::get_pay() + get_risk_pay();
	}			
	void show_salary_info() const {
		show_your_name();
		cout << "salary: " << Sales_worker::get_pay() << endl;
		cout << "risk pay: " << get_risk_pay() << endl;
		cout << "sum: " << Sales_worker::get_pay() + get_risk_pay() << endl << endl;
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
		for(int i=0; i<emp_num; ++i)
			emp_list[i]->show_salary_info();
	}
	void show_total_salary() const {
		int sum = 0;
		for(int i=0; i<emp_num; ++i) 
			sum += emp_list[i]->get_pay();
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

	Foreign_sales_worker* fseller1 = new Foreign_sales_worker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->add_sales_result(7000);
	handler.add_employee(fseller1);

	Foreign_sales_worker* fseller2 = new Foreign_sales_worker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->add_sales_result(7000);
	handler.add_employee(fseller2);

	Foreign_sales_worker* fseller3 = new Foreign_sales_worker("Hong", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->add_sales_result(7000);
	handler.add_employee(fseller3);		

	handler.show_all_salary_info();
	handler.show_total_salary();
	return 0;
}