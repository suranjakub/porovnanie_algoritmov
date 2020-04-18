#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "avlTree.h"
#include "hashTchaining.h"
#include "rbTree.h"

BST_NODE* avl_root;
//struct rbNode *root = NULL;

void test1() {
    printf("TEST 1\n=======\n");

    clock_t start, end;
    double time_taken;

    int lower = 1, upper = 1000000, x = 1000000;

    //fill array of x numbers
    int* array = (int*)malloc(x * sizeof(int));
    srand(time(0));
    for (int i = 0; i < x; i++)
        array[i] = (rand() % (upper - lower + 1)) + lower;

    printf("Inserting %d elements\n-----------------\n", x);

    //AVL tree insert
    start = clock();
    for (int i = 0; i < x; i++)
        avl_root = insert(avl_root, array[i]);
    end = clock();
    time_taken = (double)(end-start) / CLOCKS_PER_SEC * 1000;
    printf("AVL insert time is: %gms\n", time_taken);

    //Hash Table Chaining insert
    start = clock();
    for (int i = 0; i < x; i++)
        hashT_insert(array[i]);
    end = clock();
    time_taken = (double)(end-start) / CLOCKS_PER_SEC * 1000;
    printf("HT-Chaining insert time is: %gms\n", time_taken);

    //Red Black Tree insert
    start = clock();
    for (int i = 0; i < x; i++)
        RBinsertion(array[i]);
    end = clock();
    time_taken = (double)(end-start) / CLOCKS_PER_SEC * 1000;
    printf("RB Tree insert time is: %gms\n", time_taken);

    //////////////////////////////////////////////////////////

    printf("\nSearching %d elements from array\n-----------------\n", x);

    //AVL tree search
    int found = 0;
    start = clock();
    for (int i = 0; i < x; i++)
        if( search(avl_root, array[i]) )
            found++;
    end = clock();
    time_taken = (double)(end-start) / CLOCKS_PER_SEC * 1000;
    printf("AVL Search time is: %gms, ", time_taken);
    printf("found %d elements\n", found);

    //Hash Table Chaining search
    found = 0;
    start = clock();
    for (int i = 0; i < x; i++)
        if( hashT_search(array[i]) )
            found++;
    end = clock();
    time_taken = (double)(end-start) / CLOCKS_PER_SEC * 1000;
    printf("HT-Chaining search time is: %gms, ", time_taken);
    printf("found %d elements", found);

    //RB Tree search
    found = 0;
    start = clock();
    for (int i = 0; i < x; i++)
        if( RBsearchElement(array[i]) )
            found++;
    end = clock();
    time_taken = (double)(end-start) / CLOCKS_PER_SEC * 1000;
    printf("\nRB Tree search time is: %gms, ", time_taken);
    printf("found %d elements", found);
}

void test2() {
    printf("TEST 2\n=======\n");

    clock_t start, end;
    double time_taken;

    int x = 1000000;

    //fill array of x numbers
    int* array = (int*)malloc(x * sizeof(int));
    srand(time(0));
    for (int i = 1; i <= x; i++)
        array[i-1] = i*2;

    printf("Inserting %d elements\n-----------------\n", x);

    //AVL tree insert
    start = clock();
    for (int i = 0; i < x; i++)
        avl_root = insert(avl_root, array[i]);
    end = clock();
    time_taken = (double)(end-start) / CLOCKS_PER_SEC * 1000;
    printf("AVL insert time is: %gms\n", time_taken);

    //Hash Table Chaining insert
    start = clock();
    for (int i = 0; i < x; i++)
        hashT_insert(array[i]);
    end = clock();
    time_taken = (double)(end-start) / CLOCKS_PER_SEC * 1000;
    printf("HT-Chaining insert time is: %gms\n", time_taken);
    printTableInfo();

    //Red Black Tree insert
    start = clock();
    for (int i = 0; i < x; i++)
        RBinsertion(array[i]);
    end = clock();
    time_taken = (double)(end-start) / CLOCKS_PER_SEC * 1000;
    printf("RB Tree insert time is: %gms\n", time_taken);

    //////////////////////////////////////////////////////////
}

int main() {
    hashT_initialize();

    //test1();
    test2();

    printf("\n");
    return 0;
}
