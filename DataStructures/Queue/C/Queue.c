#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>


Queue createEmptyQueue(void){
    return NULL;
}

Boolean isEmpty(Queue q){
    if(q == NULL) return TRUE;
    return FALSE;
}

Boolean push(Queue *q, int value){
    Node* tmp;

    tmp = (Node*) malloc(sizeof(Node));
    if(tmp == NULL) return FALSE;

    tmp->val = value;

    if(isEmpty(*q)){
        tmp->next = tmp;
    }else{
        tmp->next = (*q)->next;
        (*q)->next = tmp;
    }

    *q = tmp;
    return TRUE;
}

Boolean pop(Queue *q, int *value){
    Node *tmp;
    if(isEmpty(*q)) return FALSE;

    tmp = (*q)->next;
    *value = tmp->val;

    if((*q)->next == (*q)){
        *q = NULL;
    }else{
        (*q)->next = tmp->next;
    }

    free(tmp);
    return TRUE;
}

void printAll(Queue q){
    Node* it = q->next;
    printf("Here is the data in the queue:\nhead\n");
    do{
        printf("\t%d\n", it->val);
        it = it->next;
    }while (it != q->next);
    printf("queue\n\n");
}