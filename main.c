#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "sorted-list.h"

int compareDouble(void* v1, void* v2) {
    double* d1 = (double*)v1;
    double* d2 = (double*)v2;

    if (*d1 < *d2)
        return -1;
    else if (*d1 > *d2)
        return 1;
    else
        return 0;
}

int main() {

    printf("Main is working.\n");
  

    double* test1 = (double*)malloc(sizeof(double)); 
    double* test2 = (double*)malloc(sizeof(double));
    *test1 = 2.4;
    *test2 = 2.5;

    void* ptr1 = test1;
    void* ptr2 = test2;

    printf("%G, %G\n", *test1, *test2);
    printf("%d\n",compareDouble(ptr1,ptr2));

    return 0;
}
