#ifndef SKIPLIST_H
#define SKIPLIST_H

#define SKIPLIST_MAX_LEVEL 6
#define MALLOC_ERROR "Space Allocation Error"

typedef struct snode {
    int key;
    int value;
    struct snode **forward;
} Node;

typedef struct skiplist {
    int level;
    int size;
    struct snode *header;
} SkipList;

SkipList* Init(SkipList *list);
int Insert(SkipList *list, int key, int value);
Node* Search(SkipList *list, int key);
int DeleteKey(SkipList *list, int key);
void Dump(SkipList *list);
void FreeNode(Node *x);

#endif // SKIPLIST_H