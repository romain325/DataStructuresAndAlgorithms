#ifndef QUEUE
#define QUEUE

// INFORMATIONS --> In this version we're gonna use the circular version as I prefer to use it

#include "Queue.h"
#include <iostream>
struct node
{
    int val;
    struct node *next;
};

bool push(int val);
bool pop();
bool printAll();
bool isEmpty();

#endif // QUEUE_H
