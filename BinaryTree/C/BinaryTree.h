#ifndef BINARYTREE_H
#define BINARYTREE_H

/// SSTRUCTURE DEFINITIONS

typedef enum { FALSE, TRUE } Boolean;

typedef struct node{
	int val;
	struct node* l;
	struct node* r;
}Node;

typedef Node* BinaryTree;

/// FUNCTION DEFINTION

BinaryTree createEmpty(void);

Boolean insert(BinaryTree* br, int val);

Boolean isEmpty(BinaryTree br);

void printAsc(BinaryTree tree);

void printDesc(BinaryTree tree);

void eraseTree(BinaryTree tree);

Node* searchValue(BinaryTree tree, int key); 

void sortArray(int array[],int size, Boolean ascOrder);

int getSize(BinaryTree tree);

int createAscArrayFromTree(BinaryTree tree,int array[] ,int index);

int createDescArrayFromTree(BinaryTree tree,int array[] ,int index);

int getHeight(BinaryTree tree);

#endif