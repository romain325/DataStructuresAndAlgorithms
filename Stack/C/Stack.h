#ifndef STACK_H
#define STACK_H

typedef enum { FALSE, TRUE } Boolean;

typedef struct node {
    int val;
    struct node* next;
} Node;

typedef Node* Stack;

Stack createEmptyStack();

Boolean isEmpty(Stack s);

void stackOn(Stack* s, int elt);

Boolean unstack(Stack* s, int* val);

Boolean getTop(Stack s, int* val);

void printAllStack(Stack s);

#endif // STACK_H