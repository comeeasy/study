#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int key;
  struct node *left;
  struct node *right;
} NODE;

NODE *insert_node (NODE * root, int key);
void print_inorder(NODE * root);

////////////////////////////////////////////////////////////////////////

NODE *insert_node (NODE * root, int key)
{
  if(root==NULL) {
    NODE * node = (NODE *)malloc(sizeof(NODE));
    node->key = key;
    node->left = node->right = NULL;
    return node;
  }

  if (key < root->key)
    root->left = insert_node(root->left, key);
  else
    root->right = insert_node(root->right, key);

  //return root;
}

void print_inorder(NODE * root)
{
  if(root == NULL) return;

  print_inorder(root-> left);
  printf("(%d)", root-> key);
  print_inorder(root-> right);
}

////////////////////////////////////////////////////////////////////////

int main() {
    int key;
    NODE* t1;

    printf("==== test-tree3 ====\n");

    key = 30;
    printf("insert=%d\n", key);
    t1 = insert_node(NULL, key);
    printf("tree=");
    print_inorder(t1);
    printf("\n");

    key = 80;
    printf("insert=%d\n", key);
    t1 = insert_node(t1, key);
    printf("tree=");
    print_inorder(t1);
    printf("\n");

    key = 90;
    printf("insert=%d\n", key);
    t1 = insert_node(t1, key);
    printf("tree=");
    print_inorder(t1);
    printf("\n");

    key = 10;
    printf("insert=%d\n", key);
    t1 = insert_node(t1, key);
    printf("tree=");
    print_inorder(t1);
    printf("\n");

    key = 70;
    printf("insert=%d\n", key);
    t1 = insert_node(t1, key);
    printf("tree=");
    print_inorder(t1);
    printf("\n");

    key = 50;
    printf("insert=%d\n", key);
    t1 = insert_node(t1, key);
    printf("tree=");
    print_inorder(t1);
    printf("\n");

    key = 60;
    printf("insert=%d\n", key);
    t1 = insert_node(t1, key);
    printf("tree=");
    print_inorder(t1);
    printf("\n");

    key = 20;
    printf("insert=%d\n", key);
    t1 = insert_node(t1, key);
    printf("tree=");
    print_inorder(t1);
    printf("\n");

    key = 40;
    printf("insert=%d\n", key);
    t1 = insert_node(t1, key);
    printf("tree=");
    print_inorder(t1);
    printf("\n");

    return EXIT_SUCCESS;
}

////////////////////////////////////////////////////////////////////////