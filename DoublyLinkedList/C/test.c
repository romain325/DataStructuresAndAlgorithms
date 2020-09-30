#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    Boolean isOk;
    LinkedList l = createEmptyList();
    int value;

    isOk = push(&l, 9);
    isOk = push(&l, 12);
    isOk = push(&l, 46);
    printAll(l);
    printAllBackward(l);
    isOk = removeFirst(&l, &value);
    printf("Remove One\nNew Length: %d\nAdd a few more but at the end\n", getLength(l));
    append(&l, 15);
    append(&l, 56);
    append(&l, 69);
    printAll(l);
    printAllBackward(l);
    return 0;
}
