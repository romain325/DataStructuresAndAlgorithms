#include "graph.h"
#include "Utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	Graph g;

	printf("TEST----------------\n");

	printf("CREATE GRAPH--------\n");
	g = createEmptyGraph();

	printf("ADD NODES-----------\n");
	printResult(addNode(&g, 6));
	printResult(addNode(&g, 7));
	printResult(addNode(&g, 420));

	printf("CREATE ARC----------\n");
	printResult(addArc(g, 6,7));
	printResult(addArc(g, 6,6));
	printResult(addArc(g, 7,420));

	printGraph(g);

	printf("LENGTH GRAPH--------\n");
	printf("Nbr of nodes: %d\n", graphLength(g));
	printf("Nbr of arcs : %d\n", graphArcsLength(g));

	printf("REMOVE ARC----------\n");
	printResult(removeArc(g,6,7));

	printGraph(g);

	printf("REMOVE NODE---------\n");
	printResult(removeNode(g,7));

	printGraph(g);

	printf("EXISTING PATH-------\n");
	printResult(existingPath(g,6,7));
	printResult(existingPath(g,6,6));


	return 0;
}