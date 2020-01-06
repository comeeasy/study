#include <iostream>
using namespace std;

class First {
public	:
	void first_func() { cout << "first_func()\n"; }
	virtual void simple_func() { cout << "First's simple_func()\n"; }
 };

 class Second : public First {
 public	:
 	void second_func() { cout << "second_func()\n"; }
 	virtual void simple_func() { cout << "Second's simple_func()\n"; }
 };

 class Third : public Second {
 public	:
 	void third_func() { cout << "Third's func()\n"; }
 	virtual void simple_func() { cout << "Third's simple_func()\n"; }
 };

 int main() {
 	Third obj;

 	obj.first_func();
 	obj.second_func();
 	obj.third_func();
 	obj.simple_func();

 	Second& sref = obj;
 	sref.first_func();
 	sref.second_func();

 	// 실제로 가리키고 있는 obj인 Third obj 의 simple_func()을 호출
 	sref.simple_func();

 	First& fref = obj;
 	fref.first_func();

 	// 실제로 가리키고 있는 obj의 simple_func() 을 호출함
 	fref.simple_func();

 	return 0;
 }