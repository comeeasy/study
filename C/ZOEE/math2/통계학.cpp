#include <iostream>

#define NUMBER_MAX 500000
using namespace std;

int number[NUMBER_MAX];

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void qsort(int* base, int _low, int _high) {
	if( _high > _low ) {
		int low = _low, high = _high;
		int pivot = low;

		low++;
		while( high > low ) {
			while( base[low]  <=  base[pivot] && high > low ) ++low;		
			while( base[high] >  base[pivot] && high > low) --high;
			swap(base[low], base[high]);

			//debug
			cout << base[low] << ", " << base[high] << " swaped." << endl;
		}
		swap(base[pivot], base[high-1]);

		// debug
		cout << "partial sort........." << endl;
		for(int i=_low; i<=_high; ++i) cout << base[i] << ' ';
		cout << endl << "------------------------------------------------" << endl<<endl;

		qsort(base, _low, high-2);
		qsort(base, high, _high);
	}
}

int cnt_mode(int N) {
	int cnt, mode=0;

	cnt = 1;
	for(int i=1; i<N; ++i) {
		if( number[i] == number[i-1] ) {
			++cnt;
		}
		else {
			if( cnt > mode ) {
				mode = cnt;
			}
			cnt = 1;
		}
	}

	return mode;
}

int main() {
	int N;
	int median, mode, range; 
	int mean;
	long long int sum = 0;

	cin >> N;
	for(int i=0; i<N; ++i) cin >> number[i];

	//debug 
	cout << "before sort..............." << endl;
	for(int i=0; i<N; ++i) cout << number[i] << ' ';
	cout << endl;

	qsort(number, 0, N-1);
	
	//debug
	cout << "after sort................." << endl;
	for(int i=0; i<N; ++i) cout << number[i] << ' ';
	cout << endl << "----------------------------\n\n";

	// mean
	for(int i=0; i<N; ++i) sum += number[i];
	if( sum % N <= N/2 ) mean = sum/N;
	else				 mean = sum/N + 1;

	//debug
	cout << "mean: " << mean << endl;

	// median
	median = number[N/2];

	//debug
	cout << "median: " << median << endl;

	//mode
	mode = cnt_mode(N);

	//debug
	cout << "mode: " << mode << endl;

	//range
	range = number[N] - number[0];

	//debug
	cout << "range: " << range << endl;

	cout << mean << endl;
	cout << median << endl;
	cout << mode << endl;
	cout << range << endl;

	return 0;
}