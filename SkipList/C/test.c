#include "SkipList.h"
#include <stdio.h>

int main() {
    int arr[] = {3, 6, 9, 2, 11, 1, 4}, i;
    SkipList list;
    Init(&list);

    printf("Insert:--------------------\n");
    for (i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        Insert(&list, arr[i], arr[i]);
    }
    Dump(&list);

    printf("Search:--------------------\n");
    int keys[] = {3, 4, 7, 10, 111};

    for (i = 0; i < sizeof(keys)/sizeof(keys[0]); i++) {
        Node *x = Search(&list, keys[i]);
        if (x) {
            printf("key = %d, value = %d\n", keys[i], x->value);
        } else {
            printf("key = %d, not found\n", keys[i]);
        }
    }

    printf("Search:--------------------\n");
    DeleteKey(&list, 3);
    DeleteKey(&list, 9);
    Dump(&list);

    return 0;
}