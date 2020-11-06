#include "Utils.h"
#include <stdio.h>

void printResult(int err){
	printf("**RESULT**: ");

	switch(err){
		case NO:
			printf("False/No\n");
			break;
		case YES:
			printf("True/Yes\n");
			break;
		case UNEXISTANT_GNODE:
			printf("Gnode doesn't exist\n");
			break;
		case MALLOC_ERROR:
			printf("Error while allocating Memory\n");
			break;
		case FILE_OPENING_ERROR:
			printf("Error while opening a file\n");
			break;
		case ALREADY_EXISTING_NODE:
			printf("The node already exist in this graph\n");
			break;
		case EMPTY_LIST:
			printf("Empty List\n");
			break;
		case FILE_NOT_FOUND:
			printf("File Not Found\n");
			break;

		default:
			printf("Unknown Error code\n");
			break;
	}
}