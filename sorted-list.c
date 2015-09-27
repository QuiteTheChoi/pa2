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

        return 1;

    }

    else {

        if (cf(list->head->data, newObj) < 0) { /*If the new object is greater than the head's data*/

            SortedListPtr newHead = (SortedListPtr) malloc(sizeof(SortedListPtr));

            newHead->data = newObj;

            newHead->next = list->head;

            list->head = newHead;

        }

          // list->head->next->

       /* SortedListPtr

        while (list->head){


        }*/

    }


}


