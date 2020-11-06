#include <stdio.h> 
#include <stdlib.h> 
#include "LinkedList.h"

int main(int argc, char *argv[]){
    Boolean isOk;
    LinkedList l = createEmptyList();
    int value;

    isOk = push(&l, 9);
    isOk = push(&l, 12);
    isOk = push(&l, 46);
    printAll(l);
    isOk = removeFirst(&l, &value);
    printf("Remove One\nNew Length: %d\n", getLength(l));
    append(&l, 15);
    append(&l, 56);
    append(&l, 69);
    insert(&l, getNode(l,56), 12);
    printAll(l);
    removeFromKey(&l, 56);
    printAll(l);
}