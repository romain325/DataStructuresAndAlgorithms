#ifndef GRAPH_H
#define GRAPH_H

#include "Utils.h"

/* STRUCTURE DEFINITION */

typedef struct aNode{
	struct gNode* val; 
	struct aNode* next;
}ArcNode;

typedef ArcNode* ArcsList;

typedef struct gNode{
	struct gNode* next;
	int val;
	ArcNode* arcsList;
	Boolean marked;
}GNode;

typedef GNode* Graph;

/* PRIVATE FUNCTION */
// ERROR_TYPE hasArcPointer(ArcNode *dep, ArcNode *end);

/* METHOD DEFINITIONS */

Graph createEmptyGraph(void);

Boolean isGraphEmpty(Graph g);

Boolean isArcEmpty(ArcsList a);

ERROR_TYPE addNode(Graph *g, int val);

ERROR_TYPE addArc(Graph g, int startK, int endK);

ERROR_TYPE hasArc(Graph g, int startK, int endK);

ERROR_TYPE removeArc(Graph g, int startK, int endK);

GNode* findNode(Graph g, int key);

ERROR_TYPE removeNode(Graph g, int key);

int graphLength(Graph g);

int arcLength(GNode n);

int graphArcsLength(Graph g);

void printGraph(Graph g);

void printNode(GNode n);

ERROR_TYPE existingPath(Graph g, int bKey, int eKey); // Use Depth First Search Algorithm


// USE DOT FILE
/*
ERROR_TYPE saveToDot(Graph g, char* name);

ERROR_TYPE loadFromDot(Graph g, char* name);
*/


#endif