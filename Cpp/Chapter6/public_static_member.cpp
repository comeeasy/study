#include<iostream>
using namespace std;

class Simple {
public	:
	static int num_sim;
public	:
	Simple() { ++num_sim; }
};
int Simple::num_sim = 0;

int main() {
	cout << Simple::num_sim << "번째 Simple 객체" << endl;
	Simple s1;
	Simple s2;

	cout << Simple::num_sim << "번쨰 Simple 객체" << endl;
	cout << s1.num_sim << "번째 Simple 객체" << endl;
	cout << s2.num_sim << "번째 Simple 객체" << endl;
	return 0;
}