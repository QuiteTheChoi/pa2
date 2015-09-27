#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "sorted-list.h"

SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df) {
    SortedListPtr SL = (SortedListPtr)malloc(sizeof(SortedList));
    SL->CompareFuncT = (CompareFuncT)malloc(sizeof(CompareFuncT));
    SL->CompareFuncT = cf;
    SL->DestructFuncT = (DestructFuncT)malloc(sizeof(DestructFuncT)); 
    SL->DestructFuncT = df;
    SL->head = (SortedListPtr)malloc(sizeof(SortedListPtr));
    SL->next = (SortedListPtr)malloc(sizeof(SortedListPtr));
    return SL;
}

int SLInsert(SortedListPtr list, void *newObj) {

    SortedListPtr temp = (SortedListPtr) malloc(sizeof(SortedList));
    temp -> data = newObj;
   
    if (list->head == NULL) {
        list->head = temp;
        return 1;
    }

    else {
        if (list->CompareFuncT(list->head->data, newObj) < 0) { /*If the new object is greater than the head's data*/
            temp->next = list->head;
            list->head = temp;
            return 1;
        }
        else if (list->CompareFuncT(list->head->data, newObj) == 0) {  //Head and newObj is equal no need to insert data in
            return 0;
        }
        else if (list->head->next == NULL) {    //This is if new obj is smaller and there is no next from head
            list -> head -> next = temp;
            return 1;
        }

        

          // list->head->next->

       /* SortedListPtr

        while (list->head){


        }*/

    }
    return 0;
}
