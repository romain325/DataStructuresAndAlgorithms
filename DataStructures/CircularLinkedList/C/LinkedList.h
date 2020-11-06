#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef enum { FALSE, TRUE } Boolean;

/** Def STRUCTURE **/
typedef struct node
{
	struct node* next;
	int value;
}Node;

typedef Node* LinkedList;


/** Def FUNC **/

LinkedList createEmptyList(void);

Boolean isEmpty(LinkedList list);

int getLength(LinkedList list);

Boolean push(LinkedList* list, int value);

Boolean insert(LinkedList* list, Node* key ,int value);

Boolean append(LinkedList* list, int value);

Boolean removeFirst(LinkedList* list,int* value);

Boolean removeFromKey(LinkedList* list, int key);

Node* getNode(LinkedList list,int key);

void printAll(LinkedList list);

#endif // LINKEDLIST_H