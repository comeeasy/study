/*
	'책'을 의미하는 Book 클래스와 '전자 책'을 의미하는 Ebook 클래스를 정의하고자 한다.
	그런데 '전자 책'도 '책'의 일종이므로, 다음의 형태로 클래스의 상속관계를 구성하고자 한다.
	(클래스에 선언돼야할 멤버 변수만 제시하였다.)
*/

#include<iostream>
#include<string>
using namespace std;

class Book {
private	:
	string title;
	string isbn;
	int price;
public	:
	Book(string _title, string _isbn, int _price) : title(_title), isbn(_isbn), price(_price) {}
	void show_info() {
		cout << "제목	: " << title << endl;
		cout << "ISBN 	: " << isbn << endl;
		cout << "가격	: " << price << endl;
	}
};
class Ebook : public Book {
private	:
	string DRMkey;
public	:
	Ebook(string _title, string _isbn, int _price, string _DRMkey) :
		Book(_title, _isbn, _price), DRMkey(_DRMkey) {}
	void show_ebook_info() {
		show_info();
		cout << "인증키	: " << DRMkey << endl;
	}
	
};
int main() {
	Book book("좋은 C++", "555-12345-890-1", 20000);
	book.show_info();
	cout << endl;
	Ebook ebook("좋은 C++ ebook", "555-12345-890-0", 10000, "fdx9w0ikwi");
	ebook.show_ebook_info();
	return 0;
}
