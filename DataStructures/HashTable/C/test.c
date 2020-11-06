#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    hashArray arr;
    initArray(arr);
    Item item;

    insert(arr,1, 6);
    insert(arr,2, 6);
    insert(arr,42, 7);
    insert(arr,4, 420);
    insert(arr,12, 69);
    insert(arr,27, 667);
    insert(arr,69, 213);

    display(arr);

    printf("Searching element with key 4\n");

    item = search(arr,37);

    if(item != NULL) {
        printf("Found: %d\n", item->value);
    } else {
        printf("Not Found\n");
    }

    printf("Deleting element with key 4 and search again\n");
    del(arr,37);
    item = search(arr,37);

    if(item != NULL) {
        printf("Found: %d\n", item->value);
    } else {
        printf("Not Found\n");
    }


    return 0;
}
