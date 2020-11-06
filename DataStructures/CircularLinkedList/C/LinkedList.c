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
    }while (tmp != list);
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
    }else{
        tmp->next = (*list)->next;
        (*list)->next = tmp;
    }

    return TRUE;
}

/*
// 1 - Go to the end
// 2 - Create Node
// 3 - Link last node to our node
*/
Boolean append(LinkedList* list, int value){
    Node *tmp;

    //if empty, add with the other function and return the same result
    if(isEmpty(*list)){
        return push(list, value);
    }

    tmp = (Node*) malloc(sizeof(Node));
    if(tmp == NULL){
        printf("Malloc Error");
        return FALSE;
    }

    tmp->value = value;
    tmp->next = (*list)->next;
    (*list)->next = tmp;
    (*list) = tmp;
    return TRUE;
}

/*
// 1 - Check for the specified node
// 2 - If exist, add after this node
// 3 - Else Return False
*/
Boolean insert(LinkedList* list, Node* key ,int value){
    Node *it = *list, *tmp;

    if(isEmpty(it)){
        return push(list, value);
    }    

    do{
        if(it == key){
            tmp = (Node*) malloc(sizeof(Node));
            if(tmp == NULL){
                printf("Malloc Error");
                return FALSE;
            }
            tmp->value = value;
            tmp->next = it->next;
            it->next = tmp;
            return TRUE;
        }
        it = it->next;
    }while(it != list);
    return FALSE;
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
        (*list)->next = tmp->next;    // Get the head to the next node
    }
    
    free(tmp); // Free the memory

    return TRUE;
}

/*
// 1 - Search for the key
// 2 - Remove the first node with this key
// 3 - Return False if no key found
*/
Boolean removeFromKey(LinkedList* list, int key){
    Node *it = *list, *tmp;
    int bin;
    // Check if the list is empty
    if(isEmpty(it)){
        printf("Empty List");
        return FALSE;
    }

    // If the first node is the key, use the RemoveFirst function
    if(it->value == key){
        return removeFirst(list, &bin);
    }

    // Going through the list checking if the value of the next node is the key
    do{
        if(it->next->value == key){
            tmp = it->next;         // Create a temporary var for the removed node
            it->next = tmp->next;   // Make the Previous node pointing on the Next node so our middle isn't in the list anymore
            free(tmp);              // Free the node
            return TRUE;
        }
        it = it->next;
    }while(it != list);
    return FALSE;

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