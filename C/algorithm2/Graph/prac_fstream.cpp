#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string buf1, buf2;
    int i1, i2;
    ifstream is("./source/graph.txt");

    if(is.is_open()) {
        cout << "file is open\n";
        is >> i1 >> i2;
        cout << i1 << i2 << endl;
        // output: 1718

        is >> buf1 >> buf2;
        cout << buf1 << buf2 << endl;
    }
    else {
        cout << "file is not open\n";
    }
    is.close();

    return 0;
}
