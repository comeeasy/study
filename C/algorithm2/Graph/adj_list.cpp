#include "./header/adj_list.h"

///////////////////////////////////////////////////////
int char_to_int(char c) { return (int)(c-'A'); }
char int_to_char(int i) { return (char)(i+'A'); }
///////////////////////////////////////////////////////

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
        for(int i=0; i<E; ++i) {
            fscanf(fp, "%s", vertex);

            //cout << "vertex: " << vertex << endl;

            from = char_to_int(vertex[0]);
            to   = char_to_int(vertex[1]);

            node* new_node_to   = new node(to);
            node* new_node_from = new node(from);

            new_node_to->set_next(graph[from]);
            graph[from] = new_node_to;
            new_node_from->set_next(graph[to]);
            graph[to] = new_node_from;
        }
        fclose(fp);
    }
    else {
        cout << "source is not available\n";
    }
}
void listGraph::show_graph() const {
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

void listGraph::dfs_adj_list_nonrecur() const {
    vector<int> stack;
    int check[MAX_VERTEX], tmp;

    for(int i=0; i<V; ++i) check[i] = 0;
    for(int i=0; i<V; ++i) {
        if(check[i] == 0) {
            stack.push_back(i);
            check[i] = 1;

            while(!(stack.empty())) {
                tmp = stack.back();
                stack.pop_back();
                // visit()
                cout << "visit " << (char)(tmp+'A') << endl;
                for(node* j=graph[tmp]; j != NULL; j = j->get_next()) {
                    if(check[j->get_key()] == 0) {
                        stack.push_back(j->get_key());
                        check[j->get_key()] = 1;
                    }
                }
            }
        }
    }
}

void listGraph::bfs_adj_list_nonrecur() const {
    int check[MAX_VERTEX], tmp;
    queue<int> q;

    for(int i=0; i<MAX_VERTEX; ++i) check[i] = 0;
    for(int i=0; i<V; ++i) {
        if(check[i] == 0) {
            q.push(i);
            check[i] = 1;

            while(!(q.empty())) {
                tmp = q.front();
                q.pop();

                // visit()
                cout << "visit " << (char)(tmp+'A') << endl;

                for(node* j=graph[tmp]; j != NULL; j = j->get_next()) {
                    if( check[j->get_key()] == 0 ) {
                        q.push(j->get_key());
                        check[j->get_key()] = 1;
                    }
                }
            }
        }
    }
}

// my
/*
int listGraph::ap_non_recur() const {
    int check[MAX_VERTEX], tmp;
    int root_vertex, order=0;
    vector<int> stack;

    for(int i=0; i<V; ++i) check[i] = 0;
    for(int i=0; i<V; ++i) {
        // single spanning tree
        if(check[i] == 0) {
            root_vertex = i;
            stack.push_back(i);
            check[i] = ++order;

            while(!(stack.empty())) {
                tmp = stack.back();
                stack.pop_back();

                for(node* j=graph[tmp]; j!=NULL; j=j->get_next()) {
                    if(check[j->get_key()] == 0) {
                        stack.push_back(j->get_key());
                        check[j->get_key()] = ++order;
                    }
                }
            }
        }
        // for spanning tree is made up, find AP


    }
}
*/

// copy
/*
int check[MAX_VERTEX];
int listGraph::ap_recur(int i) {
    int min, m;

    check[i] = min = ++order;
    for(node* t=graph[i]; t!=NULL; t=t->get_next()) {
        if( i==0 && check[t->get_key()]==0 ) son_of_root++;
        if(check[t->get_key()]) {
            m = ap_recur(t->get_key());
            if(m < min) min = m;
            if(m >= check[i] && i != 0) {
                cout <<
            }
        }
    }
}
*/

//////////////////////////////////////////////////////////////

weightedListGraph::weightedListGraph() : V(0), E(0) {
    for(int i=0; i<MAX_VERTEX; ++i) graph[i] = NULL;
}
void weightedListGraph::input_data(const char* file_name) {
    string buf;
    int w ,from, to;
    weightedNode* new_node;
    ifstream is(file_name);

    if(is.is_open()) {
        cout << "file is open\n";

        is >> V >> E;
        for(int i=0; i<E; ++i) {
            is >> buf >> w;
            from = char_to_int(buf[0]);
            to   = char_to_int(buf[1]);

            new_node = new weightedNode(to, w);
            new_node->next = graph[from];
            graph[from] = new_node;

            new_node = new weightedNode(from, w);
            new_node->next = graph[to];
            graph[to] = new_node;
        }
    }
    else {
        cout << "file is not valid\n";
    }

    is.close();
}
void weightedListGraph::input_data(int from, int end, int weight) {
    weightedNode* new_node;

    ++V;
    ++E;

    new_node = new weightedNode(end, weight);
    new_node->next = graph[from];
    graph[from] = new_node;

    new_node = new weightedNode(from, weight);
    new_node->next = graph[end];
    graph[end] = new_node;
}
void weightedListGraph::show_graph() const {
    for(int i=0; i<V; ++i) {
        cout << '|' << int_to_char(i) << "|";
        for(weightedNode* horse=graph[i]; horse!=NULL; horse=horse->next) {
            cout << "->" << int_to_char(horse->vertex) << horse->weight;
        }
        cout << endl;
    }
}
/*
weightedListGraph* weightedListGraph::pfs_adjlist() {
    // tuple <weight, vertex>
    priority_queue< tuple<int, int>, vector< tuple<int, int> >,
                            greater< tuple<int, int> > > pq;
    //priority_queue<int, vector<int>, greater<int> > pq;
    int check[MAX_VERTEX], parent[MAX_VERTEX];
    int tmp;
    weightedListGraph wg;

    for(int i=0; i<MAX_VERTEX; ++i) {
        check[i] = UNSEEN;
        parent[i] = 0;
    }
    input_data("./source/weighted_graph.txt");
    for(int i=0; i<V; ++i) {
        if(check[i] == UNSEEN) {
            pq.push(make_tuple(i, 0));

            while(!pq.empty()) {
                tmp = get<0>(pq.top());
                pq.pop();
                for(weightedNode* horse=graph[tmp]; horse!=NULL; horse=horse->next) {
                    if(check[tmp] == 0 && ) {
                        pq.push(tmp);
                        parent[horse->vertex] = tmp;
                    }
                }
            }
        }
    }
*/
























}
