#include "BinaryTree.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	BinaryTree tree;
	Node* node;
	int arrVal[] = {56,45,12,4,36,78,21,54,2,18,3};
	int arrVal2[] = {56,45,12,4,36,78,21,54,2,18,3};

	tree = createEmpty();
	insert(&tree, 6);
	insert(&tree, 6);
	insert(&tree, 7);

	insert(&tree, 420);

	printf("Binary Tree Asc Order\n");
	printAsc(tree);
	printf("\n");
	printf("Binary Tree Asc Order\n");
	printDesc(tree);

	node = searchValue(tree, 7);
	printf("\nResearch Result: %d\n\n",node->val);

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

	printf("Tree erasing");
	eraseTree(tree);

	return 0;
}