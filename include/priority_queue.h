/******************************************************************************
 * @writer:      Tal Aharon
 * @date:        30.03.2023
 
 * @description: This header file defines the interface for a priority queue
 * data structure. A priority queue is a collection of elements sorted by their 
 * priority, where elements with higher priority are dequeued before elements 
 * with lower priority. Users can define their own comparison function to determine 
 * the order of elements based on their priorities.
 *
 * The priority queue provides functions for creating, manipulating, and querying 
 * the queue. It allows for efficient enqueue and dequeue operations, as well as 
 * functions to check if the queue is empty, retrieve the element with the highest 
 * priority, and more.
 *
 * Users of this header should provide their own comparison function to specify 
 * the priority order of elements.
 *
 * Detailed function descriptions and usage guidelines can be found in the comments within this header file.
 *
******************************************************************************/
#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include <stddef.h> /*size_t, NULL */

typedef struct priority_queue priority_queue_t;

/******************************************************************************
 * @typedef Comparison function type for prioritizing elements in the queue. This 
 * function type defines the signature of a comparison function that determines 
 * the priority order of elements in the priority queue. It takes two pointers 
 * to data elements, 'data' and 'new_data', and returns an integer indicating the 
 * comparison result as follows:
 * 
 * - Positive: 'new_data' has higher priority than 'data' (dequeued before).
 * - Negative: 'new_data' has lower priority than 'data' (dequeued after).
 * - Zero: 'data' and 'new_data' have the same priority (new_data dequeued after data).
 *
 * @param data     Pointer to the existing data element for comparison.
 * @param new_data Pointer to the new data element to compare.
 * @return         Integer indicating the comparison result.
******************************************************************************/
typedef int (*priority_queue_compare_func_t) (void *data, void *new_data);

/******************************************************************************
 * @typedef Matching function type for erasing elements in the queue.
 * This function type defines the signature of a matching function used to
 * determine whether an element in the priority queue matches certain criteria.
 * The function takes two pointers to data elements, 'data' and 'new_data',
 * and should return a non-zero value if 'data' matches the criteria specified
 * by 'parameter'.
 *
 * @param data      Pointer to the data element for matching.
 * @param new_data  Pointer to the new data element to be matched.
 * @return          Non-zero if 'data' matches the criteria; otherwise, 0.
******************************************************************************/
typedef int (*priority_queue_ismatch_func_t) (void *data, void *new_data);

/******************************************************************************
 * @brief Creates a new priority queue.This function creates a new priority queue 
 * and returns a pointer to it. The comparison function passed as an argument will 
 * be used to determine the priority order of elements in the queue.
 * 
 * @param compare Comparison function for element priority.
 * @return        Pointer to the newly created priority queue, or NULL on failure.
******************************************************************************/
priority_queue_t *PriorityQueueCreate(priority_queue_compare_func_t compare);

/******************************************************************************
 * @brief Destroys a priority queue. This function deallocates the memory used by 
 * the given priority queue and all its elements. After calling this function, 
 * the priority queue pointer should not be used.
 *
 * @param queue Pointer to the priority queue to destroy.
******************************************************************************/
void PriorityQueueDestroy(priority_queue_t *queue);

/******************************************************************************
 * @brief Adds an element to the priority queue. This function inserts the specified 
 * data element into the priority queue in its appropriate position based on the 
 * priority determined by the comparison function. The data will be enqueued in 
 * such a way that elements with higher priority are dequeued first.
 *
 * @param queue Pointer to the priority queue.
 * @param data  Pointer to the data element to enqueue.
 * @return      0 on success, or a non-zero value on failure.
******************************************************************************/
int PriorityQueueEnqueue(priority_queue_t *queue, void *data);

/******************************************************************************
 * @brief Removes and returns the highest-priority element from the queue. This 
 * function dequeues and returns the element with the highest priority from the 
 * priority queue. The element is removed from the queue.
 *
 * @param queue Pointer to the priority queue.
 * @return      Pointer to the data of the dequeued element, or NULL if the queue is empty.
******************************************************************************/
void *PriorityQueueDequeue(priority_queue_t *queue);

/******************************************************************************
 * @brief Retrieves the data of the highest-priority element without removing it. 
 * This function returns the data of the element at the head of the priority queue, 
 * which has the highest priority. The element remains in the queue.
 *
 * @param queue Pointer to the priority queue.
 * @return      Pointer to the data of the highest-priority element, or NULL if 
 *              the queue is empty.
******************************************************************************/
void *PriorityQueuePeek(const priority_queue_t *queue);

/******************************************************************************
 * @brief Checks if the priority queue is empty. This function determines whether 
 * the priority queue is empty or not.
 *
 * @param queue Pointer to the priority queue.
 * @return      1 if the queue is empty, 0 if it is not.
******************************************************************************/
int PriorityQueueIsEmpty(const priority_queue_t *queue);

/******************************************************************************
 * @brief Returns the number of elements in the priority queue. This function 
 * returns the current size (number of elements) in the priority queue.
 * 
 * @param queue Pointer to the priority queue.
 * @return      The number of elements in the queue.
******************************************************************************/
size_t PriorityQueueSize(const priority_queue_t *queue);

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
 * @return Pointer to the data of the removed element, or the queue itself if no match is found.
******************************************************************************/
void *PriorityQueueErase(priority_queue_t *queue, priority_queue_ismatch_func_t ismatch, void *parameter);

/******************************************************************************
 * @brief Clears all elements from the priority queue. This function removes 
 * all elements from the priority queue, leaving it empty.
 *
 * @param queue Pointer to the priority queue.
******************************************************************************/
void PriorityQueueClear(priority_queue_t *queue);

#endif /* __PRIORITY_QUEUE_H__ */
