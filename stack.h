//
// Created by Administrator on 11/3/2019.
//

#ifndef INC_022_ALGORITHMS_STACK_H
#define INC_022_ALGORITHMS_STACK_H



typedef struct node{
    int data;
    struct node *next;
}Stack;

int IsEmpty(Stack* stack);
int Pop(Stack* stack);
Stack* CreateStack();
void EmptyStack(Stack* stack);
void DestroyStack(Stack* stack);
void EmptyStack(Stack *stack);
int Push(Stack *stack, int data);
int GetTop(Stack* stack);

#endif //INC_022_ALGORITHMS_STACK_H