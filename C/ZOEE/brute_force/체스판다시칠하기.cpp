/*
    지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M*N 크기의 보드를 찾았다.
    어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져있다. 지민이는 이 보드를
    잘라서 8*8 크기의 체스판으로 만들려고 한다.

    체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다. 구체적으로, 각 칸이 검은색과 흰색으로
    색칠돼잇고, 변을 공유하는 두 개의 사각형은 다른 색으로 칠해져 있어야한다. 따라서 이 정의를
    따르면 체스판을 색칠하는 경우는 두 가지뿐이다. 하나는 맨 위쪽 위 칸이 흰색인 경우,
    하나는 검은색인 경우이다.
*
    보드가 체스판처럼 칠해져 있다는 보장이 없어서, 지민이는 8*8 크기의 체스판으로 잘라낸 후에
    몇 개의 정사각형을 다시 칠해야겠다고 생각했다. 당연히 8*8 크기는 아무데서나 골라도 된다.
    지민이가 다시 칠해야하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.

    input : 첫째 줄에 N, M이 주어진다. (8<=N,M<=50)
            둘째 줄부터 N개의 줄에는 보드의 각 행의 상태가 주어진다.
            B는 검은색, W는 하얀색이다.
    output: 첫째 줄에 지민이가 다시 칠해야 하는 정사각형 개수의 최솟값을 출력한다.
*/

#include <iostream>
#include <cstdio>

#define WHITE 1
#define BLACK 0
#define MAX_SIZE 50
using namespace std;

int check(int k, int l, int board[][MAX_SIZE]) {

}

int main() {
    int N, M, color, num_to_correct, min_answer=1000;
    int board[MAX_SIZE][MAX_SIZE];

    //체스판은 M*N이다. (가로 길이 M, 세로 길이 N)
    cin >> N >> M;
    // for throw \n
    getchar();

    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            color = getchar();
            if(color == 'B') board[j][i] = BLACK;
            else if(color == 'W') board[j][i] = WHITE;
        }
        // for throw \n
        getchar();
    }

    int i=1^1;
    cout << "1&0: "<< i << endl;

    /* for test get board
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            cout << board[j][i];
        }
        cout << endl;
    }
    */

    /* 좌측 상단의 좌표값을 받아서 8*8 크기의 수정할 블록을 세는 함수 작성 */
    for(int i=0; i<=N-8; ++i) {
        num_to_correct = 0;
        for(int j=0; j<=M-8; ++j) {
            for(int k=i; k<i+8; ++k) {
                for(int l=j; l<j+8; ++l) {
                    if(!check(k, l, board[l][k]))
                        ++num_to_correct;
                }
            }
            if(num_to_correct < min_answer) min_answer = num_to_correct;
        }
    }


    return 0;
}
