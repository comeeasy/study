/*
	다음 두 클래스에 적절한 생성자와 소멸자를 정의해보자.
	그리고 이의 확인을 위한 main 함수를 정의해보자.
*/

#include<iostream>
#include<cstring>
using namespace std;

class Friend_info {
private	:
	char* name;
	int age;
public	:
	Friend_info(const char* _name, int _age) : age(_age) {
		name = new char[strlen(_name)+1];
		strcpy(name, _name);
	}
	~Friend_info() {
		delete[] name;
		cout << "delete name" << endl;
	}
	void show_friend_info() {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
};

class Friend_detail_info : public Friend_info {
private	:
	char* addr;
	char* phone;
public	:
	Friend_detail_info(const char* _name, int _age, const char* _addr, const char* _phone) :
		Friend_info(_name, _age) 
	{
		addr  = new char[strlen(_addr)+1];
		phone = new char[strlen(_phone)+1];
		strcpy(addr, _addr);
		strcpy(phone, _phone);
	}
	~Friend_detail_info() {
		delete[] addr;
		cout << "delete addr" << endl;
		delete[] phone;
		cout << "delete phone" << endl;
	}
		
	void show_detail_friend_info() {
		show_friend_info();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl << endl;
	}
};

int main() {
	Friend_detail_info f1("Kim", 24, "경기도 고양시 화정", "010-9243-9761");
	return 0;
}