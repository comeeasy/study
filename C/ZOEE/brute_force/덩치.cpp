/*
    우리는 사람의 덩치를 키와 몸무게, 이 두 개의 값으로 표현하여 그 등수를 매겨보려고한다.
    어떤 사람의 몸무게가 x kg, 키가 y cm 라면 이 사람의 덩치는 (x,y)로 표시된다.
    두 사람 A, B의 덩치가 각각 (x, y), (p, q) 일 때, x>p, y>q 모두를 만족해야
    A의 덩치가 B보다 크다 라고한다.
    N명의 집단에서 각 사람의 덩치 등수는 자신보다 더 "큰 덩치"의 사람의 수로 정해진다.
    만일 자신보다 더 큰 덩치의 사람이 k명이라면 그 사람의 덩치 등수는 k+1이 된다.

    input : 첫 줄에는 전체 사람의 수 N이 주어진다.
            이어지는 N개의 줄에는 각 사람의 몸무게와 키를 나타내는 야의 정수
            x, y가 주어진다. 단, 2<=N<=50, 10<=x,y<=200 이다.
    output: 입력에 나열된 사람의 덩치 등수를 구해서 그 순서대로 첫 줄에 출력해야한다.
            각 덩치 등수는 공백문자로 분리되어야한다.
*/

#include <iostream>

#define MAX_NUM 50
using namespace std;

class big {
public  :
    int w; // weight
    int h; // height;

    big() : w(0), h(0) {}
};
/*
int main() {
    big men[MAX_NUM];
    int rank[MAX_NUM];
    int w_index[MAX_NUM];
    int h_index[MAX_NUM];
    int N, tmp, com_w, com_h, j;

    cin >> N;
    for(int i=0; i<N; ++i) cin >> men[i].w >> men[i].h;

    for(int i=0; i<N; ++i) cout << '('<<men[i].w<<", "<<men[i].h<<")\n";

    for(int i=0; i<N; ++i) w_index[i] = i;
    for(int i=0; i<N; ++i) h_index[i] = i;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N-i-1; ++j) {
            if(men[w_index[j+1]].w < men[w_index[j]].w) {
                tmp = w_index[j];
                w_index[j] = w_index[j+1];
                w_index[j+1] = tmp;
            }
        }
    }

    for(int i=0; i<N; ++i) cout << w_index[i]<<' ';
    cout << endl;

    for(int i=0; i<N; ++i) {
        for(int j=0; j<N-i-1; ++j) {
            if(men[h_index[j+1]].h < men[h_index[j]].h) {
                tmp = h_index[j];
                h_index[j] = h_index[j+1];
                h_index[j+1] = tmp;
            }
        }
    }
    for(int i=0; i<N; ++i) cout << h_index[i]<<' ';
    cout << endl;

    for(int i=0; i<N; ++i) {
        // to compare
        for(j=0; w_index[j]!=i; ++j);
        cout << "com_w: "<<j<<endl;
        com_w = j;
        for(j=0; h_index[j]!=i; ++j);
        com_h = j;

        //cout<<"com_w: "<<com_w<<", com_h: "<<com_h<<endl;
        rank[i] = (com_w > com_h ? (N-com_w) : (N-com_h));
        //cout << "rank: "<<rank[i]<<endl;
    }

    for(int i=0; i<N; ++i) cout << rank[i] << ' ';
    cout << endl;

    return 0;
}
*/

int main() {
    big men[MAX_NUM];
    int rank[MAX_NUM];
    int N, bigger;

    cin >> N;
    for(int i=0; i<N; ++i) cin >> men[i].w >> men[i].h;
    for(int i=0; i<N; ++i) {
        bigger=0;
        for(int j=0; j<N; ++j) {
            if(i==j) continue;
            if(men[j].w>men[i].w && men[j].h>men[i].h) bigger++;
        }
        rank[i]=bigger+1;
    }
    for(int i=0; i<N; ++i) cout << rank[i] << ' ';
    cout << endl;
}
