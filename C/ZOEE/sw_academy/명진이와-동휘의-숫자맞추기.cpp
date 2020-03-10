#include <iostream>
#include <string>
#include <cstdio>

#define YES_NO_NUM 8
#define YES 1
#define NO (-1)
using namespace std;

// 0-9까지 나열한다음 하나하나 지워기며 비교하는 방
int main() {
    int T, N, sol;
    int yes_no[10];
    char y_n;
    char buf[14];

    //  test-case, N  입력받고
    cin >> T >> N;
    cin.get();

    for(int i=1; i<=T; ++i) {
        for(int i=0; i<10; ++i) yes_no[i] = 0;

        for(int i=0; i<N; ++i) {
            cin.getline(buf, 12);
            y_n = buf[YES_NO_NUM];

            //cout << "buf: " << buf << endl;
            //cout << "y_n: " << y_n << endl;

            if(y_n == 'N') {
                for(int i=0; i<7; i+=2) {
                    yes_no[(int)(buf[i]-'0')] = NO;
                    cout << (int)(buf[i]-'0') << " = No\n";
                }
            }
            else if(y_n == 'Y'){
                for(int i=0; i<7; i+=2) {
                    if(yes_no[(int)(buf[i]-'0')] != NO) {
                        yes_no[(int)(buf[i]-'0')] = YES;
                        cout << (int)(buf[i]-'0') << " = yes\n";
                    }
                }
            }
            else {
                cout << "wrong input bitch\n";
            }
        }

        //for(int i=0; i<10; ++i) cout << yes_no[i] << ' ';
        //cout << endl;

        for(int i=0; i<10; ++i) {
            if(yes_no[i] == YES) sol = i;
        }
        cout << '#' << i << ' ' << sol << '\n';
    }

     return 0;
}

/*
int main {
    int T, N;
    parent[10];
    char yes_no;
    string buf;

    cin >> T >> N;
    for(int i=1; i<=T; ++i) {
        cin >> buf;
        yes_no = buf[YES_NO_NUM];
        if(yes_no == 'N') {
            for(int i=0; i<7; i+=2) {
                yes_no[i] = NO;
            }
        }
        else if(yes_no == 'Y'){

        }
        else {
            cout << "wrong input bitch\n";
        }

        cout << '#' << i << ' ' // output answer here
    }
}
*/
