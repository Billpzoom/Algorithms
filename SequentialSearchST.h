//
// Created by 00000 on 3/12/2019.
//

#ifndef INC_131_ALGORITHMS_SEQUENTIALSEARCHST_H
#define INC_131_ALGORITHMS_SEQUENTIALSEARCHST_H

typedef struct node{
    char *key;
    int data;
    struct node *next;
}Node;

typedef struct chain{
    struct node* head;
    struct node* rear;
}Chain;

void SSSTInit();
Node *get(char *key);
void set(char *key, int data);
int size();
char **keys();
void delete(char *key);
#endif //INC_131_ALGORITHMS_SEQUENTIALSEARCHST_H
