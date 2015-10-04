SLCreate(): Creates a sorted list and allocates space and initializes everything inside it. This happens in O(1) time.

SLInsert(): Takes a void* argument and inserts it (or doesn't) into the sorted list based on the comparator function.  If the sorted list has a head whose data is less than the new object, equal to the new object, or if the sorted list has no head, then this function will run in O(1) time. This function will also run in O(1) time if the list only has one node, the head, and its data is greater than the new object. If the sorted list has more than one object and the head's data is greater than the new object, then this function will run in O(n) time. 

SLRemove(): Takes a void* argument and removes the node in the sorted list containing data that matches it. If the sorted list has a head whose data is less than the new object, equal to the new object, or if the sorted list has no head, then this function will run in O(1) time. This function will also run in O(1) time if the list only has one node, the head, and its data is greater than the new object. If the sorted list has more than one object and the head's data is greater than the new object, then this function will run in O(n) time.

SLCreateIterator(): Allocates space for an iterator if a list exists, and makes it point to the head. This function runs in O(1) time whether there is a list or not.

SLGetItem(): Gets the data at the node that an iterator is pointing to, if the node exists. This function runs in O(1) time whether the node exists or not.

SLNextItem(): Gets the data at the node following the node that an iterator is pointing to, if that node exists. This function runs in O(1) time whether that node exists or not.

SLDestroy(): Frees a sorted list in O(1) time.

SLDestroyIterator(): Frees an iterator in O(1) time.
