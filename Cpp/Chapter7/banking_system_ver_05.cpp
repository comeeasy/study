#include<iostream>
#include<cstring>

#define NAME_LEN 20
using namespace std;

enum { MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 클래스 이름	: Account
// 클래스 유형	: Entity Class
////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Account {
private	:
	int acc_ID;
	int balance;
	char* customer_name;
public	:
	Account(int ID, int money, const char* name);		// constructor
	Account(const Account& ref);				// copy constructor

	int get_acc_ID() const;
	void deposit(int money);
	int withdraw(int money);
	void show_acc_info() const;

	~Account();
};

Account::Account(int ID, int money, const char* name) : acc_ID(ID), balance(money) {
	customer_name = new char[strlen(name)+1];
	strcpy(customer_name, name);
}
Account::Account(const Account& ref) : acc_ID(ref.acc_ID), balance(ref.balance) {
	customer_name = new char[strlen(ref.customer_name)+1];
	strcpy(customer_name, ref.customer_name);
}
int Account::get_acc_ID() const { return acc_ID; }
void Account::deposit(int money) {
	balance += money;
}
int Account::withdraw(int money) {
	if( balance < money ) {
		return 0;
	}
	balance -= money;
	return money;
}
void Account::show_acc_info() const {
	cout << "계좌번호	: " << acc_ID << endl;
	cout << "이름		: " << customer_name << endl;
	cout << "잔액		: " << balance << endl;
}
Account::~Account() {
	delete[] customer_name;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 클래스 이름	: Account_handler
// 클래스 유형	: control class
////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Account_handler {
private	:
	Account* acc_arr[100];
	int acc_num;
public	:
	Account_handler();

	void show_menu() const;
	void make_account();
	void deposit_money();
	void withdraw_money();
	void show_all_acc_info() const;

	~Account_handler();
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Account_handler::show_menu() const {
	cout << "------------------ menu ------------------" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4.계좌번호 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}
void Account_handler::make_account() {
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌 개설]" << endl;
	cout << "계좌 ID: "; cin >> id;
	cout << "이름	: "; cin >> name;
	cout << "입금액	: "; cin >> balance;
	cout << endl;

	acc_arr[acc_num++] = new Account(id, balance, name);
}
void Account_handler::deposit_money() {
	int money;
	int id;

	cout << "[입금]" << endl;
	cout << "계좌ID	: "; cin >> id;
	cout << "입금액	: "; cin >> money;
	
	for(int i=0; i<acc_num; ++i) {
		if(acc_arr[i]->get_acc_ID() == id) {
			acc_arr[i]->deposit(money);
			cout << "입금 완료!" << endl << endl;
			return;
		}
		cout << "유효하지 않은 ID 입니다." << endl << endl;
	} 
}
void Account_handler::withdraw_money() {
	int money;
	int id;

	cout << "[출금]" << endl;
	cout << "계좌ID	: "; cin >>id;
	cout << "출금액	: "; cin >> money;

	for(int i=0; i<acc_num; ++i) {
		if(acc_arr[i]->get_acc_ID() == id) {
			if(acc_arr[i]->withdraw(money) == 0) {
				cout << "잔액 부족!" << endl;
				return; 
			}
		}

		cout << "출금 완료!" << endl << endl;
		return;
	}

	cout << "유효하지 않은 ID 입니다." << endl << endl;
}
Account_handler::Account_handler() : acc_num(0) {}
void Account_handler::show_all_acc_info() const {
	for(int i=0; i<acc_num; ++i) {
		acc_arr[i]->show_acc_info();
		cout << endl;
	}
}
Account_handler::~Account_handler() {
	for(int i=0; i<acc_num; ++i) {
		delete acc_arr[i];
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	Account_handler manager;
	int choice;

	while(1) {
		manager.show_menu();
		cout << "선택: "; cin >> choice;
		cout << endl;

		switch(choice) {
			case MAKE :
				manager.make_account(); break;
			case DEPOSIT :
				manager.deposit_money(); break;
			case WITHDRAW :
				manager.withdraw_money(); break;
			case INQUIRE :
				manager.show_all_acc_info(); break;
			case EXIT :
				return 0;
			default :
				cout << "Illegal selection.." << endl;
		}
	}

	return 0;
}

