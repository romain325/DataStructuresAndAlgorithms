#include "SkipList.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define SKIPLIST_MAX_LEVEL 6
#define MALLOC_ERROR "Space Allocation Error"


SkipList* Init(SkipList *list) {
    int i;
    Node *header = (Node *)malloc(sizeof(Node));
    if(header == NULL){
        printf(MALLOC_ERROR);
        exit(1);
    }

    
    header->key = INT_MAX;
    header->forward = (Node **)malloc(sizeof(Node*) * (SKIPLIST_MAX_LEVEL+1));
    if(header->forward == NULL){
        printf(MALLOC_ERROR);
        exit(1);
    }
    for (i = 0; i <= SKIPLIST_MAX_LEVEL; i++) {
        header->forward[i] = header;
    }
    list->header = header;

    list->level = 1;
    list->size = 0;

    return list;
}

static int rand_level() {
    int level = 1;
    while (rand() < RAND_MAX/2 && level < SKIPLIST_MAX_LEVEL)
        level++;
    return level;
}

int Insert(SkipList *list, int key, int value) {
    Node *update[SKIPLIST_MAX_LEVEL+1];
    Node *x = list->header;
    int i, level;

    for (i = list->level; i >= 1; i--) {
        while (x->forward[i]->key < key)
            x = x->forward[i];
        update[i] = x;
    }
    x = x->forward[1];

    if (key == x->key) {
        x->value = value;
        return 0;
    } else {
        level = rand_level();
        if (level > list->level) {
            for (i = list->level+1; i <= level; i++) {
                update[i] = list->header;
            }
            list->level = level;
        }

        x = (Node *)malloc(sizeof(Node));
        if(x == NULL){
            printf(MALLOC_ERROR);
            exit(1);
        }
        
        x->key = key;
        x->value = value;
        x->forward = (Node **)malloc(sizeof(Node*) * (level + 1));
        if(x->forward == NULL){
            printf(MALLOC_ERROR);
            exit(1);
        }


        for (i = 1; i <= level; i++) {
            x->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = x;
        }
    }
    return 0;
}

Node* Search(SkipList *list, int key) {
    Node *x = list->header;
    int i;

    for (i = list->level; i >= 1; i--) {
        while (x->forward[i]->key < key)
            x = x->forward[i];
    }
    if (x->forward[1]->key == key) {
        return x->forward[1];
    } else {
        return NULL;
    }
    return NULL;
}

void FreeNode(Node *x) {
    if (x) {
        free(x->forward);
        free(x);
    }
}

int DeleteKey(SkipList *list, int key) {
    int i;
    Node *update[SKIPLIST_MAX_LEVEL + 1];
    Node *x = list->header;

    for (i = list->level; i >= 1; i--) {
        while (x->forward[i]->key < key)
            x = x->forward[i];
        update[i] = x;
    }

    x = x->forward[1];
    if (x->key == key) {
        for (i = 1; i <= list->level; i++) {
            if (update[i]->forward[i] != x)
                break;
            update[i]->forward[i] = x->forward[i];
        }
        FreeNode(x);

        while (list->level > 1 && list->header->forward[list->level] == list->header)
            list->level--;
        return 0;
    }
    return 1;
}

void Dump(SkipList *list) {
    Node *x = list->header;

    while (x && x->forward[1] != list->header) {
        printf("%d[%d]->", x->forward[1]->key, x->forward[1]->value);
        x = x->forward[1];
    }
    printf("END\n");
}
