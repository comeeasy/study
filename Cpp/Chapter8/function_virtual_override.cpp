#include <iostream>
using namespace std;

class First {
public	:
	virtual void my_func() { cout << "First my func" << endl; }
};

class Second : public First{
public	:
	virtual void my_func() { cout << "Second my func" << endl; }
};

class Third : public Second {
public	:
	virtual void my_func() { cout << "Third my func" << endl; }
};

int main() {
	Third*  tptr = new Third();
	Second* sptr = tptr;
	First*  fptr = sptr;

	fptr->my_func();
	sptr->my_func();
	tptr->my_func();

	delete tptr;
	return 0;
}

