#include "./header/adj_matrix.h"

matrixGraph::matrixGraph() : V(0), E(0) {
    for(int i=0; i<V; ++i) {
        for(int j=0; j<V; ++j) {
            graph[i][j] = 0;
        }
    }
}

void matrixGraph::get_adj_matrix(const char* filename) {
    FILE* fp;
    char vertex[3];

    fp = fopen(filename, "r");
    fscanf(fp, "%d %d", &V, &E);

    cout << "V: " << V << " E: " << E << endl;

    for(int i=0; i<V; ++i) graph[i][i] = 1;
    for(int i=0; i<E; ++i) {
        fscanf(fp, "%s", vertex);

        cout << vertex << endl;

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
