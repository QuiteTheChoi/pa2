#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "sorted-list.h"

SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df) {
    SortedListPtr SL = (SortedListPtr)malloc(sizeof(SortedListPtr));
    SL -> CompareFuncT = (CompareFuncT)malloc(sizeof(CompareFuncT));
    SL -> CompareFuncT = cf;
    SL -> DestructFuncT = (DestructFuncT)malloc(sizeof(DestructFuncT)); 
    SL -> DestructFuncT = df;
    SL -> head = (SortedListPtr)malloc(sizeof(SortedListPtr));
    return SL;
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


