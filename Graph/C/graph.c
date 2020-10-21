#include "graph.h"
#include "Utils.h"
#include <stdio.h>
#include <stdlib.h>

/* **************** */
/* PRIVATE FUNCTIONS */
/* **************** */

ERROR_TYPE hasArcPointer(GNode *dep, GNode *end){
	ArcNode *start = dep->arcsList;

	while(!isArcEmpty(start)){
		if(start->val == end)
			return YES;

		start = start->next;
	}

	return NO;
}

void unmarkAll(Graph g){
	GNode *it = g;

	while(it != NULL){
		it->marked = FALSE;
		it = it->next;
	}
}

Boolean testPath(GNode* beg, GNode* end){
	ArcNode *tmp;
	Boolean ret;
	GNode *it;

	beg->marked = TRUE;
	if(beg == end) return TRUE;

	tmp = beg->arcsList;
	while(tmp != NULL){
		it = tmp->val;
		if(it->marked == FALSE){
			ret = testPath(it, end);
			if(ret) return TRUE;
		}
		tmp = tmp->next;
	}
	return FALSE;
}

/* **************** */
/* PUBLIC FUNCTIONS */
/* **************** */

Graph createEmptyGraph(void){
	return NULL;
}

Boolean isGraphEmpty(Graph g){
	if(g == NULL) return TRUE;
	return FALSE;
}

Boolean isArcEmpty(ArcsList a){
	if(a == NULL) return TRUE;
	return FALSE;
}

ERROR_TYPE addNode(Graph *g, int val){
	GNode *tmp;

	if(!isGraphEmpty(findNode(*g, val))){
		return ALREADY_EXISTING_NODE;
	}

	tmp = (GNode*) malloc(sizeof(GNode));
	if(tmp == NULL)
		return MALLOC_ERROR;

	tmp->val = val;
	tmp->marked = FALSE;
	tmp->arcsList = NULL;
	tmp->next = *g;
	*g = tmp;

	return YES;
}

ERROR_TYPE hasArc(Graph g, int startK, int endK){
	GNode *start, *end;

	start = findNode(g,startK);
	if(isGraphEmpty(start)){ return UNEXISTANT_GNODE; }

	end = findNode(g,endK);
	if(isGraphEmpty(end)){ return UNEXISTANT_GNODE; }

	return hasArcPointer(start, end);
}

GNode* findNode(Graph g, int key){
	GNode* it = g;

	while(!isGraphEmpty(it)){
		if(it->val == key){
			return it;
		}
		it = it->next;
	}

	return NULL;
}

ERROR_TYPE addArc(Graph g, int startK, int endK){
	GNode *start, *end;
	ArcNode* tmp;

	start = findNode(g,startK);
	if(isGraphEmpty(start)){ return UNEXISTANT_GNODE; }

	end = findNode(g,endK);
	if(isGraphEmpty(end)){ return UNEXISTANT_GNODE; }

	tmp = (ArcNode*) malloc(sizeof(ArcNode));
	if(tmp == NULL)
		return MALLOC_ERROR;

	tmp->next = start->arcsList;
	tmp->val = end;

	start->arcsList = tmp;

	return YES;
}

void printNode(GNode n){
	ArcNode* tmp = n.arcsList;

	printf("%d:\n", n.val);
	while(!isArcEmpty(tmp)){
		printf("\t->%d\n", tmp->val->val );
		tmp = tmp->next;
	}
}

void printGraph(Graph g){
	GNode* tmp = g;

	printf("\n=======Affichage Graph=======\n");
	while(!isGraphEmpty(tmp)){
		printNode(*tmp);
		tmp = tmp->next;
	}
	printf("\n=============================\n");
}

ERROR_TYPE removeArc(Graph g, int startK, int endK){
	GNode *start, *end;
	ArcNode* tmp, *it;
	ERROR_TYPE result;

	/* MAKE SURE THIS CONNECTION EXIST */
	start = findNode(g,startK);
	if(isGraphEmpty(start)){ return UNEXISTANT_GNODE; }

	end = findNode(g,endK);
	if(isGraphEmpty(end)){ return UNEXISTANT_GNODE; }

	result = hasArcPointer(start,end);

	if(result != YES)
		return result;

	/* REMOVE NODE */
	it = start->arcsList;

    // Check if the list is empty
    if(isArcEmpty(it))
        return EMPTY_LIST;

    // If the first node is the key, use the RemoveFirst function
    if(it->val == end){
    	tmp = it;
		start->arcsList = tmp->next;
    }else{
	    // Going through the list checking if the value of the next node is the key
	    while(!isArcEmpty(it->next)){
	        if(it->next->val == end){
	            tmp = it->next;         // Create a temporary var for the removed node
	            it->next = tmp->next;   // Make the Previous node pointing on the Next node so our middle isn't in the list anymore
	            break;
	        }
	        it = it->next;
	    }
    }
    free(tmp);
	return YES;
}

ERROR_TYPE removeNode(Graph g, int key){
	GNode *tmpN = g, *toRm, *precNode = NULL;
	ArcNode *tmpA, *tmpA2;
	ERROR_TYPE err;

	toRm = findNode(g,key);
	if(toRm == NULL)
		return UNEXISTANT_GNODE;
	tmpA = toRm->arcsList;
	// REMOVE ALL HIS OWN ARCS
	while(!isArcEmpty(tmpA)){
		tmpA2 = tmpA;
		tmpA = tmpA->next;
		err = removeArc(g, key, tmpA2->val->val);
		if(err != YES)
			return err;
	}

	// REMOVE ALL THE ARC POINTING TO HIM AND GRAB THE NODE BEFORE HIM
	while(!isGraphEmpty(tmpN)){
		if(hasArcPointer(tmpN, toRm)){
			err = removeArc(g, tmpN->val, toRm->val);
			if(err != YES)
				return err;
		}

		// GRAB THE NEXT NODE IF == KEY
		if(tmpN->next != NULL && tmpN->next->val == key){
			precNode = tmpN;
		}

		tmpN = tmpN->next;
	}

	if(precNode == NULL){
		g = toRm->next;
	}else{
		precNode->next = toRm->next;
	}

    free(toRm);

    return YES;
}

int graphLength(Graph g){
	GNode* tmp = g;
	int cpt = 0;
	while(!isGraphEmpty(tmp)){
		cpt += 1;
		tmp = tmp->next;
	}

	return cpt;
}

int arcLength(GNode n){
	ArcNode* tmp = n.arcsList;
	int cpt = 0;
	while(!isArcEmpty(tmp)){
		cpt += 1;
		tmp = tmp->next;
	}
	return cpt;
}

int graphArcsLength(Graph g){
	GNode* tmp = g;
	int cpt = 0;
	
	while(!isGraphEmpty(tmp)){
		cpt += arcLength(*tmp);
		tmp = tmp->next;
	}

	return cpt;
}

ERROR_TYPE existingPath(Graph g, int bKey, int eKey){
	GNode *beg,*end;

	beg = findNode(g, bKey);
	if(beg == NULL) return UNEXISTANT_GNODE;

	end = findNode(g, eKey);
	if(end == NULL) return UNEXISTANT_GNODE;

	unmarkAll(g);
	return testPath(beg, end);
}




/*
ERROR_TYPE saveToDot(Graph g, char* name){
	FILE* f;

	f = fopen(name,"r");
	if(f == NULL)
		return FILE_NOT_FOUND;

	fclose(f);
}

ERROR_TYPE loadFromDot(Graph g, char* name){
	FILE* f;
	int buffer_size = 255;
	char[buffer_size] buffer;

	f = fopen(name,"w");
	if(f == NULL)
		return FILE_NOT_FOUND;

	while(!feof(f)){
		fgets(buff,buffer_size, f);
		
		switch(buff){
			case 
		}
	}

	fclose(f);
}
*/


