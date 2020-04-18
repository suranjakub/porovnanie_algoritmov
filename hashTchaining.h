#ifndef ALGORITHMCOMPARE_HASHTCHAINING_H
#define ALGORITHMCOMPARE_HASHTCHAINING_H
typedef struct node {
    int data;
    struct node* next;
} NODE;

typedef struct hashTableStruct {
    NODE** table;
    int size, nOfElements, nOfCollisions;
    double alpha;
} HASHTABLE;

int hash(int x);
int isPrime(int x);
int findNextPrime(int x);
void printHashTable();
void addToLinkedList(NODE** table, int hashed, int data);
void createNewHashTable(int number);
void hashT_insert(int number);
int hashT_search(int number);
void hashT_initialize();
void printTableInfo();
#endif //ALGORITHMCOMPARE_HASHTCHAINING_H
