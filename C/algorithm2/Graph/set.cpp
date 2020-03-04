#include "./header/set.h"

int char_to_int(char c) {return (int)(c-'A');}
char int_to_char(int i) {return (char)(i+'A');}

set::set() : num_elem(0) {
    for(int i=0; i<MAX_ELEMENT; ++i) parent[i] = -1;
    for(int i=0; i<MAX_ELEMENT; ++i) height[i] = 0;
}

void set::union_set(int elem, int asso) {parent[elem] = asso; }
int set::find_set(int elem, int asso, int flag) {
    int i=elem, j=asso;
    // find root of elem, asso
    while(parent[i] >= 0) i = parent[i];
    while(parent[j] >= 0) j = parent[j];
    if(flag == UNION && i != j)
        union_set2(i ,j);
    return (i!=j);

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
    string buf;
    int nelem, ninform;

    ifstream is("./source/set.txt");
    if(is.is_open()) {
        cout << "file is open\n";

        is >> nelem >> ninform;
        num_elem = nelem;
        cout << "nelem: " << nelem << ", ninform: " << ninform << endl;

        for(int i=0; i<ninform; ++i) {
            is >> buf;

            cout << buf << endl;
            find_set(char_to_int(buf[0]), char_to_int(buf[1]), UNION);
        }
    }
    else {
        cout << "file is not available\n";
    }
    is.close();

    print_set();
}
