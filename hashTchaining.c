#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "hashTchaining.h"

HASHTABLE firstHashTable;
HASHTABLE* hashtable;

int hash(int x) {
    int a = 11, b = 13;
    return (a*x + b) % hashtable->size;
}

int isPrime(int x) {
    for(int i = 2; i < sqrt(x); i++)
        if(x % i == 0)
            return 0;
    return 1;
}

int findNextPrime(int x) {
    while(!isPrime(x++));
    return --x;
}

void printHashTable() {
    for (int i = 0; i < hashtable->size; ++i) {
        NODE* tmp = hashtable->table[i];
        printf("%d: ", i);
        while (tmp != NULL) {
            printf("%d -> ", tmp->data);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

void addToLinkedList(NODE** table, int hashed, int data) {
    //if no collision
    if(table[hashed]->data == 0)
        table[hashed]->data = data;
        //if collision
    else {
        NODE* newNode = (NODE*)malloc(sizeof(NODE));
        NODE* tmp = table[hashed];
        //find end of ll and insert newNode
        while(tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = newNode;

        //assign data to new node
        newNode->data = data;
        newNode->next = NULL;

        hashtable->nOfCollisions++;
    }

    hashtable->nOfElements++;
    hashtable->alpha = ((hashtable->nOfElements) * 1.0) / hashtable->size;
}

void createNewHashTable(int number) {
    int oldSize = hashtable->size;
    //reset global table fields
    hashtable->nOfElements = hashtable->nOfCollisions = 0;
    hashtable->alpha = 0.0;
    //count size of new table
    int newSize = (hashtable->size)*2;
    newSize = findNextPrime(newSize);
    hashtable->size = newSize;

    //create new table
    NODE** newHashTable = (NODE**)calloc(newSize, sizeof(NODE*));
    for (int i = 0; i < newSize; ++i)
        newHashTable[i] = (NODE*)calloc(1,sizeof(NODE));
    //printf("\nCreated new table with size %d, old one had %d\n\n", newSize, oldSize);

    //also we have to add recent number
    addToLinkedList(newHashTable, hash(number), number);

    //now rehash old table and put all nums to new table
    for (int j = 0; j < oldSize; ++j) {
        NODE* tmp = hashtable->table[j];
        while (tmp != NULL && tmp->data != 0) {
            int hashed = hash(tmp->data);
            addToLinkedList(newHashTable, hashed, tmp->data);
            tmp = tmp->next;
        }
    }
    //rehashed, we can update global hashtable
    hashtable->table = newHashTable;
}

void hashT_insert(int number) {
    int hashed = hash(number);

    //if load factor is quite normal
    if (hashtable->alpha < 0.5) {
        addToLinkedList(hashtable->table, hashed, number);
    }
        //factor is large, we need to create new hashtable
    else {
        //printHashTable();
        //we pass number, to add recent also
        createNewHashTable(number);
    }
}

int hashT_search(int number) {
    int hashed = hash(number);

    NODE* tmp = hashtable->table[hashed];
    while (tmp->data != number && tmp->next != NULL)
        tmp = tmp->next;

    if(tmp->data == number) {
        //printf("Found number %d\n", number);
        return 1;
    } else {
        //printf("Number %d was not found\n", number);
        return 0;
    }
}

void hashT_initialize() {
    //This way throws weird aplha numbers
    //hashtable = malloc(sizeof(HASHTABLE));
    hashtable = &firstHashTable;
    hashtable->size = 23;
    hashtable->table = (NODE**)calloc(hashtable->size, sizeof(NODE*));
    hashtable->alpha = 0;
    for (int i = 0; i < hashtable->size; ++i)
        hashtable->table[i] = (NODE*)calloc(1,sizeof(NODE));
}

void printTableInfo() {
    printf("\tLoad factor: %lf\n", hashtable->alpha);
    printf("\tNumber of collisions: %d\n", hashtable->nOfCollisions);
    printf("\tNumber of elements: %d\n", hashtable->nOfElements);
}