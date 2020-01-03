#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;

void printRandNum() {
	srand(time(NULL));

	cout << rand()%101 << endl;
	cout << rand()%101 << endl;
	cout << rand()%101 << endl;
	cout << rand()%101 << endl;
	cout << rand()%101 << endl;
}

int main() {
	printRandNum();
	return 0;
}