#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "avlTree.h"

BST_NODE* avl_root;

void test1() {
    clock_t start, end;
    double time_taken;

    int lower = 0, upper = 1000000, x = 1000000;

    //fill array of x numbers
    int* array = (int*)malloc(x * sizeof(int));
    srand(time(0));
    for (int i = 0; i < x; i++)
        array[i] = (rand() % (upper - lower + 1)) + lower;

    printf("Inserting %d elements\n------\n", x);

    //AVL tree
    start = clock();
    for (int i = 0; i < x; i++)
        avl_root = insert(avl_root, array[i]);
    end = clock();
    time_taken = (double)(end-start) / CLOCKS_PER_SEC * 1000;
    printf("AVL Insert time is: %gms\n", time_taken);

    printf("\nSearching %d elements from array\n------\n", x);

    //AVL tree
    int found = 0;
    start = clock();
    for (int i = 0; i < x; i++)
        if(search(avl_root, array[i]))
            found++;
    end = clock();
    time_taken = (double)(end-start) / CLOCKS_PER_SEC * 1000;
    printf("AVL Search time is: %gms\n", time_taken);
    printf("Found %d elements", found);

}

int main() {

    test1();

    printf("\n");
    return 0;
}
