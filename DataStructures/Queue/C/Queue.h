#ifndef QUEUE_H
#define QUEUE_H

// INFORMATIONS --> In this version we're gonna use the circular version as I prefer to use it


typedef enum { FALSE, TRUE } Boolean;

typedef struct node {
    int val;
    struct node *next;
}Node;

typedef Node* Queue;


#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>


Queue createEmptyQueue(void);

Boolean isEmpty(Queue q);

Boolean push(Queue *q, int value);

Boolean pop(Queue *q, int *value);

void printAll(Queue q);

#endif // QUEUE_H