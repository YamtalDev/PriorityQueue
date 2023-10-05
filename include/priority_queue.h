#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include <stddef.h> /*size_t, NULL */

typedef struct priority_queue priority_queue_t;

/* The function we will use to sort the queue. returns an integer indicating the result 
   of the comparison, as follows: positive if "new_data" has higher priority than "data" 
   (and will be dequeued before), negative if "new_data" has lower priority than "data" 
   (and will be dequeued after), or 0, if the data and new_data have the same priority, 
   (and then new_data will be dequeued after data) */

typedef int (*priority_queue_compare_func_t) (void *data, void *new_data);

/* Used in Erase. Should return non-zero if "data" match the "parameter" */
typedef int (*priority_queue_ismatch_func_t) (void *data, void *new_data);

/*****************************************************************************/

/* Complexity - time Complexity O(1), space complexity O(1).
   Creation of a Queue, if creation fails it will return NULL */

priority_queue_t *PriorityQueueCreate(priority_queue_compare_func_t compare);

/*****************************************************************************/

/* Complexity - time Complexity O(n), space complexity O(1).
   Destroy of the Queue. */

void PriorityQueueDestroy(priority_queue_t *queue);

/*****************************************************************************/

/* Complexity - time Complexity O(n), space complexity O(1).
   Adds element to the right position in the queue. return 0 on success. */

int PriorityQueueEnqueue(priority_queue_t *queue, void *data);

/*****************************************************************************/

/* Complexity - time Complexity O(1), space complexity O(1).
   Removes element from head of queue */

void *PriorityQueueDequeue(priority_queue_t *queue);

/*****************************************************************************/

/* Complexity - time Complexity O(1), space complexity O(1).
   Return the data from the head of queue */

void *PriorityQueuePeek(const priority_queue_t *queue);

/*****************************************************************************/

/* Complexity - time Complexity O(1), space complexity O(1).
   Return 1 if empty and 0 if not */

int PriorityQueueIsEmpty(const priority_queue_t *queue);

/*****************************************************************************/

/* Complexity - time Complexity O(n), space complexity O(1).
   Returns the size of queue */

size_t PriorityQueueSize(const priority_queue_t *queue);

/*****************************************************************************/

/* Complexity - time Complexity O(n), space complexity O(1).
   Returns the data of removed element, or the queue itself, in case there is no match */
   
void *PriorityQueueErase(priority_queue_t *queue, priority_queue_ismatch_func_t ismatch, void *parameter);

/*****************************************************************************/

/* Complexity - time Complexity O(n), space complexity O(1).
   Returns empty queue */
   
void PriorityQueueClear(priority_queue_t *queue);

/*****************************************************************************/

#endif /* __PRIORITY_QUEUE_H__ */
