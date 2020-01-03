#include<iostream>
#include<cstring>
using namespace std;

namespace COM_POS {
	enum {
		CLERK = 1, SENIOR = 2, ASSIST = 3, MANAGER = 4
	};
}

class Name_card {
private	:
	char* name;
	char* company;
	char* phone_num;
	int position;
public	:
	Name_card(const char *_name, const char *_company, const char *_phone_num, const int &_position) {
		name 	 = new char[strlen(_name)+1];
		strcpy(name, _name);
		company  = new char[strlen(_company)+1];
		strcpy(company, _company);
		phone_num = new char[strlen(_phone_num)+1];
		strcpy(phone_num, _phone_num);
		position = _position;  
	}
	void show_info() {
		cout << "이름	 	: " << name << endl;
		cout << "회사	 	: " << company << endl;
		cout << "전화번호 	: " << phone_num << endl;
		switch(position) {
			case 1: cout << "직급		: 사원" << endl << endl; break;
			case 2: cout << "직급		: 주임" << endl << endl; break;
			case 3: cout << "직급		: 대리" << endl << endl; break;
			case 4: cout << "직급		: 과장" << endl << endl; break;
			default: break;
		}
	}
	~Name_card() {
		delete[] name;
		delete[] company;
		delete[] phone_num;
	}
};

int main() {
	Name_card man_clerk("Lee", "ABCEng", "010-1111-2222", COM_POS::CLERK);
	Name_card man_senior("Hong", "OrangeEng", "010-3333-4444", COM_POS::SENIOR);
	Name_card man_assist("Kim", "SoGoodEng", "010-5555-6666", COM_POS::ASSIST);

	man_clerk.show_info();
	man_senior.show_info();
	man_assist.show_info();

	return 0;
}