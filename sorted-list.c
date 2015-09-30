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
    SL->head = NULL;
    SL->next = (SortedListPtr)malloc(sizeof(SortedListPtr));
    SL->next = NULL;
    return SL;
}

/*Will insert nodes into sorted list, or create a head for new sorted list.
 * Reutrn 1 if successful, 0 if any other case. The sorted list is in descending
 * order*/
int SLInsert(SortedListPtr list, void *newObj) {

    SortedListPtr temp = (SortedListPtr) malloc(sizeof(SortedList));

    temp->data = newObj;
   
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
        
        else if (list->CompareFuncT(list->head->data, newObj) == 0) {  //Head and newObj is equal no need to insert data
            
            return 0;
        
        }
       
        else if (list->CompareFuncT(list->head->data, newObj) > 0 && list->head->next == NULL) { /*If the head's data is greater than the new object*/

            list->head->next = temp;

            return 1;

        }

        else {

            SortedListPtr curr = list->head; /*Points to the head of the list*/

            SortedListPtr prev = NULL; /*Initializes prev pointer*/

            while (curr->next != NULL) { /*While the pointer is not null*/

                int comp = list->CompareFuncT(curr->next->data, newObj); /*Stores the result of the comparison between curr->next's data and the new object in an int*/

                prev = curr; /*Makes the previous pointer the current pointer*/

                if (comp < 0) { /*If curr->next's data is less than the new object*/

                    temp->next = prev->next;
                    prev->next = temp;                    
                    
                    return 1;

                }

                else if (comp == 0) { /*If curr->next's data is equal to the new object*/

                    return 0;

                }

                else { /*If curr->next's data is greater than the new object*/

                    if (curr->next->next == NULL) { /*If curr->next->next is null*/

                        curr->next->next = temp; /*curr->next->next is temp*/

                        return 1;

                    }

                    else { /*If curr->next->next is not null*/

                        curr = curr->next; /*Moves on to the next pointer and continues the loop*/

                    }

                }
                
            }

            return 0;

        }

    }

}

<<<<<<< HEAD
int SLRemove(SortedListPtr list, void *newObj) {

    if (list == NULL) {

        return 0;

    }

    else {



    }

    return 0;

=======
SortedListIteratorPtr SLCreateIterator (SortedListPtr list) {
    SortedListIteratorPtr iter;
    
    if (list == NULL || list->head == NULL) 
        return NULL;
    else {
        iter = (SortedListIteratorPtr) malloc(sizeof(struct SortedListIterator));
        iter->CurrNode = list->head;
    }
    return iter;
}

void* SLGetItem(SortedListIterator iter) {
    SortedList
    if 
>>>>>>> 6befce3334a2f722c282763ce22354f4b14890ef
}
