#include <iostream>
#include <cstring>
using namespace std;

class First {
private	:
	char* str_one;
public		:
	First( const char* str ) { str_one = new char[strlen(str)+1]; }
	virtual ~First() { 
		cout << "~First()" << endl;
		delete[] str_one; 
	}
};

class Second : public First {
private	:
	char* str_two;
public		:
	Second(const char* str1, const char* str2) : First(str1) {
		str_two = new char[strlen(str2)+1];
	}
	~Second() { 
		cout << "~Second()" << endl;
		delete[] str_two; 
	}
};

int main() {
	First* ptr = new Second("simple", "complex");

	// 여기서 문제가 발생, ptr는 실제로는 First class를 가키고 있기 떄문에
	// ~First() 를 호출 할 것이다. 그렇게 되면 str_two는 메모리 반환이 안될것이다.
	delete ptr;
	return 0;
}