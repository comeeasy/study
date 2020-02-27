#include "./header/adj_list.h"

listGraph::listGraph() : V(0), E(0) {
    for(int i=0; i<MAX_VERTEX; ++i) graph[i] = NULL;
}
void listGraph::input_adj_list(const char* source_file) {
    char vertex[3];
    int from, to;
    FILE* fp;

    fp = fopen(source_file, "r");
    if(fp){
        fscanf(fp, "%d %d", &V, &E);

        cout << "V: " << V << " E: " << E << endl;

        for(int i=0; i<E; ++i) {
            fscanf(fp, "%s", vertex);

            cout << "vertex: " << vertex << endl;

            from = char_to_int(vertex[0]);
            to   = char_to_int(vertex[1]);

            node* new_node_to   = new node(to);
            node* new_node_from = new node(from);

            // graph[i] == NULL
            if(graph[i] == NULL) {
                graph[from] = new_node_to;
                graph[to]   = new_node_from;
            }
            // graph[i] != NULL
            else {
                new_node_to->set_next(graph[from]);
                graph[from] = new_node_to;
                new_node_from->set_next(graph[to]);
                graph[to] = new_node_from;
            }

            //cout << vertex << " is alligned\n";
        }
        fclose(fp);
    }
    else {
        cout << "source is not available\n";
    }
}
void listGraph::show_graph() {
    node* iterator;
    for(int i=0; i<V; ++i) {
        iterator = graph[i];
        cout <<'|'<<(char)(i+'A')<<'|';

        while( iterator ) {
            cout << "->" << (char)( (iterator->get_key()) + 'A' );
            if( !(iterator->is_next_null()) ) {
                iterator = iterator->get_next();
            }
            else break;
        }
        cout << endl;
    }
}
int listGraph::char_to_int(char c) { return (int)(c-'A'); }
char listGraph::int_to_char(int i) { return (char)(i+'A'); }
