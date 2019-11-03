//
// Created by Bill on 11/3/2019.
//
#include <stdio.h>

#include "stack.h"

int main()
{
    Stack* stack=CreateStack();
    Push(stack,0);
    Push(stack,1);
    printf("%d\n",GetTop(stack));
    Pop(stack);
    printf("%d\n",GetTop(stack));
    Push(stack,2);
    printf("%d\n",GetTop(stack));
    Pop(stack);
    printf("%d\n",GetTop(stack));
    return 0;
}