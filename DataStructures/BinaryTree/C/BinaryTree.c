#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

/* PRIVATE FUNCTION */
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



Boolean isEmpty(BinaryTree br){
	if(br == NULL) return TRUE;
	return FALSE;
}

BinaryTree createEmpty(void){
	return NULL;
}

Boolean insertNode(BinaryTree* br, int val){
	Node* tmp;
	tmp = searchValue(*br, val);
	if(tmp != NULL){
		return FALSE;
	}

	return insert(br, val);
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

Node* searchParent(BinaryTree  tree, int key){
	Node* tmp;

	if(isEmpty(tree)) return NULL;
	if(tree->val == key) return NULL;
	if((!isEmpty(tree->l) && tree->l->val == key) || (!isEmpty(tree->r) && tree->r->val == key)) return tree;

	tmp = searchParent(tree->l, key);
	if(!isEmpty(tmp)) return tmp; 

	tmp = searchParent(tree->r, key);
	if(!isEmpty(tmp)) return tmp;

	return NULL;
}

// Get Binary Tree Size
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

int getHeight(BinaryTree tree){
	int tmpL, tmpR;
	if(isEmpty(tree)) return -1;

	tmpL = getHeight(tree->l);
	tmpR = getHeight(tree->r);

	if(tmpL > tmpR) return tmpL +1;
	else return tmpR +1;
}

int getMin(BinaryTree tree){
	if(isEmpty(tree->l )){
		return tree->val;
	}
	return getMin(tree->l);
}

int getMax(BinaryTree tree){
	if(isEmpty(tree->r)){
		return tree->val;
	}
	return getMax(tree->r);
}

Boolean removeNode(BinaryTree tree, int key){
	int val;
	Node *selectedNode, *toRemoveParent, *tmp;

	// Search for the value we want to remove
	selectedNode = searchValue(tree, key);
	if(isEmpty(selectedNode)){return FALSE;}

	// If the node we want to remove doesn't have child then we remove it itself so we get his toRemove
	// Else we do take the min from the right branch if it exists or the max of the left branch
	if(isEmpty(selectedNode->r) && isEmpty(selectedNode->l)){
		val = key;
		toRemoveParent = searchParent(tree, key);
	}else{
		tmp = selectedNode;
		if(tmp->val == tree->val){
			if(!isEmpty(tmp->r)){
				tmp = tmp->r;
			}else{
				tmp = tmp->l;
			}
		}

		if(isEmpty(tmp->r)){
			val = getMax(tmp);
		}else{
			val = getMin(tmp);
		}
		toRemoveParent = searchParent(tmp, val);
		selectedNode->val = val;
	}


	if(!isEmpty(toRemoveParent->r) && toRemoveParent->r->val == val){		
		tmp = toRemoveParent->r;
		toRemoveParent->r = NULL;
	}
	if(!isEmpty(toRemoveParent->l) && toRemoveParent->l->val == val){
		tmp = toRemoveParent->l;
		toRemoveParent->l = NULL;
	}

	free(tmp);
	return TRUE;
		
}


// Function to print binary tree in 2D
void drawTree(BinaryTree tree, int space){
	int count = 1;

    if (isEmpty(tree)) 
        return; 
  
    space += count; 
  
    drawTree(tree->r, space); 

    for (int i = count; i < space; i++) 
        printf("\t"); 
    printf("-- %d|\n", tree->val); 
  
    drawTree(tree->l, space); 
} 