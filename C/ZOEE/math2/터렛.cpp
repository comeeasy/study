#include<iostream>
#include<cmath>
using namespace std;

int sol(int x1, int y1, int x2, int y2, int r1, int r2) {
	int r_longer, r_shorter;
	long long int d_sqr, r_sub_sqr, r_add_sqr;

	if( r2 > r1 ) {
		r_longer = r2;
		r_shorter = r1;
	}
	else {
		r_longer = r1;
		r_shorter = r2;
	}

	d_sqr = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
	r_sub_sqr   = (r2-r1)*(r2-r1);
	r_add_sqr   = (r2+r1)*(r2+r1);

	if( d_sqr > r_add_sqr ) 							return 1;
	else if ( d_sqr == r_add_sqr ) 						return 2;
	else if ( d_sqr < r_add_sqr && d_sqr > r_sub_sqr )	return 3;
	else if ( d_sqr == r_sub_sqr )						return 4;
	else if ( d_sqr < r_sub_sqr )						return 5;
}

int main() {
	int x1, y1, x2, y2, r1, r2;
	int TC;

	cin >> TC;
	for(int i=0; i<TC; ++i) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		
		if( x1 == x2 && y1 == y2 && r1 == r2 ) {
			cout << -1 << endl;
		}
		else {
			switch(sol(x1, y1, x2, y2, r1, r2)) {
				case 1: cout << 0 << endl; break;
				case 2: cout << 1 << endl; break;
				case 3: cout << 2 << endl; break;
				case 4: cout << 1 << endl; break;
				case 5: cout << 0 << endl; break;
			}	
		}
		
	}

	return 0;
}