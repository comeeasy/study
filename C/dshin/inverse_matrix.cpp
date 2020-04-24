#include <iostream>
using namespace std;


int mat3[3][3];
void product(int mat[][3], int mat2[][3], int n) {

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            for(int k=0; k<n; ++k) {
                mat3[i][j] += mat[i][k]*mat2[k][j];
            }
        }
    }

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cout << mat3[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    int mat[3][3];
    int mat2[3][3];

    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
            cin >> mat[i][j];
        }
    }
    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
            cin >> mat2[i][j];
        }
    }

    cout << endl;
    product(mat, mat2, 3);

    return 0;
}
