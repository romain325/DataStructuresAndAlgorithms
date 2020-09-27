#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main(int argc, char const *argv[])
{
    Boolean isOk;
    Stack s;
    int recipient;

    printf("Create empty stack and fill it\n");
    s = createEmptyStack();
    stackOn(&s, 7);
    stackOn(&s, 6);
    stackOn(&s, 6);
    stackOn(&s, 420);
    printAllStack(s);
    
    printf("Print the head without unstacking it\n");
    isOk = getTop(s, &recipient);
    printf("\t%d\n", recipient);

    printf("Unstacking first one and printing the stack\n");
    isOk = unstack(&s, &recipient);
    printAllStack(s);

    return 0;
}
