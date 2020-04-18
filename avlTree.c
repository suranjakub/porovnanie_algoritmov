#include <stdio.h>
#include <stdlib.h>

#include "avlTree.h"

//BST_NODE* avl_root;

BST_NODE* insert(BST_NODE* node, int value) {
    //if found empty node then put data in here
    if(node == NULL) {
        BST_NODE* new_node = malloc(sizeof(BST_NODE));
        new_node->data = value;
        new_node->left = new_node->right = NULL;
        new_node->height = 1;

        return new_node;
    }

    if(value < node->data)
        node->left = insert(node->left, value);
    else if(value > node->data)
        node->right = insert(node->right, value);
        //if there is same value in the tree
    else
        return node;

    //set greatest height of this node
    setHeight(node);
    int bf = getBalanceFactor(node);

    //L imbalance
    if(bf > 1) {
        //LL imbalance
        if(value < node->left->data)
            return rightRotation(node);
            //LR imbalance
        else if(value > node->left->data) {
            node->left = leftRotation(node->left);
            return rightRotation(node);
        }
    }
    //R imbalance
    if(bf < -1) {
        //RR imbalance
        if(value > node->right->data)
            return leftRotation(node);
            //RL imbalance
        else if(value < node->right->data) {
            node->right = rightRotation(node->right);
            return leftRotation(node);
        }
    }

    return node;
}

int max(int a, int b) {
    return (a >= b) ? a : b;
}

int getBalanceFactor(BST_NODE *node) {
    if(node == NULL)
        return 0;
    int left, right;
    left = right = 0;

    if(node->left != NULL)
        left = node->left->height;
    if(node->right != NULL)
        right = node->right->height;

    return left - right;
}

void setHeight(BST_NODE *node) {
    int leftHeight, rightHeight;
    leftHeight = rightHeight = 0;

    if( node->left != NULL )
        leftHeight = node->left->height;
    if( node->right != NULL )
        rightHeight = node->right->height;

    node->height = 1 + max(leftHeight, rightHeight);
}

BST_NODE* rightRotation(BST_NODE *node) {
    BST_NODE* bNode = node->left;

    //swap nodes
    node->left = bNode->right;
    bNode->right = node;

    //update heights of changed elements
    setHeight(node);
    setHeight(bNode);

    return bNode;
}

BST_NODE *leftRotation(BST_NODE *node) {
    BST_NODE* bNode = node->right;

    //swap nodes
    node->right = bNode->left;
    bNode->left = node;

    //update heights of changed elements
    setHeight(node);
    setHeight(bNode);

    return bNode;
}

void inorderPrint(BST_NODE* node) {
    if(node == NULL)
        return;

    inorderPrint(node->left);
    printf("%d ", node->data);
    inorderPrint(node->right);
}

int search(BST_NODE *root, int data) {
    BST_NODE* ptr = root;
    while (ptr != NULL) {
        if(data == ptr->data)
            return 1;
        else if(data < ptr->data)
            ptr = ptr->left;
        else if(data > ptr->data)
            ptr = ptr->right;
    }

    return 0;
}