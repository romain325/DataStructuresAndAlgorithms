#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    Queue q;
    int recipient;

    printf("First we create an empty queue and fill it with data.\n");
    q = createEmptyQueue();
    push(&q, 7);
    push(&q, 6);
    push(&q, 6);
    printAll(q);
    printf("Now we remove the last node.\n");
    pop(&q,&recipient);
    printAll(q);
    return 0;
}