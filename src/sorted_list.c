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
/*****************************************************************************/
sorted_list_t *SortedListCreate(sorted_list_compare_func_t compare)
{
	sorted_list_t *sorted_list = (sorted_list_t *)malloc(sizeof(sorted_list_t));
	if(NULL == sorted_list)
	{
		return NULL;
	}

	sorted_list -> dll = DLLCreate();
	if(NULL == sorted_list -> dll)
	{
		free(sorted_list);
		return NULL;
	}

	sorted_list -> cmp = compare;

	return sorted_list;
}
/*****************************************************************************/
void SortedListDestroy(sorted_list_t *sorted_list)
{
	assert(sorted_list && "List isn't valid.");

	DLLDestroy(sorted_list -> dll);
	free(sorted_list);
}
/*****************************************************************************/
size_t SortedListCount(const sorted_list_t *sorted_list)
{
	assert(sorted_list && "List isn't valid.");
	return DLLCount(sorted_list -> dll);
}
/*****************************************************************************/
sorted_list_iter_t SortedListBegin(const sorted_list_t *sorted_list)
{
	sorted_list_iter_t begin = {NULL};
	assert(sorted_list && "List isn't valid.");

	begin.iterator = DLLBegin(sorted_list -> dll);

	#ifndef NDEBUG
	begin.list = (sorted_list_t *)sorted_list;
	#endif

	return begin;
}
/*****************************************************************************/
sorted_list_iter_t SortedListEnd(const sorted_list_t *sorted_list)
{
	sorted_list_iter_t end = {NULL};
	assert(sorted_list && "List isn't valid.");

	end.iterator = DLLEnd(sorted_list -> dll);

	#ifndef NDEBUG
	end.list = (sorted_list_t *)sorted_list;
	#endif

	return end;
}
/*****************************************************************************/
sorted_list_iter_t SortedListNext(const sorted_list_iter_t iterator)
{
	assert(iterator.iterator && "Iterator isn't valid.");
	*(dll_iter_t *)&iterator.iterator = DLLNext(iterator.iterator);

	return iterator;
}
/*****************************************************************************/
sorted_list_iter_t SortedListPrev(const sorted_list_iter_t iterator)
{
	assert(iterator.iterator && "Iterator isn't valid.");
	*(dll_iter_t *)&iterator.iterator = DLLPrev(iterator.iterator);

	return iterator;

}
/*****************************************************************************/
int SortedListIsEmpty(const sorted_list_t *sorted_list)
{
	assert(sorted_list && "List isn't valid.");
	return DLLIsEmpty(sorted_list -> dll);
}
/*****************************************************************************/
int SortedListIsEqual(const sorted_list_iter_t iter1, const sorted_list_iter_t iter2)
{
	assert(iter1.iterator && "Iterator isn't valid.");
	assert(iter2.iterator && "Iterator isn't valid.");

	return iter1.iterator == iter2.iterator;
}
/*****************************************************************************/
sorted_list_iter_t SortedListInsert(sorted_list_t *sorted_list, void *data)
{
	sorted_list_iter_t start = {NULL};
	sorted_list_iter_t end = {NULL};

	assert(sorted_list && "List isn't valid.");

	end = SortedListEnd(sorted_list);
	start = SortedListBegin(sorted_list);

	while(start.iterator != end.iterator &&
	 0 > (sorted_list -> cmp(SortedListGetData(start), data)))
	{
		start = SortedListNext(start);
	}

	start.iterator = DLLInsertBefore(start.iterator, data);
	#ifndef NDEBUG
	start.list = sorted_list;
	#endif

	return start;
}
/*****************************************************************************/
sorted_list_iter_t SortedListRemove(sorted_list_iter_t iterator)
{
	assert(iterator.iterator && "Iterator isn't valid.");
	iterator.iterator = DLLRemove(iterator.iterator);

	return iterator;
}
/*****************************************************************************/
void *SortedListPopBack(sorted_list_t *sorted_list)
{
	assert(sorted_list && "List isn't valid.");
	return DLLPopBack(sorted_list -> dll);
}
/*****************************************************************************/
void *SortedListPopFront(sorted_list_t *sorted_list)
{
	assert(sorted_list && "List isn't valid.");
	return DLLPopFront(sorted_list -> dll);
}
/*****************************************************************************/
void *SortedListGetData(const sorted_list_iter_t iterator)
{
	assert(iterator.iterator && "Iterator isn't valid.");
	return DLLGetData(iterator.iterator);
}
/*****************************************************************************/
void SortedListMerge(sorted_list_t *dest, sorted_list_t *source)
{
	dll_iter_t runner = NULL;
	dll_iter_t from = NULL;
	dll_iter_t to = NULL;

	assert(dest && "List isn't valid.");
	assert(source && "List isn't valid.");

	runner = DLLBegin(dest -> dll);
	from = DLLBegin(source -> dll);
	to = DLLBegin(source -> dll);

	while(from != DLLEnd(source -> dll))
	{
		while(runner != DLLEnd(dest -> dll) &&
		 0 >= (dest -> cmp(DLLGetData(runner), DLLGetData(from))))
		{
			runner = DLLNext(runner);
		}

		if(runner == DLLEnd(dest -> dll))
		{
			to = DLLEnd(source -> dll);
		}
		else
		{
			while(to != DLLEnd(source -> dll) &&
			 0 > (dest -> cmp(DLLGetData(to), DLLGetData(runner))))
			{
				to = DLLNext(to);
			}
		}

		DLLSplice(runner, from, to);
		from = DLLBegin(source -> dll);
	}
}
/*****************************************************************************/
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
	0 < list -> cmp(SortedListGetData(target), parameter);
	target = SortedListNext(target));

	return target;
}
/*****************************************************************************/
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
			return runner;
		}
	}

	return to;
}
/*****************************************************************************/
int SortedListForEach(sorted_list_iter_t from, const sorted_list_iter_t to, sorted_list_action_func_t action, void *parameter)
{
	assert(from.iterator && "Iterator from isn't valid.");
	assert(to.iterator && "Iterator from isn't valid.");

	#ifndef NDEBUG
	if(from.list != to.list)
	{
		return -1;
	}
	#endif

	return DLLForEach(from.iterator, to.iterator, action, parameter);
}
/*****************************************************************************/
