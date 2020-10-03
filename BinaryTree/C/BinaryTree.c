#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

Boolean isEmpty(BinaryTree br){
	if(br == NULL) return TRUE;
	return FALSE;
}

BinaryTree createEmpty(void){
	return NULL;
}

// Insert a int value depending on his value
Boolean insert(BinaryTree* br, int val){
	Node* tmp;

	if (isEmpty(*br)){
		tmp = (Node*) malloc(sizeof(Node));
		if(tmp == NULL){
			printf("Malloc Error\n");
			exit(1);
		}
		tmp->val = val;
		tmp->l = NULL;
		tmp->r = NULL;
		*br = tmp;
		return TRUE;
	}

	if((*br)->val >= val)
		insert(&((*br)->l), val);
	else
		insert(&((*br)->r), val);

	return TRUE;
}


// FOLLOW INFIX PRINCIPE
void printAsc(BinaryTree tree){

	if(isEmpty(tree)) return;

	printAsc(tree->l);

	printf("%d\n", tree->val);

	printAsc(tree->r);

	return;
}

// FOLLOW INFIX PRINCIPE
void printDesc(BinaryTree tree){

	if(isEmpty(tree)) return;

	printDesc(tree->r);

	printf("%d\n", tree->val);

	printDesc(tree->l);

	return;
}

// Free recursively every node
void eraseTree(BinaryTree tree){

	if(isEmpty(tree)) return;

	eraseTree(tree->l);
	eraseTree(tree->r);

	free(tree);
}

// Search the first node that match the given key
Node* searchValue(BinaryTree tree, int key){
	Node* tmp;

	if(isEmpty(tree)) return NULL;
	if(tree->val == key) return tree;

	tmp = searchValue(tree->l, key);
	if(!isEmpty(tmp)) return tmp; 

	tmp = searchValue(tree->r, key);
	if(!isEmpty(tmp)) return tmp;

	return NULL;
}

int getSize(BinaryTree tree){
	if(isEmpty(tree)) return 0;
	return 1 + getSize(tree->l) + getSize(tree->r);
} 

void sortArray(int array[],int size, Boolean ascOrder){
	BinaryTree tree;

	tree = createEmpty();

	for (int i = 0; i < size; ++i){
		insert(&tree, array[i]);
	}

	if(ascOrder)
		size = createAscArrayFromTree(tree, array, 0);
	else
		size = createDescArrayFromTree(tree, array, 0);	

	return;
}

int createAscArrayFromTree(BinaryTree tree,int array[] ,int index) {
	if(isEmpty(tree)) return index;

	index = createAscArrayFromTree(tree->l, array, index);
	
	array[index] = tree->val;
	index++;

	index = createAscArrayFromTree(tree->r, array, index);

	return index;
}

int createDescArrayFromTree(BinaryTree tree,int array[] ,int index) {
	if(isEmpty(tree)) return index;

	index = createDescArrayFromTree(tree->r, array, index);
	
	array[index] = tree->val;
	index++;

	index = createDescArrayFromTree(tree->l, array, index);

	return index;
}