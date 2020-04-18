#ifndef ALGORITHMCOMPARE_AVLTREE_H
#define ALGORITHMCOMPARE_AVLTREE_H
typedef struct bst_node {
    int data, height;
    struct bst_node* left;
    struct bst_node* right;
} BST_NODE;

BST_NODE* insert(BST_NODE* node, int value);
int max(int a, int b);
int getBalanceFactor(BST_NODE* node);
void setHeight(BST_NODE* node);
BST_NODE* rightRotation(BST_NODE* node);
BST_NODE* leftRotation(BST_NODE* node);
void inorderPrint(BST_NODE* node);
int search(BST_NODE *root, int data);
#endif //ALGORITHMCOMPARE_AVLTREE_H
