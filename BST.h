//
// Created by 00000 on 13/12/2019.
//

#ifndef INC_131_ALGORITHMS_BST_H
#define INC_131_ALGORITHMS_BST_H

typedef struct node {
    char *key;
    int value;
    struct node *left, *right
}Node;

Node *root;

int N;

int BSTGet(Node *node, char *key);
Node*  BSTPut(Node *node, char *key, int val);
Node *MinKey(Node *node);
Node* Floor(Node *node, char *key);
Node* Select(Node *node, int k);
int Rank(Node *node, char *key);
Node *Delete(Node *node, char *key);

#endif //INC_131_ALGORITHMS_BST_H
