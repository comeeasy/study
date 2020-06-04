//==================================================================

typedef struct node {
    int key;
    struct node* left;
    struct node* right;
} NODE;

//==================================================================

NODE* insert_node(NODE* root, int key);
void print_inorder(NODE* root);

//==================================================================