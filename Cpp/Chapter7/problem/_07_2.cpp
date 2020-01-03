/*
	정사각형을 의미하는 Square 클래스와 직사각형을 의미하는 Rectangle 클래스를 정의하고자 한다.
	그런데 정사각형은 직사각형의 일종이르머, 다음의 형태로 클래스의 상속관계를 구성하고자 한다.

	이에 다음 main 함수와 함꼐 실행이 가능하도록 위의 클래스를 완성해보자. 참로 상속을 한다고 해서
	유도 클래시에 무엇인가를 많이 담아야 한다는 생각을 버리자!.
*/
#include<iostream>
using namespace std;

class Rectangle {
private	:
	int height;
	int width;
public	:
	Rectangle() : height(1), width(1) {}
	Rectangle(int h, int w) : height(h), width(w) {}
	void show_area_info() { cout << "면적: " << height*width << endl; }
};
class Square : public Rectangle {
public	:
	Square() : Rectangle() {}
	Square(int w) : Rectangle(w, w) {}
};

int main() {
	Rectangle rec(4, 3);
	rec.show_area_info();

	Square sqr(7);
	sqr.show_area_info();
	return 0;
}