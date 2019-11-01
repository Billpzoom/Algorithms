//
// Created by Bill on 1/11/2019.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct queue{
    Node* head;
    Node* rear;
}Queue;

int CreateQueue(Queue* queue) {
    queue->head = queue->rear = (Node *) malloc(sizeof(Node));
    queue->head->next=NULL;
    return 0;
}

int Enqueue(Queue* queue, int data)
{
    Node* pNode=(Node*)malloc(sizeof(Node));
    pNode->data=data;
    pNode->next=NULL;
    queue->rear->next=pNode;
    queue->rear=pNode;
}

int Dequeue(Queue* queue) {
    Node *pNode = queue->head->next;
    queue->head->next = pNode->next;
    int result = pNode->data;
    free(pNode);
    return result;
}


