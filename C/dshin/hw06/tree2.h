//==================================================================

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
 } NODE;

 //==================================================================

 NODE* create_node(int item);
 void add_child(NODE* root, NODE* left, NODE* right);
 int sum_tree(NODE* root);

 //==================================================================