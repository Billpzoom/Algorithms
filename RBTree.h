//
// Created by Bill on 24/12/2019.
//
#include <stdbool.h>
#ifndef INC_131_ALGORITHMS_RBTREE_H
#define INC_131_ALGORITHMS_RBTREE_H


#define RED true
#define BLACK false

typedef struct node{
    char *key;
    int value;
    int N;
    struct node *left, *right;
    _Bool color;
}Node;

_Bool isRed(Node *node);
Node *balance(Node *node);
Node* rotateLeft(Node *node);
Node* rotateRight(Node *node);
void flipColors(Node *node);
Node* put(Node *node,char *key, int val);
Node* moveRedLeft(Node *node);
Node* moveRedRight(Node *node);
Node* deleteMin(Node *node);
Node* deleteMax(Node *node);
Node* delete(Node *node, char *key);
int rbGet(Node *node, char *key);
Node* rbMin(Node* node);

#endif //INC_131_ALGORITHMS_RBTREE_H
