#ifndef ALGORITHMCOMPARE_HASHTCHAINING_H
#define ALGORITHMCOMPARE_HASHTCHAINING_H
typedef struct node {
    long long data;
    struct node* next;
} NODE;

typedef struct hashTableStruct {
    NODE** table;
    long long  size;
    long long  nOfElements, nOfCollisions;
    double alpha;
} HASHTABLE;

long long hash(long long x);
long long isPrime(long long x);
long long findNextPrime(long long x);
void printHashTable();
void addToLinkedList(NODE** table, long long hashed, long long data);
void createNewHashTable(long long number);
void hashT_insert(long long number);
long long hashT_search(long long number);
void hashT_initialize();
void printTableInfo();
#endif //ALGORITHMCOMPARE_HASHTCHAINING_H
