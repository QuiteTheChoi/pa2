<<<<<<< HEAD
SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df) {
    
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "sorted-list.h"

int SLInsert(SortedListPtr list, void *newObj) {

    if (list->head == NULL) {

        SortedListPtr newHead = (SortedListPtr) malloc(sizeof(SortedListPtr));

        list->head = newHead;

    }

    else {



    }


}


>>>>>>> 3e625b4aab82424e4a34cb501f8d24a083189805
