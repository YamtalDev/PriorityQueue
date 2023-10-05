/******************************************************************************
 * @writer:      Tal Aharon
 * @date:        30.03.2023
 
 * @description: 
 * 
******************************************************************************/
#include <stdlib.h>           /* malloc, free */
#include <assert.h>           /* assert       */

#include "priority_queue.h"   /* Internal use */
#include "sorted_list.h"      /* Internal use */

struct priority_queue
{
	sorted_list_t *sorted_list;

} priority_queue;

/*****************************************************************************/
priority_queue_t *PriorityQueueCreate(priority_queue_compare_func_t compare)
{
	priority_queue_t *priority_queue = (priority_queue_t *)
	malloc(sizeof(priority_queue_t *));
	if(NULL == priority_queue)
	{
		return NULL;
	}

	priority_queue -> sorted_list = SortedListCreate(compare);
	if(NULL == priority_queue -> sorted_list)
	{
		free(priority_queue);
		priority_queue = NULL;
		return NULL;
	}

	return priority_queue;
}
/*****************************************************************************/ 
void PriorityQueueDestroy(priority_queue_t *queue)
{
	assert(queue && "Queue is not valid");
	SortedListDestroy(queue -> sorted_list);
	free(queue);
	queue = NULL;
}
/*****************************************************************************/ 
int PriorityQueueEnqueue(priority_queue_t *queue, void *data)
{
	sorted_list_iter_t insert = {0};
	assert(queue && "Queue is not valid");
	insert = SortedListInsert(queue -> sorted_list, data);
	return (SortedListIsEqual(SortedListEnd(queue -> sorted_list), insert));
}
/*****************************************************************************/ 
void *PriorityQueueDequeue(priority_queue_t *queue)
{
	assert(queue && "Queue is not valid");
	return SortedListPopFront(queue -> sorted_list);
}
/*****************************************************************************/ 
void *PriorityQueuePeek(const priority_queue_t *queue)
{
	assert(queue && "Queue is not valid");
	return SortedListGetData(SortedListBegin(queue -> sorted_list));
}
/*****************************************************************************/ 
int PriorityQueueIsEmpty(const priority_queue_t *queue)
{
	assert(queue && "Queue is not valid");
	return SortedListIsEmpty(queue -> sorted_list);
}
/*****************************************************************************/ 
size_t PriorityQueueSize(const priority_queue_t *queue)
{
	assert(queue && "Queue is not valid");
	return SortedListCount(queue -> sorted_list);
}
/*****************************************************************************/ 
void *PriorityQueueErase(priority_queue_t *queue, priority_queue_ismatch_func_t ismatch, void *parameter)
{
	void *data = NULL;
	sorted_list_iter_t result = {0};
	assert(queue && "Queue is not valid");

	result = SortedListFindIf(SortedListBegin(queue -> sorted_list),
	SortedListEnd(queue -> sorted_list), ismatch, parameter);
	if(SortedListIsEqual(result, SortedListEnd(queue -> sorted_list)))
	{
		return (void *)queue;
	}

	data = SortedListGetData(result);
	SortedListRemove(result);
	return data;
}
/*****************************************************************************/ 
void PriorityQueueClear(priority_queue_t *queue)
{
	assert(queue && "Queue is not valid");

	for(; !SortedListIsEmpty(queue -> sorted_list); SortedListPopFront(queue -> sorted_list));
	return;
}
/*****************************************************************************/ 
