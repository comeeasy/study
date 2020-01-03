#include <iostream>
using namespace std;

void merge(int* base, int left_low, int left_high, int right_low, int right_high) {
	int i=left_low, j=right_low;
	int buf_length = right_high - left_low + 1, cnt=0;
	int buf[buf_length];

	while(cnt < buf_length) {
		if( i <= left_high && j <=right_high ) {
			if( base[i] <= base[j] ) {
				buf[cnt++] = base[i++];
			}
			else {
				buf[cnt++] = base[j++];
			}
		}
		else if( i > left_high && j <= right_high ) {
			for(int k=j; k<=right_high; ++k) {
				buf[cnt++] = base[k];
			}
		}
		else if( j > right_high && i <= left_high ) {
			for(int k=i; k<=left_high; ++k) {
				buf[cnt++] = base[k];
			}
		}
	}

	// copy
	for(int i=0; i<cnt; ++i) base[left_low+i] = buf[i];
}

void merge_sort(int* base, int low, int high) {
	int left_low, left_high;
	int right_low, right_high;

	left_low = low;
	left_high = (low+high)/2;
	right_low = left_high+1;
	right_high = high;

	if( high > low ) {
		// divide
		merge_sort(base, left_low, left_high);
		merge_sort(base, right_low, right_high);
		// merge
		merge(base, left_low, left_high, right_low, right_high);
	}	
}

void print(int* base) {
	cout << "-----------------------------------------------------" << endl;
	for(int i=0; i<10; ++i) {
		cout << base[i] << ' ';
	}
	cout << endl <<"------------------------------------------------------" << endl;
}

int main() {
	int base[10] = {4, 2, 11, 6, 8, 6, 2, 1, 3, 12};

	//before print
	cout << "before sorting" << endl;
	print(base);

	merge_sort(base, 0, 9);

	//after print
	cout << "after sorting" << endl;
	print(base);

	return 0;
}