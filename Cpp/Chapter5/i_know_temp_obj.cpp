#include<iostream>
using namespace std;

class Tmp {
private	:
	int num;
public	:
	Tmp(int n) : num(n) {
		cout << "Create obj: " << num << endl;
	}
	~Tmp() {
		cout << "Deconstrut obj: " << num << endl;
	}
	void show_info() {
		cout << "num is: " << num << endl;
	}
};

int main() {
	Tmp(100);
	cout << "--------------- After make!" << endl << endl;

	Tmp(200).show_info();
	cout <<"---------------- After make!" << endl << endl;

	const Tmp &ref = Tmp(300);
	cout << "-------------- end main!" << endl << endl;

	return 0;
}

// 1. 임시객체는 다음 행으로 넘어가면 바로 소멸되어 버린다.
// 2/ 참조자에 참조되는 임시객체는 바로 소멸되지 않는다.