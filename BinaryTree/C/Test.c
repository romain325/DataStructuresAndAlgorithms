#include "BinaryTree.h"
#include <stdio.h>

int main(int argc, char const *argv[]){
	Boolean isOk;
	BinaryTree tree;
	Node* node;
	int arrVal[] = {56,45,12,4,36,78,21,54,2,18,3};
	int arrVal2[] = {56,45,12,4,36,78,21,54,2,18,3};

	tree = createEmpty();
	insertNode(&tree, 6);
	insertNode(&tree, 9);
	insertNode(&tree, 7);

	insertNode(&tree, 420);

	printf("Binary Tree Asc Order\n");
	printAsc(tree);
	printf("\n");
	printf("Binary Tree Desc Order\n");
	printDesc(tree);
	printf("\n");
	printf("Binary Tree Size:  %d\n", getSize(tree));
	printf("Binary Tree Height:  %d\n", getHeight(tree));

	node = searchValue(tree, 7);
	printf("\nResearch Result: %d",node->val);

	node = searchParent(tree, 7);
	printf("\nResearch Parent of 7, Result: %d\n",node->val);

	drawTree(tree,0);

	removeNode(tree, 9);
	printf("\nRemove Node 7 from tree.");
	printf("\nTree After remove:\n");

	drawTree(tree,0);

	printf("Array sorting(Asc&Desc): \nOrig:  ");
	for (int i = 0; i < sizeof(arrVal)/sizeof(*arrVal); i++){
		printf("%d  ", arrVal[i]);
	}

	sortArray(arrVal,sizeof(arrVal)/sizeof(*arrVal), TRUE);
	sortArray(arrVal2,sizeof(arrVal2)/sizeof(*arrVal2), FALSE);
	
	printf("\nAsc:   ");
	for (int i = 0; i < sizeof(arrVal)/sizeof(*arrVal); i++){
		printf("%d  ", arrVal[i]);
	}

	printf("\nDesc:  ");
	for (int i = 0; i < sizeof(arrVal2)/sizeof(*arrVal2); i++){
		printf("%d  ", arrVal2[i]);
	}

	eraseTree(tree);
	printf("\n\nTree erased\n");

	return 0;
}