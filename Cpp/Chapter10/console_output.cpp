#include <iostream>
	namespace mystd {
		using namespace std;

		class ostream {
		public	:
			void operator<< (char* str) { printf("%s", str); }
			void operator<< (char c) { printf("%c", c); }
			void operator<< (int num) { printf("%d", num); }
			void operator<< (double d) { printf("%g", d); }
			void operator<< ( ostream& (*fp)(ostream& ostm) ) { fp(*this); }
		};

		ostream& endl(ostream& ostm) {
			ostm<< '\n';
			fflush(stdout);
			return ostm;
		}
	}

int main() {
	using mystd::cout;
	using mystd::endl;

	cout << "Simple string";
	cout << endl;
	cout << 3.14;
	cout << endl;
	cout << 123;
	endl(cout);

	return 0;
}