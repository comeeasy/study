#include "./header/set.h"

int char_to_int(char c) {return (int)(c-'A');}
char int_to_char(int i) {return (char)(i+'A');}

void set::union_set(int elem, int asso) {parent[elem] = asso; }
int set::find_set(int elem, int asso) {
    int i=elem, j=asso;
    // find root of elem, asso
    while(parent[i] >= 0) i = parent[i];
    while(parent[j] >= 0) j = parent[j];

    return (i == j);
}
void set::union_set2(int elem, int asso) {
    int tmp;

    if(height[elem] == height[asso]) height[asso]++;
    else if (height[elem] > height[asso]) {
        tmp = elem;
        elem = asso;
        asso = tmp;
    }

    parent[elem] = asso;
}
void set::print_set() const {
    cout << "son     ";
    for(int i=0; i<num_elem; ++i) cout << int_to_char(i) << ' ';
    cout << "\n--------------------------------------------------\n";
    cout << "parent  ";
    for(int i=0; i<num_elem; ++i) cout << int_to_char(parent[i]) << ' ';
    cout << "\n\n";
}
void set::input_relation(const char* file_name) {
    char buf[3];
    int nelem, ninform;

    ifstream is;
    is.open("set.txt");
    is >> nelem >> ninform;
    for(int i=0; i<ninform; ++i) {
        is >> buf;
        union_set(char_to_int(buf[0]), char_to_int(buf[1]));
    }
    is.close();

    print_set();
}
