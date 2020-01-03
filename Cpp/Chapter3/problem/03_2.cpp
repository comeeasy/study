// 계산기 기능의 Calculator 클래스를 정의해 보자. 기본적으로 지니는 기능은 덧셈, 뺄셈, 솝셈
// 그리고 나눗셈이며, 연산을 할 때마다 어떠한 연산을 몇 번 수행했는지 기록되어야한다.

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////
class Calculator {
private	:
	int add_cnt, sub_cnt, mul_cnt, div_cnt;
public	:
	void init();
	float add(float a, float b);
	float sub(float a, float b);
	float mul(float a, float b);
	float div(float a, float b);
	void show_op_cnt();
};
////////////////////////////////////////////////////////////////////////////////////////////////
void Calculator::init() {
	add_cnt = 0;
	sub_cnt = 0;
	mul_cnt = 0;
	div_cnt = 0;
}
float Calculator::add(float a, float b) {++add_cnt; return a+b;}
float Calculator::sub(float a, float b) {++sub_cnt; return a-b;}
float Calculator::mul(float a, float b) {++mul_cnt; return a*b;}
float Calculator::div(float a, float b) {
	++div_cnt;
	if(b == 0)	cout << "Divided by 0" << endl;
	else		return a/b;
}
void Calculator::show_op_cnt() { 
	cout << "덧셈: " << add_cnt << ", 뺄셈: " << sub_cnt << ", 곱셈: " << mul_cnt << ", 나눗셈: " << div_cnt << endl; 
}
///////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	Calculator cal;
	cal.init();

	cout << "3.2 + 2.4 = " << cal.add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.sub(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.div(4.9, 1.2) << endl;

	cal.show_op_cnt();
	return 0;
}