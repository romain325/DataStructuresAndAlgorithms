#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

void initArray(hashArray arr){
    for(int i=0; i < MAX_SIZE; i++){
        arr[i] = NULL;
    }
}

// THIS FUNCTION SHOULD BE PROHIBITED IN REAL CASE AND INSTEAD USE ONE FROM THE HashAlgorithms.c FILE
// THIS IS A DEMO TO EXPLAIN SIMPLY HOW IT WORKS
int hashCode(int key) {
    return key % MAX_SIZE;
}

Item search(hashArray arr, int key){
    int hashIndex = hashCode(key);

    while(arr[hashIndex] != NULL){
        if(arr[hashIndex]->key == key){
            return arr[hashIndex];
        }
        ++hashIndex;
        hashIndex %= MAX_SIZE;
    }
    return NULL;
}

void insert(hashArray arr, int key, int value){
    int hashIndex;
    Item item = (Node*) malloc(sizeof(Node));
    if(item == NULL){
        printf(MALLOC_ERROR);
        exit(1);
    }
    item->key = key;
    item->value = value;
    hashIndex = hashCode(key);
    while(arr[hashIndex] != NULL){
        ++hashIndex;
        hashIndex %= MAX_SIZE;
    }
    arr[hashIndex] = item;
}

int del(hashArray arr, int key){
    int hashIndex = hashCode(key);

    while(arr[hashIndex] != NULL){
        if(arr[hashIndex]->key == key){
            int tmp = arr[hashIndex]->value;
            arr[hashIndex] = NULL;
            free(arr[hashIndex]);
            return tmp;
        }

        ++hashIndex;
        hashIndex %= MAX_SIZE;
    }
    return -1;
}

void display(hashArray arr){
    for (int i = 0; i < MAX_SIZE; i++){
        if(arr[i] != NULL){
            printf("[%d]: {k:%d, v:%d}\n",i, arr[i]->key,arr[i]->value);
        }else{
            printf("[%d]: unassigned\n",i);
        }
    }
}