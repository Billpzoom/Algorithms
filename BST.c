//
// Created by Bill on 19/12/2019.
//
#include <string.h>
#include <ddk/ntddk.h>

#include "BST.h"

int BSTGet(Node *node, char *key) {
    int cmp = strcmp(key, node->key);
    if (cmp < 0) return BSTGet(node->left, key);
    else if (cmp > 0) return BSTGet(node->right, key);
    else return node->value;
}

Node* BSTPut(Node *node, char *key, int val) {
    int cmp = strcmp(node->key, key);
    if (cmp < 0)node->left = BSTPut(node->left, key, val);
    else if (cmp > 0)node->right = BSTPut(node->right, key, val);
    else node->value = val;
    return node;
}

Node *MinKey(Node* node) {
    if (node->left == NULL) return node;
    return MinKey(node->left);
}

Node *Floor(Node *node, char *key) {
    if (node == NULL) return NULL;
    int cmp = strcmp(key, node->key);
    if (cmp == 0) return node;
    if (cmp < 0) return Floor(node->left, key);
    Node *t = Floor(node->right, key);
    if (t != NULL)return t;
    else return node;
}

Node* Select(Node *node, int k) {
    if (node == NULL) return NULL;
    int t = sizeof(node->left);
    if (t > k)return Select(node->left, k);
    else if (t < k) return Select(node->right, k - t - 1);
    else return node;
}

int Rank(Node *node, char *key) {
    if (node == NULL) return 0;
    int cmp = strcmp(key, node->key);
    if (cmp < 0)return Rank(key, node->left);
    else if (cmp > 0)return 1 + sizeof(node->left) + Rank(key, node->right);
    else return sizeof(node->left);
}

Node* DeleteMin(Node *node) {
    if (node->left == NULL)return node->right;
    node->left = DeleteMin(node->left);
    return node;
}

Node *Delete(Node *node, char *key) {
    if (node == NULL)return NULL;
    int cmp = strcmp(key, node->key);
    if (cmp < 0) node->left = Delete(node->left, key);
    else if (cmp > 0) node->right = Delete(node->right, key);
    else {
        if (node->right == NULL) return node->left;
        if (node->left == NULL) return node->right;
        Node *t = node;
        node = MinKey(node->right);
        node->right = DeleteMin(node->right);
        node->left = t->left;
    }
    return node;
}