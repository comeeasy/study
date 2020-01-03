#include<iostream>
#include<cstring>
using namespace std;

class Computer {
private	:
	char owner[50];
public	:
	Computer(const char* name) { strcpy(owner, name); }
	void calculate() { cout << "요청 내용을 계산합니다." << endl; }
};
class Notebook : public Computer {
private	:
	int battery;
public	:
	Notebook(const char* name, int initcharg) : Computer(name), battery(initcharg) {}
	void charging() { battery += 5; }
	void use_battery() { battery -= 1; }
	void moving_cal() {
		if( !get_battery() ) {
			cout << "충전이 필요합니다." << endl;
			return;
		}
		cout << "이동하면서 ";
		calculate();
		use_battery();
	}
	int get_battery() { return battery; }
};
class Table_notebook : public Notebook{
private	:
	char regst_pen_model[50];
public	:
	Table_notebook(const char* name, int initcharg, const char* pen) : Notebook(name, initcharg) 
	{
		strcpy(regst_pen_model, pen);
	}
	void write(const char* pen_info) {
		if(!get_battery()) {
			cout << "충전이 필요합니다." << endl;
			return;
		}
		if(strcmp(regst_pen_model, pen_info) != 0) {
			cout <<"등록된 펜이 아닙니다.";
			return;
		}
		cout << "필기 내용을 처리합니다." << endl;
		use_battery();
	}
};

int main() {
	Notebook nc("이수종", 5);
	Table_notebook tn("정수영", 5, "ISE-241-242");
	nc.moving_cal();
	tn.write("ISE-241-242");
	return 0;
}