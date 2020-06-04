//==================================================================

#define MAX_TREE_SIZE   16
#define ERROR           -1

//==================================================================

typedef struct tree {
    int data[MAX_TREE_SIZE];
} TREE;

//==================================================================

void init_tree(TREE* t);
void preorder_tree(TREE* t, int root);
void inorder_tree(TREE* t, int root);
void postorder_tree(TREE* t, int root);

//==================================================================