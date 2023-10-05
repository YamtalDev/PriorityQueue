 /******************************************************************************
 * @writer:      Tal Aharon
 * @date:        19.03.2023
 * 
 * @description: This header file defines the interface for a sorted list data
 *               structure. A sorted list is a collection of elements sorted
 *               in a specific order according to a user-defined comparison
 *               function. The sorted list provides functions for creating,
 *               manipulating, and querying the list. It is built on top of a
 *               doubly linked list and maintains the sorted order of its
 *               elements.
 *
 *               The sorted list allows for efficient insertion, removal, and
 *               retrieval of elements while keeping them sorted. It provides
 *               iterators to traverse the list in order, as well as functions
 *               for merging two sorted lists and searching for specific
 *               elements within a given range.
 *
 *               Users of this header should provide their own comparison
 *               function, which defines the sorting order for the elements.
 *
 *               Detailed function descriptions and usage guidelines can be
 *               found in the comments within this header file.
 * 
******************************************************************************/
#ifndef __SORTED_LIST_H__
#define __SORTED_LIST_H__

#include <stddef.h> /*size_t, NULL */
#include "dll.h"    /*Internal API */

typedef struct sorted_list sorted_list_t;

typedef struct sorted_list_node
{
	dll_iter_t iterator;
	#ifndef NDEBUG
	sorted_list_t *list;
	#endif

} sorted_list_iter_t;

/******************************************************************************
 * @typedef sorted_list_compare_func_t
 * @brief   Function pointer type for sorting the list.
 * @return  This function compares two data elements and returns:
 * - Zero if the data elements are equal.
 * - A positive value if the new data should come before the current data.
 * - A negative value if the new data should come after the current data.
******************************************************************************/
typedef int (*sorted_list_compare_func_t) (void *data, void *new_data);

/******************************************************************************
 * @typedef sorted_list_ismatch_func_t
 * @brief   Function pointer type for matching data elements. This function checks 
 *          if the data element matches a parameter and returns non-zero if they match.
******************************************************************************/
typedef int (*sorted_list_ismatch_func_t) (void *data, void *parameter);

/******************************************************************************
 * @typedef sorted_list_action_func_t
 * @brief   Function pointer type for performing actions on data elements. This 
 *          function performs an action on a data element using a parameter and 
 *          returns zero on success.
******************************************************************************/
typedef int (*sorted_list_action_func_t) (void *data, void *parameter);

/******************************************************************************
 * @brief         Creates a new sorted list.
 * @param compare Function to use for sorting the list.
 * @return        Pointer to the created sorted list, or NULL if creation fails.
 * @note          Time Complexity: O(1)
******************************************************************************/
sorted_list_t *SortedListCreate(sorted_list_compare_func_t compare);

/******************************************************************************
 * @brief             Destroys a sorted list and its nodes.
 * @param sorted_list Pointer to the sorted list to be destroyed.
 * @note              Time Complexity: O(n)
******************************************************************************/
void SortedListDestroy(sorted_list_t *sorted_list);

/******************************************************************************
 * @brief             Returns the number of nodes in the sorted list.
 * @param sorted_list Pointer to the sorted list.
 * @return            Number of nodes in the sorted list.
 * @note              Time Complexity: O(n)
******************************************************************************/
size_t SortedListCount(const sorted_list_t *sorted_list);

/******************************************************************************
 * @brief             Returns an iterator pointing to the start of the sorted list.
 * @param sorted_list Pointer to the sorted list.
 * @return            Iterator pointing to the start of the sorted list.
 * @note              Time Complexity: O(1)
******************************************************************************/
sorted_list_iter_t SortedListBegin(const sorted_list_t *sorted_list);

/******************************************************************************
 * @brief             Returns an iterator pointing to the end of the sorted list.
 * @param sorted_list Pointer to the sorted list.
 * @return            Iterator pointing to the end of the sorted list.
 * @note              Time Complexity: O(1)
******************************************************************************/
sorted_list_iter_t SortedListEnd(const sorted_list_t *sorted_list);

/******************************************************************************
 * @brief          Returns an iterator to the next data in the sorted list.
 * @param iterator Iterator.
 * @return         Next iterator.
 * @note           Time Complexity: O(1)
******************************************************************************/
sorted_list_iter_t SortedListNext(const sorted_list_iter_t iterator);

/******************************************************************************
 * @brief          Returns an iterator to the previous data in the sorted list.
 * @param iterator Iterator.
 * @return         Previous iterator.
 * @note           Time Complexity: O(1)
******************************************************************************/
sorted_list_iter_t SortedListPrev(const sorted_list_iter_t iterator);

/******************************************************************************
 * @brief             Checks if the sorted list is empty.
 * @param sorted_list Pointer to the sorted list.
 * @return            Non-zero value if empty, 0 if not empty.
 * @note              Time Complexity: O(1)
******************************************************************************/
int SortedListIsEmpty(const sorted_list_t *sorted_list);

/******************************************************************************
 * @brief       Checks if two iterators in the sorted list are equal.
 * @param iter1 Iterator.
 * @param iter2 Iterator.
 * @return      Non-zero value if equal, 0 if not equal.
 * @note        Time Complexity: O(1)
******************************************************************************/
int SortedListIsEqual(const sorted_list_iter_t iter1, const sorted_list_iter_t iter2);

/******************************************************************************
 * @brief             Inserts data into the sorted list in the appropriate 
 *                    place and returns an iterator to it.
 * 
 * @param sorted_list Pointer to the sorted list.
 * @param data        Pointer to the data to be inserted.
 * @return            Iterator pointing to the inserted data, or end of the list 
 *                    if insertion fails.
 *
 * @note              Time Complexity: O(1)
******************************************************************************/
sorted_list_iter_t SortedListInsert(sorted_list_t *sorted_list, void *data);

/******************************************************************************
 * @brief          Removes the data that the iterator points to and returns 
 *                 the next iterator.
 * 
 * @param iterator Iterator pointing to the data to be removed.
 * @return         Iterator pointing to the next data after removal.
 * @note           Time Complexity: O(1)
******************************************************************************/
sorted_list_iter_t SortedListRemove(sorted_list_iter_t iterator);

/******************************************************************************
 * @brief      Removes and returns the data at the end of the sorted list.
 * @param list Pointer to the sorted list.
 * @return     Pointer to the removed data.
 * @note       Time Complexity: O(1)
******************************************************************************/
void *SortedListPopBack(sorted_list_t *list);

/******************************************************************************
 * @brief      Removes and returns the data at the start of the sorted list.
 * @param list Pointer to the sorted list.
 * @return     Pointer to the removed data.
 * @note       Time Complexity: O(1)
******************************************************************************/
void *SortedListPopFront(sorted_list_t *list);

/******************************************************************************
 * @brief          Gets the data at the position pointed to by the iterator.
 * @param iterator Iterator pointing to the data.
 * @return         Pointer to the data at the specified position.
 * @note           Time Complexity: O(1)
******************************************************************************/
void *SortedListGetData(const sorted_list_iter_t iterator);

/******************************************************************************
 * @brief        Merges two sorted lists together.
 * @param dest   Pointer to the destination sorted list.
 * @param source Pointer to the source sorted list.
 *               Both the destination and source lists must use the same sorting 
 *               function.
 *
 * @note         Time Complexity: O(n)
******************************************************************************/
void SortedListMerge(sorted_list_t *dest, sorted_list_t *source);

/******************************************************************************
 * @brief           Finds the iterator to a position with comparable data to 
 *                  the parameter.
 * 
 * @param list      Pointer to the sorted list.
 * @param from      Starting iterator.
 * @param to        Iterator pointing to the end of the range (not included).
 * @param parameter Pointer to the parameter used for comparison.
 * @return          Iterator pointing to the found position or "to" if not found.
 *                  "to" should be in the same list as "from" and after it.
 *
 * @note            Time Complexity: O(n)
******************************************************************************/
sorted_list_iter_t SortedListFind(const sorted_list_t *list, const sorted_list_iter_t from, const sorted_list_iter_t to, void *parameter);

/******************************************************************************
 * @brief           Finds the iterator to a position with matching data to the parameter.
 * @param from      Starting iterator.
 * @param to        Iterator pointing to the end of the range (not included).
 * @param match     Matching function.
 * @param parameter Pointer to the parameter used for matching.
 * @return          Iterator pointing to the found position or "to" if not found.
 *                  "to" should be in the same list as "from" and after it.
 *
 * @note            Time Complexity: O(n)
******************************************************************************/
sorted_list_iter_t SortedListFindIf(const sorted_list_iter_t from, const sorted_list_iter_t to, sorted_list_ismatch_func_t match, void *parameter);

/******************************************************************************
 * @brief           Do an action for every data in the given range. The order in 
 *                  the list should remain as is.
 * 
 * @param from      Starting iterator.
 * @param to        Iterator pointing to the end of the range (not included).
 * @param action    Action function.
 * @param parameter Pointer to the parameter used for the action.
 * @return          Zero on success, or the fail status of the action function on 
 *                  failure. Returns "to" if fails to find. "to" should be in the 
 *                  same list as "from" and after it. In debug mode, will check 
 *                  if "from" and "to" are from the same list.
 * 
 * @note            Time Complexity: O(n)
******************************************************************************/
int SortedListForEach(sorted_list_iter_t from, const sorted_list_iter_t to, sorted_list_action_func_t action, void *parameter);

#endif /* __SORTED_LIST_H__ */
