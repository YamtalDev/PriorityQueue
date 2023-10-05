#ifndef __SORTED_LIST_H__
#define __SORTED_LIST_H__

#include <stddef.h> /*size_t       */
#include "dll.h"   /*Internal use */

typedef struct sorted_list sorted_list_t;

typedef struct sorted_list_node
{
	dll_iter_t iterator;
	#ifndef NDEBUG
	sorted_list_t *list;
	#endif

} sorted_list_iter_t;


/* The function we will use to sort the list. "new_data" will be the data we
will insert into the list. Should return zero if "data" and "new_data" are
equal, positive if "new_data" should come before "data", and negative if after */
typedef int (*sorted_list_compare_func_t) (void *data, void *new_data);

/* Used in FindIf. Should return non-zero if "data" match the "parameter" */
typedef int (*sorted_list_ismatch_func_t) (void *data, void *parameter);

/* Used in ForEach. Will use "parameter" to act on "data". Will return zero on
sucsses and non-zero otherwise */
typedef int (*sorted_list_action_func_t) (void *data, void *parameter);

/* TC:O(1) Creation of a list. If creation fails return NULL. Gets a compare
function to sort with */
sorted_list_t *SortedListCreate(sorted_list_compare_func_t compare);

/* TC:O(n) Delete the list */
void SortedListDestroy(sorted_list_t *sorted_list);

/* TC:O(n) Returns the number of nodes in the list */
size_t SortedListCount(const sorted_list_t *sorted_list);

/* TC:O(1) Returns iterator pointing to the start of the list */
sorted_list_iter_t SortedListBegin(const sorted_list_t *sorted_list);

/* TC:O(1) Returns iterator pointing to the end of the list */
sorted_list_iter_t SortedListEnd(const sorted_list_t *sorted_list);

/* TC:O(1) Returns iterator to the next data in the list */
sorted_list_iter_t SortedListNext(const sorted_list_iter_t iterator);

/* TC:O(1) Returns iterator to the previous data in the list */
sorted_list_iter_t SortedListPrev(const sorted_list_iter_t iterator);

/* TC:O(1) Returns non-zero value if empty*/
int SortedListIsEmpty(const sorted_list_t *sorted_list);

/* TC:O(1) Returns non-zero value if equal. 
Function comparing if two iterators are the same.*/
int SortedListIsEqual(const sorted_list_iter_t iter1, const sorted_list_iter_t iter2);

/* TC:O(n) Adds data to the list in the appropriate place and returns iterator
to it. If failed, returns iterator to the end of the list */
sorted_list_iter_t SortedListInsert(sorted_list_t *sorted_list, void *data);

/* TC:O(1) Removes the data the iterator points to, and returns the next iterator */
sorted_list_iter_t SortedListRemove(sorted_list_iter_t iterator);

/* TC:O(1) Removes and returns the data in the end of the list */
void *SortedListPopBack(sorted_list_t *list);

/* TC:O(1) Removes and returns the data in the start of the list */
void *SortedListPopFront(sorted_list_t *list);

/* TC:O(1) Gets the data at the position pointed by iterator */
void *SortedListGetData(const sorted_list_iter_t iterator);

/* TC:O(n) Adds the data in source to the appropriate place in dest. Source
needs to use the same sorting function */
void SortedListMerge(sorted_list_t *dest, sorted_list_t *source);

/* TC:O(n) Returns the iterator to a position with compareable data to parameter
using the built in compare function. Returns "to" if fails to find any. "to"
should be in the same list as "from" and after it */
sorted_list_iter_t SortedListFind(const sorted_list_t *list, const sorted_list_iter_t from, const sorted_list_iter_t to, void *parameter);

/* TC:O(n) Returns the iterator to a position with matching data to parameter.
Returns "to" if fails to find. "to" should be in the same list as "from" and
after it */
sorted_list_iter_t SortedListFindIf(const sorted_list_iter_t from, const sorted_list_iter_t to, sorted_list_ismatch_func_t match, void *parameter);

/* TC:O(n) Do action for every data in the given range. The order in the list
should remain as is. Returns zero on success. On fail stops and return
the fail status of action. Returns "to" if fails to find. "to" should be in the
same list as "from" and after it. In debug mode, will check for if "from" and
"to" are from the same list */
int SortedListForEach(sorted_list_iter_t from, const sorted_list_iter_t to, sorted_list_action_func_t action, void *parameter);

#endif /* __SORTED_LIST_H__ */
