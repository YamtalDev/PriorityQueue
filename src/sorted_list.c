/******************************************************************************
 * @writer:      Tal Aharon
 * @date:        19.03.2023
 *
 * @description: This implementation file contains the actual implementation
 *               of the functions declared in the sorted_list.h header file.
 *               It provides the logic for creating, manipulating, and
 *               querying the sorted list data structure.
 *
 *               The implementation relies on a doubly linked list to maintain
 *               the sorted order of elements. It uses user-defined comparison
 *               functions to determine the order of elements during insertion
 *               and searching operations.
 *
 *               Users of this implementation can create sorted lists, insert,
 *               remove, and query elements efficiently while ensuring that
 *               the list remains sorted at all times.
 *
 *               The code is organized according to the function prototypes
 *               defined in sorted_list.h, and each function is documented
 *               with details about its purpose and usage.
 *
 *****************************************************************************/
#include <assert.h>      /* assert       */
#include <stdlib.h>      /* malloc, free */

#include "sorted_list.h" /* Internal API */
/*****************************************************************************/
struct sorted_list
{
	dll_t *dll;
	sorted_list_compare_func_t cmp;
};

/******************************************************************************
 * @brief         Creates a new sorted list.
 * @param compare Function to use for sorting the list.
 * @return        Pointer to the created sorted list, or NULL if creation fails.
 * @note          Time Complexity: O(1)
******************************************************************************/
sorted_list_t *SortedListCreate(sorted_list_compare_func_t compare)
{
	sorted_list_t *sorted_list = (sorted_list_t *)malloc(sizeof(sorted_list_t));
	if(NULL == sorted_list)
	{
		return (NULL);
	}

	sorted_list->dll = DLLCreate();
	if(NULL == sorted_list->dll)
	{
		free(sorted_list);
		return (NULL);
	}

	sorted_list->cmp = compare;
	return (sorted_list);
}

/******************************************************************************
 * @brief             Destroys a sorted list and its nodes.
 * @param sorted_list Pointer to the sorted list to be destroyed.
 * @note              Time Complexity: O(n)
******************************************************************************/
void SortedListDestroy(sorted_list_t *sorted_list)
{
	assert(sorted_list && "List isn't valid.");
	DLLDestroy(sorted_list->dll);
	free(sorted_list);
}

/******************************************************************************
 * @brief             Returns the number of nodes in the sorted list.
 * @param sorted_list Pointer to the sorted list.
 * @return            Number of nodes in the sorted list.
 * @note              Time Complexity: O(n)
******************************************************************************/
size_t SortedListCount(const sorted_list_t *sorted_list)
{
	assert(sorted_list && "List isn't valid.");
	return DLLCount(sorted_list->dll);
}

/******************************************************************************
 * @brief             Returns an iterator pointing to the start of the sorted list.
 * @param sorted_list Pointer to the sorted list.
 * @return            Iterator pointing to the start of the sorted list.
 * @note              Time Complexity: O(1)
******************************************************************************/
sorted_list_iter_t SortedListBegin(const sorted_list_t *sorted_list)
{
	sorted_list_iter_t begin = {NULL};
	assert(sorted_list && "List isn't valid.");
	begin.iterator = DLLBegin(sorted_list->dll);

	#ifndef NDEBUG
	begin.list = (sorted_list_t *)sorted_list;
	#endif

	return (begin);
}

/******************************************************************************
 * @brief             Returns an iterator pointing to the end of the sorted list.
 * @param sorted_list Pointer to the sorted list.
 * @return            Iterator pointing to the end of the sorted list.
 * @note              Time Complexity: O(1)
******************************************************************************/
sorted_list_iter_t SortedListEnd(const sorted_list_t *sorted_list)
{
	sorted_list_iter_t end = {NULL};
	assert(sorted_list && "List isn't valid.");
	end.iterator = DLLEnd(sorted_list->dll);

	#ifndef NDEBUG
	end.list = (sorted_list_t *)sorted_list;
	#endif

	return (end);
}

/******************************************************************************
 * @brief          Returns an iterator to the next data in the sorted list.
 * @param iterator Iterator.
 * @return         Next iterator.
 * @note           Time Complexity: O(1)
******************************************************************************/
sorted_list_iter_t SortedListNext(const sorted_list_iter_t iterator)
{
	assert(iterator.iterator && "Iterator isn't valid.");
	*(dll_iter_t *)&iterator.iterator = DLLNext(iterator.iterator);
	return (iterator);
}

/******************************************************************************
 * @brief          Returns an iterator to the previous data in the sorted list.
 * @param iterator Iterator.
 * @return         Previous iterator.
 * @note           Time Complexity: O(1)
******************************************************************************/
sorted_list_iter_t SortedListPrev(const sorted_list_iter_t iterator)
{
	assert(iterator.iterator && "Iterator isn't valid.");
	*(dll_iter_t *)&iterator.iterator = DLLPrev(iterator.iterator);
	return (iterator);
}

/******************************************************************************
 * @brief             Checks if the sorted list is empty.
 * @param sorted_list Pointer to the sorted list.
 * @return            Non-zero value if empty, 0 if not empty.
 * @note              Time Complexity: O(1)
******************************************************************************/
int SortedListIsEmpty(const sorted_list_t *sorted_list)
{
	assert(sorted_list && "List isn't valid.");
	return DLLIsEmpty(sorted_list->dll);
}

/******************************************************************************
 * @brief       Checks if two iterators in the sorted list are equal.
 * @param iter1 Iterator.
 * @param iter2 Iterator.
 * @return      Non-zero value if equal, 0 if not equal.
 * @note        Time Complexity: O(1)
******************************************************************************/
int SortedListIsEqual(const sorted_list_iter_t iter1, const sorted_list_iter_t iter2)
{
	assert(iter1.iterator && "Iterator isn't valid.");
	assert(iter2.iterator && "Iterator isn't valid.");
	return (iter1.iterator == iter2.iterator);
}

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
sorted_list_iter_t SortedListInsert(sorted_list_t *sorted_list, void *data)
{
	sorted_list_iter_t start = {NULL};
	sorted_list_iter_t end = {NULL};

	assert(sorted_list && "List isn't valid.");
	end = SortedListEnd(sorted_list);
	start = SortedListBegin(sorted_list);
	while(start.iterator != end.iterator && 0 > (sorted_list->cmp(SortedListGetData(start), data)))
	{
		start = SortedListNext(start);
	}

	start.iterator = DLLInsertBefore(start.iterator, data);
	#ifndef NDEBUG
	start.list = sorted_list;
	#endif

	return (start);
}

/******************************************************************************
 * @brief          Removes the data that the iterator points to and returns 
 *                 the next iterator.
 * 
 * @param iterator Iterator pointing to the data to be removed.
 * @return         Iterator pointing to the next data after removal.
 * @note           Time Complexity: O(1)
******************************************************************************/
sorted_list_iter_t SortedListRemove(sorted_list_iter_t iterator)
{
	assert(iterator.iterator && "Iterator isn't valid.");
	iterator.iterator = DLLRemove(iterator.iterator);
	return (iterator);
}

/******************************************************************************
 * @brief      Removes and returns the data at the end of the sorted list.
 * @param list Pointer to the sorted list.
 * @return     Pointer to the removed data.
 * @note       Time Complexity: O(1)
******************************************************************************/
void *SortedListPopBack(sorted_list_t *sorted_list)
{
	assert(sorted_list && "List isn't valid.");
	return (DLLPopBack(sorted_list->dll));
}

/******************************************************************************
 * @brief      Removes and returns the data at the start of the sorted list.
 * @param list Pointer to the sorted list.
 * @return     Pointer to the removed data.
 * @note       Time Complexity: O(1)
******************************************************************************/
void *SortedListPopFront(sorted_list_t *sorted_list)
{
	assert(sorted_list && "List isn't valid.");
	return (DLLPopFront(sorted_list->dll));
}

/******************************************************************************
 * @brief          Gets the data at the position pointed to by the iterator.
 * @param iterator Iterator pointing to the data.
 * @return         Pointer to the data at the specified position.
 * @note           Time Complexity: O(1)
******************************************************************************/
void *SortedListGetData(const sorted_list_iter_t iterator)
{
	assert(iterator.iterator && "Iterator isn't valid.");
	return (DLLGetData(iterator.iterator));
}

/******************************************************************************
 * @brief        Merges two sorted lists together.
 * @param dest   Pointer to the destination sorted list.
 * @param source Pointer to the source sorted list.
 *               Both the destination and source lists must use the same sorting 
 *               function.
 *
 * @note         Time Complexity: O(n)
******************************************************************************/
void SortedListMerge(sorted_list_t *dest, sorted_list_t *source)
{
	dll_iter_t to = NULL;
	dll_iter_t from = NULL;
	dll_iter_t runner = NULL;

	assert(dest && "List isn't valid.");
	assert(source && "List isn't valid.");

	to = DLLBegin(source->dll);
	runner = DLLBegin(dest->dll);
	from = DLLBegin(source->dll);

	while(from != DLLEnd(source->dll))
	{
		while(runner != DLLEnd(dest->dll) && 0 >= (dest->cmp(DLLGetData(runner), DLLGetData(from))))
		{
			runner = DLLNext(runner);
		}

		if(runner == DLLEnd(dest->dll))
		{
			to = DLLEnd(source->dll);
		}
		else
		{
			while(to != DLLEnd(source->dll) && 0 > (dest->cmp(DLLGetData(to), DLLGetData(runner))))
			{
				to = DLLNext(to);
			}
		}

		DLLSplice(runner, from, to);
		from = DLLBegin(source->dll);
	}
}

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
sorted_list_iter_t SortedListFind(const sorted_list_t *list, const sorted_list_iter_t from, const sorted_list_iter_t to, void *parameter)
{
	sorted_list_iter_t target = from;

	assert(from.iterator && "Iterator from isn't valid.");
	assert(to.iterator && "Iterator from isn't valid.");
	assert(list && "List isn't valid.");

	#ifndef NDEBUG
	assert(from.list == to.list && "Iterators not belong to the same list.");
	#endif

	for(; target.iterator !=  to.iterator && 
	0 < list->cmp(SortedListGetData(target), parameter);
	target = SortedListNext(target));

	return (target);
}

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
sorted_list_iter_t SortedListFindIf(const sorted_list_iter_t from, const sorted_list_iter_t to, sorted_list_ismatch_func_t match, void *parameter)
{
	sorted_list_iter_t runner = from;

	assert(from.iterator && "From iterator isn't valid.");
	assert(to.iterator && "To iterator isn't valid.");

	#ifndef NDEBUG
	assert(from.list == to.list && "Iterators not belong to the same list.");
	#endif

	for(; runner.iterator !=  to.iterator; runner = SortedListNext(runner))
	{
		if(match(SortedListGetData(runner), parameter))
		{
			return (runner);
		}
	}

	return (to);
}

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
int SortedListForEach(sorted_list_iter_t from, const sorted_list_iter_t to, sorted_list_action_func_t action, void *parameter)
{
	assert(from.iterator && "Iterator from isn't valid.");
	assert(to.iterator && "Iterator from isn't valid.");

	#ifndef NDEBUG
	if(from.list != to.list)
	{
		return (-1);
	}
	#endif

	return (DLLForEach(from.iterator, to.iterator, action, parameter));
}
/*****************************************************************************/