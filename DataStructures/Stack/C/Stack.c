#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

Stack createEmptyStack(){
    return NULL;
}

Boolean isEmpty(Stack s){
    if(s == NULL)return TRUE;
    return FALSE;
}

void stackOn(Stack* s, int elt){
    Node* tmp = (Node*) malloc(sizeof(Node));
    if(tmp == NULL){
        printf("Mallox Error");
        exit(1);
    }

    tmp->val = elt;
    tmp->next = *s;
    *s = tmp;
}

Boolean unstack(Stack* s, int* val){ 
    Node* tmp;
    
    if(isEmpty(*s)){
        printf("Empty Stack");
        return FALSE;
    }

    tmp = *s;
    *val = tmp->val;
    *s = tmp->next;
    free(tmp);

    return TRUE;
}

Boolean getTop(Stack s, int* val){
    if(isEmpty(s)){
        printf("Empty Stack");
        return FALSE;
    }
    *val = (s)->val;
    return TRUE;
}

void printAllStack(Stack s){
    Node* it;

    printf("Stack Value:\n");
    if(isEmpty(s)){
        printf("\tEmpty Stack\n");
        return;
    }

    it = s;
    while(it != NULL){
        printf("\t%d\n", it->val);
        it = it->next;
    }
}