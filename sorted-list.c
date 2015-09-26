#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "sorted-list.h"


SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df) {
    
}

int SLInsert(SortedListPtr list, void *newObj) {

    if (list->head == NULL) {

        SortedListPtr newHead = (SortedListPtr) malloc(sizeof(SortedListPtr));

        list->head = newHead;

    }

    else {



    }


}


