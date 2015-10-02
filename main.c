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
    else return 0;
}

void destroyDouble(void* ptr){
    free(ptr);
}

int compareString(void* v1, void* v2) {
    char* s1 = (char *)v1;
    char* s2 = (char *)v2;
    return strcmp(s1, s2);
}

void destroyString(void* ptr){
   free(ptr);
}

void testProg (SortedListPtr testing,void* ptr1) {
    if(SLInsert(testing,ptr1) == 1) {
        printf("IT WAS INSERTED\n");
    }
    else
        printf("IT DIDN'T INSERT\n");
}


void testProg2 (SortedListPtr testing,void* ptr1) {
    if(SLRemove(testing,ptr1) == 1) {
        printf("IT WAS REMOVED\n");
    }
    else
        printf("IT WASN'T REMOVED\n");
}

void printSortedList(SortedListPtr ptr) {
    SortedListPtr curr = ptr;
    while (curr != NULL) {
        printf("%G\n",*(double*)curr->data);
        curr = curr->next;
    }
    return;
}

void printSortedList2(SortedListPtr ptr) {
    SortedListPtr curr = ptr->head;
    while (curr != NULL) {
        printf("%s\n", (char*)curr->data);
        curr = curr->next;
    }
    return;
}

int main() {

    double* test1 = (double*)malloc(sizeof(double)); 
    double* test2 = (double*)malloc(sizeof(double));
    double* test3 = (double*)malloc(sizeof(double));
    double* test4 = (double*)malloc(sizeof(double));
    
    *test1 = 2.4;
    *test2 = 2.5;
    *test3 = 2.8;
    *test4 = 2.6;

    void* ptr1 = test1;
    void* ptr2 = test2;
    void* ptr3 = test3;
    void* ptr4 = test4;

    printf("%G, %G\n", *test1, *test2);
    printf("%d\n",(int)(sizeof(CompareFuncT)));

    SortedListPtr testing = SLCreate(compareDouble, destroyDouble);

    testProg(testing,ptr1);
    testProg(testing,ptr2);
    testProg(testing,ptr1);
    testProg(testing,ptr2);
    testProg(testing,ptr3);
    testProg(testing,ptr4);
    testProg(testing,ptr3);
    
    SortedListIteratorPtr SL = SLCreateIterator (testing);

    printSortedList(SL->CurrNode);
    printSortedList(testing->head);

    char* test5 = (char*)malloc(sizeof(char)); 
    char* test6 = (char*)malloc(sizeof(char));
    char* test7 = (char*)malloc(sizeof(char));
    char* test8 = (char*)malloc(sizeof(char));
    
    test5 = "hello";
    test6 = "apple";
    test7 = "mango";
    test8 = "zebra";

    void* ptr5 = test5;
    void* ptr6 = test6;
    void* ptr7 = test7;
    void* ptr8 = test8;

    SortedListPtr testing2 = SLCreate(compareString, destroyString);

    testProg(testing2,ptr5);
    testProg(testing2,ptr6);
    testProg(testing2,ptr7);
    testProg(testing2,ptr8);

    printSortedList2(testing2);
    SortedListIteratorPtr StringIter = SLCreateIterator (testing2);

    printf("THIS IS A TEST%s\n",(char*)SLGetItem(StringIter));
    printf("THIS IS A TEST%s\n",(char*)SLNextItem(StringIter));
    printf("THIS IS A TEST%s\n",(char*)SLNextItem(StringIter));
    
    SortedListIteratorPtr iter = (SortedListIteratorPtr)malloc(sizeof(SortedListIteratorPtr));

    iter->CurrNode = StringIter->CurrNode;

    printf("THIS IS iter before something is removed %s\n",(char*)iter->CurrNode->data);
    
    
    testProg2(testing2,ptr5);

printf("THIS IS iter after something is removed %s\n",(char*)iter->CurrNode->data);

    printSortedList2(testing2);

    SLNextItem(StringIter);

printf("THIS IS iter after something is freed %s\n",(char*)iter->CurrNode->data);

    return 0;
}
