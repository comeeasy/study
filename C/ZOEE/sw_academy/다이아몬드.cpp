/*
	태영이는 N개의 다이아몬드를 가지고 있다. 각 다이아몬드 크기는 1 이상 10,000 이하의 자연수로
	나타낼 수 있다. 태영이는 N개의 다이아몬드 중 몇 개를 골라, 애인에게 선물로 주려고한다.
	한편, 태영이는 고른 다이아몬드의 크기가 뒤죽박죽이면 애인이 좋아하지 않을 것이라 생각하여,
	고른 다이아몬드 중 크기 차가 K 이하인 것들을 묶음으로 가져가려고 한다.
	( 묶음은 여러 묶음일 수 있다. )

	태영이가 애인에게 선물할 수 있는 다이아몬드의 최대 개수는 얼마인가?

	input	:
		TC
		N K ( 1<- N <= 1,000 ) ( 0 <= K <= 10,000 )
		N개의 줄에 다이아몬드의 크기가 주어진다.

	output	:
		각 테스트 케이스마다 #x (x는 테스트케이스 번호를 의미하며 1부터 시작한다.) 를 출력하고
		태영이가 선물할 수 있는 다이아몬드의 최대 개수를 출력하라.
*/

#include <iostream>

#define MAX_NUM_DIAMOND 1000
using namespace std;

int size_of_diamond[MAX_NUM_DIAMOND];
void sort(int* base, int nel) {
	int tmp;
	for(int i=0; i<nel-1; ++i) {
		for(int j=0; j<nel-i; ++j) {
			if(base[j-1] > base[j]) {
				tmp = base[j-1];
				base[j-1] = base[j];
				base[j] = tmp;
			}
		}

		//debug
		//for(int k=0; k<nel; ++k) cout << size_of_diamond[k] << ' ';
		//cout << endl;
	}
}

int solution(int N, int K) {
	int result = 0, cnt;

	//debug
	//cout << "before sort" << endl;
	//for(int i=0; i<N; ++i) cout << size_of_diamond[i] << ' ';
	//cout << endl;

	for(int i=0; i<N; ++i) cin >> size_of_diamond[i];
	sort(size_of_diamond, N);

	//debug
	//cout << "after sort" << endl;
	//for(int i=0; i<N; ++i) cout << size_of_diamond[i] << ' ';
	//cout << endl;

	for(int i=0; i<N-1; ++i) {
		cnt = 1;
		for(int j=i+1; j<N; ++j) {
			if(size_of_diamond[j] - size_of_diamond[i] <= K) 
				++cnt;
			else	
				break;
		}
		if(cnt > result) 
			result = cnt;
	}
	return result;
}

int main() {
	int TC, N, K, answer;

	cin >> TC;
	for(int i=1; i<=TC; ++i) {
		cin >> N >> K;
		answer = solution(N, K);
		cout << "#" << i << ' ' << answer << endl;
	}
	return 0;
}