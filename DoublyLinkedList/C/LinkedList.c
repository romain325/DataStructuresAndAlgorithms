#include <stdio.h> 
#include <stdlib.h> 
#include "LinkedList.h"

LinkedList createEmptyList(void){
    return NULL; // An empty list point to nowhere
}

Boolean isEmpty(LinkedList list){
    if(list == NULL) return TRUE;
    return FALSE;
}

// Get through the list and return the length
int getLength(LinkedList list){
    int i = 0;
    if(isEmpty(list)) return 0;
    Node* tmp = list->next; // We create a variable as we don't want to change where the list is pointing at

    do{ // Get through all the list until we reach the end (represented by NULL)
        i++;
        tmp = tmp->next;
    }while (tmp != list->next);
    return i;
}

/*
// 1 - Allocate memory for a node and fill his value
// 2 - Make his "next" point to the actual beginning of the list
// 3 - Make the list pointer point to him
*/
Boolean push(LinkedList* list, int value){

    Node* tmp = (Node*) malloc(sizeof(Node));

    if(tmp == NULL){
        printf("Malloc Error");
        return FALSE;
    }

    tmp->value = value;

    if(isEmpty(*list)){
        *list = tmp;
        tmp->next = tmp;
        tmp->prev = tmp;
    }else{
        tmp->next = (*list)->next;
        tmp->prev = (*list);
        (*list)->next->prev = tmp;
        (*list)->next = tmp;
    }

    return TRUE;
}

Boolean append(LinkedList* list, int value){
    Node* tmp = (Node*) malloc(sizeof(Node));
    if(tmp == NULL){
        printf("Error Malloc");
        return FALSE;
    }

    tmp->value = value;
    if(isEmpty(*list) == TRUE){
        tmp->next = tmp;
        tmp->prev = tmp;
    }else{
        tmp->next = (*list)->next;
        tmp->prev = *list;
        (*list)->next->prev = tmp;
        (*list)->next = tmp;
    }
    *list = tmp;
    return TRUE;
}

/*
// 1 - Put the value in the pointer
// 2 - Remove the node and make the list point to the new head
// 3 - Free the memory of the removed node
*/
Boolean removeFirst(LinkedList* list,int* value){
    Node* tmp = (*list)->next;

    if(isEmpty(tmp)) return FALSE;

    *value = tmp->value; // Put the value in the return container
    if(tmp->next == tmp){
        *list = NULL;
    }else{
        tmp->next->prev = *list;
        (*list)->next = tmp->next;    // Get the head to the next node
    }
    
    free(tmp); // Free the memory

    return TRUE;
}

Boolean removeLast(LinkedList* list, int* value){
    Node* tmp;
    if(isEmpty(*list)){
        printf("Empty List");
        return FALSE;
    }

    tmp = *list;
    *value = tmp->value;

    if((*list)->prev == (*list)){
        *list = NULL;
    }else{
        (*list)->next->prev = tmp->prev;
        (*list) = tmp->prev;
        (*list)->next = tmp->next;
    }

    free(tmp);
    return TRUE;
}

/*
// 1 - Go through the list
// 2 - Search for the value
// 3 - Return the node pointer or NULL
*/
Node* getNode(LinkedList list,int key){
    Node* tmp = list;
    if(isEmpty(tmp))return NULL;
    do{
        if(tmp->value == key){
            return tmp;
        }
        tmp = tmp->next;
    }while(tmp != list);
    return NULL;
}


void printAll(LinkedList list){
    if(isEmpty(list)) return;
    Node* tmp = list->next;
    printf("===========================================\nValues:\n");
    do{
        printf("\t%d\n",tmp->value);
        tmp = tmp->next;
    }while(tmp != list->next);
    printf("===========================================\n");
}

void printAllBackward(LinkedList list){
    if(isEmpty(list)) return;
    Node* tmp = list;
    printf("===========================================\nValues:\n");
    do{
        printf("\t%d\n",tmp->value);
        tmp = tmp->prev;
    }while(tmp != list);
    printf("===========================================\n");
}