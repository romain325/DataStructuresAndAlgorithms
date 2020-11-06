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
    Node* tmp = list; // We create a variable as we don't want to change where the list is pointing at

    while (tmp != NULL){ // Get through all the list until we reach the end (represented by NULL)
        i++;
        tmp = tmp->next;
    }
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
   tmp->next = *list;
   
   *list = tmp;
   return TRUE;
}

/*
// 1 - Go to the end
// 2 - Create Node
// 3 - Link last node to our node
*/
Boolean append(LinkedList* list, int value){
    Node *tmp, *it = list;

    //if empty, add with the other function and return the same result
    if(list == NULL){
        return push(list, value);
    }

    tmp = (Node*) malloc(sizeof(Node));
    if(tmp == NULL){
        printf("Malloc Error");
        return FALSE;
    }
    tmp->value = value;
    tmp->next = NULL;

    // We check if the next one is null
    // This way we can get the last node before null
    while(!isEmpty(it->next)){
        it = it->next;
    }
    
    it->next = tmp;
    return TRUE;
}

/*
// 1 - Check for the specified node
// 2 - If exist, add after this node
// 3 - Else Return False
*/
Boolean insert(LinkedList* list, Node* key ,int value){
    Node *it = list, *tmp;

    if(isEmpty(it)){
        return push(list, value);
    }    

    while (!isEmpty(it))
    {
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
    }
    return FALSE;
}

/*
// 1 - Put the value in the pointer
// 2 - Remove the node and make the list point to the new head
// 3 - Free the memory of the removed node
*/
Boolean removeFirst(LinkedList* list,int* value){
    Node* tmp = (*list);

    *value = tmp->value; // Put the value in the return container
    *list = tmp->next;    // Get the head to the next node
    free(tmp); // Free the memory

    return TRUE;
}

/*
// 1 - Search for the key
// 2 - Remove the first node with this key
// 3 - Return False if no key found
*/
Boolean removeFromKey(LinkedList* list, int key){
    Node *it = list, *tmp;
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
    while(!isEmpty(it->next)){
        if(it->next->value == key){
            tmp = it->next;         // Create a temporary var for the removed node
            it->next = tmp->next;   // Make the Previous node pointing on the Next node so our middle isn't in the list anymore
            free(tmp);              // Free the node
            return TRUE;
        }
        it = it->next;
    }
    return FALSE;

}

/*
// 1 - Go through the list
// 2 - Search for the value
// 3 - Return the node pointer or NULL
*/
Node* getNode(LinkedList list,int key){
    Node* tmp = list;

    while(!isEmpty(tmp)){
        if(tmp->value == key){
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}


void printAll(LinkedList list){
    Node* tmp = list;
    printf("===========================================\nValues:\n");
    while(!isEmpty(tmp)){
        printf("\t%d\n",tmp->value);
        tmp = tmp->next;
    }
    printf("===========================================\n");
}