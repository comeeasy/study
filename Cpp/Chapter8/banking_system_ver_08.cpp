#include<iostream>
#include<cstring>

#define NAME_LEN 200
using namespace std;

enum { MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
enum { CREDIT_A=1, CREDIT_B, CREDIT_C };
enum { NORMAL=1, CREDIT };

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
	Account(const Account& ref);						// copy constructor

	int get_acc_ID() const;
	int get_balance() const;
	void add_balance(int money);
	char* get_customer_name() const;
	virtual void deposit(int money) {}	// 보통 예금, 신용예금에 deposit할 때는 보통 예금 class의 deposit을 호출해야한다.
	int withdraw(int money);
	virtual void show_acc_info() const {}

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
int Account::get_balance() const { return balance; }
void Account::add_balance(int money) { balance += money; }
char* Account::get_customer_name() const { return customer_name; }
int Account::withdraw(int money) {
	if( balance < money ) {
		return 0;
	}
	balance -= money;
	return money;
}
 Account::~Account() {

 	// debug
 	cout << "delete name memory\n";

	delete[] customer_name;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
// class name 	: Normal_account
////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Normal_account : public Account {
private	:
	int interest;
public	:
	Normal_account(int ID, int money, const char* name, int _interest) : Account(ID, money, name), interest(_interest) {}
	void deposit(int money);
	int get_interest() const;
	virtual void show_acc_info() const;
};

int Normal_account::get_interest() const { return interest; }
void Normal_account::deposit(int money) {
	add_balance(money);
	add_balance(get_balance()*interest/100);
}
void Normal_account::show_acc_info() const {
	cout << "보통 입출금 계좌" << endl;
	cout << "계좌번호	: " << get_acc_ID() << endl;
	cout << "이름		: " << get_customer_name() << endl;
	cout << "잔액		: " << get_balance() << endl;
	cout << "이자율		: " << get_interest() << endl << endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
// class name 	: Highcredit_account
////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Highcredit_account : public Normal_account {
private	:
	int credit;
public	:
	Highcredit_account(int ID, int money, const char* name, int _interest, int credit_rank) :
						Normal_account(ID, money, name, _interest), credit(credit_rank) {}
	int get_credit() const;
	void deposit(int money);
	virtual void show_acc_info() const; 
};

int Highcredit_account::get_credit() const { 
	switch(credit) {
		case CREDIT_A: return 7;
		case CREDIT_B: return 4;
		case CREDIT_C: return 2;
	}
}
void Highcredit_account::deposit(int money) {
	add_balance(money);
	add_balance(get_balance()*get_interest()/100);
	switch(credit) {
		case CREDIT_A: add_balance(get_balance()*7/100);	break;
		case CREDIT_B: add_balance(get_balance()*4/100);	break;
		case CREDIT_C: add_balance(get_balance()*2/100);	break;
	}
}
void Highcredit_account::show_acc_info() const {
	cout << "신용 신뢰 계좌" << endl;
	cout << "계좌번호	: " << get_acc_ID() << endl;
	cout << "이름		: " << get_customer_name() << endl;
	cout << "잔액		: " << get_balance() << endl;
	cout << "이자율		: " << get_interest()+get_credit() << endl << endl;	
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
	int id, choice;
	char name[NAME_LEN];
	int balance, interest, credit_rank;

	cout << "1. 보통 예금 계좌     2. 신용 신뢰 계좌" << endl;
	cout << "선택	: "; cin >> choice;

	switch(choice) {
		case NORMAL: cout << "[보통 예금 계좌 개설]" << endl;
					 cout << "계좌 ID: "; cin >> id;
					 cout << "이름	: "; cin >> name;
					 cout << "입금액	: "; cin >> balance;
					 cout << "이자율	: "; cin >> interest;

				acc_arr[acc_num++] = new Normal_account(id, balance, name, interest);
				break;
		case CREDIT: cout << "[신용 신뢰 계좌 개설]" << endl;
					 cout << "계좌 ID: "; cin >> id;
					 cout << "이름	: "; cin >> name;
					 cout << "입금액	: "; cin >> balance;
					 cout << "이자율	: "; cin >> interest;
					 cout << "신용 등급( 1 to A, 2 to B, 3 to C )\n 	: ";
					 cin >> credit_rank;

				acc_arr[acc_num++] = new Highcredit_account(id, balance, name, interest, credit_rank);
				break;
	}
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
			
		cout << "출금 완료!" << endl << endl;
		return;
		}
	}

	cout << "유효하지 않은 ID 입니다." << endl << endl;
}
Account_handler::Account_handler() : acc_num(0) {}
void Account_handler::show_all_acc_info() const {
	cout << "현재 계좌는 " << acc_num << "개 등록돼있습니다." << endl;

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

