// ============================================================

typedef struct node {
    int data;
    struct node* link;
} NODE;

// ============================================================

void print_list(NODE* list);
int length_list(NODE* list);
NODE* nth_list(NODE* list, int n);
NODE* add_list(NODE* list, int item);
NODE* delete_list(NODE* list);

// ============================================================