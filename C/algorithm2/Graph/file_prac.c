#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fp;
    fp.open("./graph.txt");

    if(fp.open()) {
        while(!fp.eof()) {
            string str;
            getline(fp, str);
            cout << str << endl;
        }
    }
    fp.close();

    return 0;
}
