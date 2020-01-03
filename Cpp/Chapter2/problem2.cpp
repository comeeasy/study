// 아래와 같이 구조체가 정의돼있을때 두 점의 합을 계산하는 함수를 다음과 같이 정의할 때
// Point& PntAdder(const Point &p1, const Point &p2)
// 덧셈의 결과는 함수의 반환형으로 return해라

#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct _point {
	int x;
	int y;
} Point;

Point& PntAdder(const Point &p1, const Point &p2) {
	Point* result = new Point;
	result->x = p1.x + p2.x;
	result->y = p1.y + p2.y;

	return *result;
}

int main() {
	Point* p1 = new Point;
	Point* p2 = new Point;

	// p1 = <5, 2>, p2 = <2, -4>
	p1->x = 5;
	p1->y = 2;
	p2->x = 2;
	p2->y = -4;

	// reference는 항상 initialized 돼야한다.
	Point &ref = PntAdder(*p1, *p2);
	cout << ref.x << ' ' << ref.y << endl;

	delete &ref;
	delete p1;
	delete p2;
	return 0;
}