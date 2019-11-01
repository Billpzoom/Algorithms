//
// Created by Bill on 1/11/2019.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Stack;

int IsEmpty(Stack* stack);
int Pop(Stack* stack);

Stack* CreateStack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    if (stack != NULL)
    {
        stack->next=NULL;
        return stack;
    }
    printf("out of place.\n");
    return NULL;
}

void EmptyStack(Stack* stack)
{
    while (!IsEmpty(stack))
    {
        Pop(stack);
    }
    printf("stack is empty.\n");
}

void DestroyStack(Stack* stack)
{
    free(stack);
    printf("stack is destroyed");
    exit(0);
}

int IsEmpty(Stack* stack)
{
    return (stack->next==0);
}

int Push(Stack* stack, int data) {
    Stack *newst = (Stack *) malloc(sizeof(Stack));
    if (NULL != newst) {
        newst->data = data;
        newst->next = stack->next;
        stack->next = newst;
        return 1;
    }
    printf("push failed");
    return 0;
}

int Pop(Stack* stack) {
    Stack *tempst;
    if (!IsEmpty(stack)) {
        tempst = stack->next;
        stack->next = tempst->next;
        free(tempst);
        return 1;
    }
    return 0;
}

int GetTop(Stack* stack)
{
    if(!IsEmpty(stack))
    {
        return stack->next->data;
    }
    printf("stack is empty");
    return -1;
}