//
// Created by Bill on 2/12/2019.
//

#include <stdlib.h>
#include <string.h>
#include "SequentialSearchST.h"

Chain *chain;

void SSSTInit() {
    chain = (Chain *) realloc(chain, sizeof(Node *));
    chain->head = chain->rear = (Node *) malloc(sizeof(Node *));
    chain->head->key = "k_head";
    chain->head->data = 0;
    chain->rear->next = NULL;

    for (int i = 1; i < 10; ++i) {
        char *str_i = (char *) malloc(sizeof(2));
        itoa(i, str_i, 10);
        char *pre = "k_";
        char *key = (char *) malloc(strlen(pre) + strlen(str_i));
        strcpy(key, pre);
        strcat(key, str_i);
        set(key, i);
    }
}

Node *get(char *key) {
    for (Node *n = chain->head; n != NULL; n = n->next) {
        if (strcmp(key, n->key) == 0) {
            return n;
        }
    }
    return NULL;
}

void set(char *key, int data) {
    for (Node *n = chain->head; n != NULL; n = n->next) {
        if (strcmp(key, n->key) == 0) {
            n->data = data;
            return;
        }
    }
    Node *node = (Node *) malloc(sizeof(struct node));
    node->data = data;
    node->key = key;
    node->next = NULL;
    chain->rear->next = node;
    chain->rear = node;
}

int size() {
    int size = 0;
    for (Node *n = chain->head; n != NULL; n = n->next) {
        size += 1;
    }
    return size;
}
char **result;
char **keys() {
    result = (char **) malloc(sizeof(Node *) * size());
    int i = 0;
    for (Node *n = chain->head; n != NULL; n = n->next) {
        result[i] = (char *) malloc(sizeof(char) * 64);
        strcpy(result[i], n->key);
        i++;
    }
    return result;
}

void delete(char *key) {
    for (Node *n = chain->head; n->next != NULL; n = n->next) {
        if (strcmp(n->next->key, key) == 0) {
            Node *k = n->next;
            n->next = k->next;
            k->next = NULL;
            free(k);
        }
    }
}


