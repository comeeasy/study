#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void qsort(int* base, int _low, int _high) {
	int low, high, pivot, tmp;

	if( _high - _low >= 2 ) {
		low = _low;
		high = _high;
		pivot = low++;
		while(1) {
			while(base[low] <= base[pivot])	++low;
			while(base[high] > base[pivot])	--high;
			if( high > low ) 	swap(base[low], base[high]);		
			else {
				swap(base[pivot], base[high]);
				break;
			}
		}
		
		cout << "---------------------------------------" << endl;
		cout << "pivot: " << base[high] << " low: " << _low <<" high: " << _high <<endl;
		cout << "---------------------------------------" << endl;
		for(int i=_low; i<=_high; ++i) cout << base[i] << ' ';
		cout << endl;


		qsort(base, _low, high-1);
		qsort(base, high+1, _high);
	}
}

int main() {
	int n;
	int base[100];

	cin >> n;
	for(int i=0; i<n; ++i) cin >> base[i];

	// before sort
	cout << "before sort" << endl;
	for(int i=0; i<n; ++i) cout << base[i] << ' ';
	cout << endl << endl;

	qsort(base, 0, n-1);

	//after sort
	cout << "after sort" << endl;
	for(int i=0; i<n; ++i) cout << base[i] << ' ';
	cout << endl << endl;	

	return 0;
}