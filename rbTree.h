#ifndef ALGORITHMCOMPARE_RBTREE_H
#define ALGORITHMCOMPARE_RBTREE_H
enum nodeColor {
    RED,
    BLACK
};

struct rbNode {
    int data, color;
    struct rbNode *link[2];
};

//struct rbNode *root = NULL;

struct rbNode * createNode(int data);
void RBinsertion (int data);
void RBdeletion(int data);
int RBsearchElement(int data);
void RBinorderTraversal(struct rbNode *node);
#endif //ALGORITHMCOMPARE_RBTREE_H
