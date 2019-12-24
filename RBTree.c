//
// Created by Bill on 24/12/2019.
//
#include "RBTree.h"
#include <stdlib.h>
#include <string.h>

_Bool isRed(Node *node) {
    if (node == NULL) return false;
    return node->color == RED;
}

Node* rotateLeft(Node *node) {
    Node *x = node->right;
    node->right = x->left;
    x->left = node;
    x->color = node->color;
    node->color = RED;
    x->N = node->N;
    node->N = 1 + node->left->N + node->right->N;
    return x;
}

Node* rotateRight(Node *node) {
    Node *x = node->left;
    node->left = x->right;
    x->right = node;
    x->color = node->color;
    node->color = RED;
    x->N = node->N;
    node->N = 1 + node->left->N + node->right->N;
    return x;
}

void flipColors(Node *node) {
    node->color = RED;
    node->left->color = BLACK;
    node->right->color = BLACK;
}

Node* put(Node *node,char *key, int val) {
    if (node == NULL) {
        node = (Node *) malloc(sizeof(Node *));
        node->key = key;
        node->value = val;
        node->N = 1;
        node->color = RED;
        return node;
    }
    int cmp = strcmp(key, node->key);
    if (cmp < 0) node->left = put(node->left, key, val);
    else if (cmp > 0) node->right = put(node->right, key, val);
    else node->value = val;
    return balance(node);

}

Node *balance(Node *node) {
    if (isRed(node->right) && !isRed(node->left)) node = rotateLeft(node);
    if (isRed(node->left) && isRed(node->left->left)) node = rotateRight(node);
    if (isRed(node->left) && isRed(node->right)) flipColors(node);

    node->N = node->left->N + node->right->N + 1;
    return node;
}

Node* moveRedLeft(Node *node){
    flipColors(node);
    if(isRed(node->left->right)){
        node->right=rotateRight(node->right);
        node=rotateLeft(node);
    }
    return node;
}
Node* deleteMin(Node *node) {
    if (node->left == NULL)return NULL;
    if (!isRed(node->left) && !isRed(node->left->left))
        node = moveRedLeft(node);
    node->left = deleteMin(node->left);
    return balance(node);
}

Node* moveRedRight(Node *node){
    flipColors(node);
    if(!isRed(node->left->left))
        node=rotateRight(node);
    return node;
}

Node* deleteMax(Node *node) {
    if (isRed(node->left))
        node = rotateRight(node);
    if (node->right == NULL)
        return NULL;
    if (!isRed(node->right) && !isRed(node->right->left))
        node = moveRedRight(node);
    node->right = deleteMax(node->right);
    return balance(node);
}

Node* delete(Node *node, char *key) {
    int cmp = strcmp(key, node->key);
    if (cmp < 0) {
        if (!isRed(node->left) && !isRed(node->left->left))
            node = moveRedLeft(node);
        node->left = delete(node->left, key);
    } else {
        if (isRed(node->left))
            node = rotateRight(node);
        if (cmp == 0 && node->right == NULL)
            return NULL;
        if (!isRed(node->right) && !isRed(node->right->left))
            node = moveRedRight(node);
        if (cmp == 0) {
            node->value = rbGet(node->right, rbMin(node->right)->key);
            node->key = rbMin(node->right)->key;
            node->right = deleteMin(node->right);
        } else {
            node->right = delete(node->right, key);
        }
    }
    return balance(node);
}

int rbGet(Node *node, char *key) {
    int cmp = strcmp(key, node->key);
    if (cmp < 0) return rbGet(node->left, key);
    else if (cmp > 0) return rbGet(node->right, key);
    else return node->value;
}

Node* rbMin(Node* node) {
    if (node->left == NULL) return node;
    return rbMin(node->left);
}