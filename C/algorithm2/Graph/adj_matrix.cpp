#include "./header/adj_matrix.h"
// for stack, use vector STL

matrixGraph::matrixGraph() : V(0), E(0) {}
void matrixGraph::get_adj_matrix(const char* filename) {
    FILE* fp;
    char vertex[3];

    fp = fopen(filename, "r");
    fscanf(fp, "%d %d", &V, &E);

    for(int i=0; i<V; ++i) graph[i][i] = 1;
    for(int i=0; i<E; ++i) {
        fscanf(fp, "%s", vertex);
        graph[char_to_int(vertex[0])][char_to_int(vertex[1])] = 1;
        graph[char_to_int(vertex[1])][char_to_int(vertex[0])] = 1;
    }
    fclose(fp);
}

void matrixGraph::show_graph() {
    cout << "  ";
    for(int i=0; i<V; ++i) cout << (char)(i+'A') << " ";
    cout << endl;
    for(int i=0; i<V; ++i) {
        cout << (char)(i+'A') << " ";
        for(int j=0; j<V; ++j) {
            cout << graph[i][j] << ' ';
        }
        cout <<"\n";
    }
}

int matrixGraph::char_to_int(char c) { return (int)(c-'A'); }
char matrixGraph::int_to_char(int i) { return (char)(i+'A'); }

void matrixGraph::dfs_recur(int i) const {
    int check[MAX_VERTEX];

    check[i] = 1;
    // visit is to be kind of printing, processing
    //visit(i);
    for(int j=0; j<V; ++j) {
        if(graph[i][j] != 0)
            if(check[j] == 0)
                dfs_recur(j);
    }
}
void matrixGraph::dfs_adj_matrix_nonrecur() const {
    vector<int> stack;
    int check[MAX_VERTEX];
    int tmp;

    for(int i=0; i<MAX_VERTEX; ++i) check[i] = 0;
    for(int i=0; i<V; ++i) {
        if(check[i] == 0) {
            stack.push_back(i);
            check[i] = 1;
            while(!(stack.empty())) {
                tmp = stack.back();
                stack.pop_back();
                // visit()
                cout << "visit " << (char)(tmp+'A') << endl;

                for(int j=0; j<V; ++j) {
                    if(graph[tmp][j] == 1)
                        if(check[j] == 0) {
                            stack.push_back(j);
                            check[j] = 1;
                        }
                }
            }
        }
    }
}

int matrixGraph::count_components() const {
    int cnt = 0, tmp;
    int check[MAX_VERTEX];
    vector<int> stack;

    for(int i=0; i<V; ++i) check[i] = 0;
    for(int i=0; i<V; ++i) {
        if(check[i] == 0) {
            // connected componentes mean sapnning tree
            ++cnt;

            stack.push_back(i);
            check[i] = 1;
            while(!(stack.empty())) {
                tmp = stack.back();
                stack.pop_back();

                for(int j=0; j<V; ++j) {
                    if( graph[tmp][j] == 1 ) {
                        if(check[j] == 0) {
                            stack.push_back(j);
                            check[j] = 1;
                        }
                    }
                }
            }
        }
    }

    cout << "Totally, this graph has " << cnt << " connected components\n";
    return cnt;
}
