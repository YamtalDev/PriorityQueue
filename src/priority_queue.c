/******************************************************************************
 * @writer:      Tal Aharon
 * @date:        30.03.2023
 * 
 * @description: Implementation of a Priority Queue based on a Sorted List. A 
 * Priority Queue is a data structure that allows efficient retrieval and removal 
 * of elements based on their priority. The priority is determined using a user-
 * defined comparison function.
 * 
******************************************************************************/
#include <assert.h>           /* assert       */
#include <stdlib.h>           /* malloc, free */

#include "sorted_list.h"      /* Internal API */
#include "priority_queue.h"   /* Internal API */
/*****************************************************************************/
struct priority_queue
{
	sorted_list_t *sorted_list;
} priority_queue;

/******************************************************************************
 * @brief Creates a new priority queue.This function creates a new priority queue 
 * and returns a pointer to it. The comparison function passed as an argument will 
 * be used to determine the priority order of elements in the queue.
 * 
 * @param compare Comparison function for element priority.
 * @return        Pointer to the newly created priority queue, or NULL on failure.
 * @note          complexity   Time: O(1), Space: O(1)
******************************************************************************/
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

/******************************************************************************
 * @brief Destroys a priority queue. This function deallocates the memory used by 
 * the given priority queue and all its elements. After calling this function, 
 * the priority queue pointer should not be used.
 *
 * @param queue Pointer to the priority queue to destroy.
 * @note        complexity   Time: O(n), Space: O(1)
******************************************************************************/
void PriorityQueueDestroy(priority_queue_t *queue)
{
	assert(queue && "Queue is not valid");
	SortedListDestroy(queue -> sorted_list);
	free(queue);
	queue = NULL;
}

/******************************************************************************
 * @brief Adds an element to the priority queue. This function inserts the specified 
 * data element into the priority queue in its appropriate position based on the 
 * priority determined by the comparison function. The data will be enqueued in 
 * such a way that elements with higher priority are dequeued first.
 *
 * @param queue Pointer to the priority queue.
 * @param data  Pointer to the data element to enqueue.
 * @return      0 on success, or a non-zero value on failure.
 * @note        complexity   Time: O(1), Space: O(1)
******************************************************************************/
int PriorityQueueEnqueue(priority_queue_t *queue, void *data)
{
	sorted_list_iter_t insert = {0};
	assert(queue && "Queue is not valid");
	insert = SortedListInsert(queue -> sorted_list, data);
	return (SortedListIsEqual(SortedListEnd(queue -> sorted_list), insert));
}

/******************************************************************************
 * @brief Removes and returns the highest-priority element from the queue. This 
 * function dequeues and returns the element with the highest priority from the 
 * priority queue. The element is removed from the queue.
 *
 * @param queue Pointer to the priority queue.
 * @return      Pointer to the data of the dequeued element, or NULL if the queue is empty.
 * @note        complexity   Time: O(1), Space: O(1)
******************************************************************************/
void *PriorityQueueDequeue(priority_queue_t *queue)
{
	assert(queue && "Queue is not valid");
	return SortedListPopFront(queue -> sorted_list);
}

/******************************************************************************
 * @brief Retrieves the data of the highest-priority element without removing it. 
 * This function returns the data of the element at the head of the priority queue, 
 * which has the highest priority. The element remains in the queue.
 *
 * @param queue Pointer to the priority queue.
 * @return      Pointer to the data of the highest-priority element, or NULL if 
 *              the queue is empty.
 * @note        complexity   Time: O(1), Space: O(1)
******************************************************************************/
void *PriorityQueuePeek(const priority_queue_t *queue)
{
	assert(queue && "Queue is not valid");
	return SortedListGetData(SortedListBegin(queue -> sorted_list));
}

/******************************************************************************
 * @brief Checks if the priority queue is empty. This function determines whether 
 * the priority queue is empty or not.
 *
 * @param queue Pointer to the priority queue.
 * @return      1 if the queue is empty, 0 if it is not.
 * @note        complexity   Time: O(1), Space: O(1)
******************************************************************************/
int PriorityQueueIsEmpty(const priority_queue_t *queue)
{
	assert(queue && "Queue is not valid");
	return SortedListIsEmpty(queue -> sorted_list);
}

/******************************************************************************
 * @brief Returns the number of elements in the priority queue. This function 
 * returns the current size (number of elements) in the priority queue.
 * 
 * @param queue Pointer to the priority queue.
 * @return      The number of elements in the queue.
 * @note        complexity   Time: O(n), Space: O(1)
******************************************************************************/
size_t PriorityQueueSize(const priority_queue_t *queue)
{
	assert(queue && "Queue is not valid");
	return SortedListCount(queue -> sorted_list);
}

/******************************************************************************
 * @brief Removes an element from the priority queue based on a matching function. 
 * This function searches for an element in the priority queue that matches the 
 * specified criteria provided by the `ismatch` function. If a match is found, 
 * the matched element is removed from the queue and returned. If no match is found, 
 * the queue remains unchanged.
 *
 * @param queue     Pointer to the priority queue.
 * @param ismatch   Matching function to determine if an element should be removed.
 * @param parameter User-defined parameter to pass to the ismatch function.
 * @return          Pointer to the data of the removed element, or the queue itself 
 *                  if no match is found.
 * @note            complexity   Time: O(n), Space: O(1)
******************************************************************************/
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

/******************************************************************************
 * @brief Clears all elements from the priority queue. This function removes 
 * all elements from the priority queue, leaving it empty.
 *
 * @param queue Pointer to the priority queue.
 * @note        complexity   Time: O(n), Space: O(1)
******************************************************************************/
void PriorityQueueClear(priority_queue_t *queue)
{
	assert(queue && "Queue is not valid");
	for(; !SortedListIsEmpty(queue -> sorted_list); SortedListPopFront(queue -> sorted_list));
	return;
}
/*****************************************************************************/