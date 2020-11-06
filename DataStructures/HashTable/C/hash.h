#ifndef HASHTABLE_H
#define HASHTABLE_H

#define MALLOC_ERROR "Memory/Malloc Error"
#define MAX_SIZE 10

typedef struct item{
    int value;
    int key;
}Node;

typedef Node* hashArray[MAX_SIZE];
typedef Node* Item;


void initArray(hashArray arr);
void display(hashArray arr);
int del(hashArray arr, int key);
void insert(hashArray arr, int key, int value);
Item search(hashArray arr, int key);
int hashCode(int key);

#endif // HASHTABLE_H