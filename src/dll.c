/******************************************************************************
 * @writer:      Tal Aharon
 * @date:        15.03.2023
 
 * @description: This implementation of the doubly linked list in C provides basic 
 *               doubly linked list operations such as insertion, removal, iteration, 
 *               and more. The list can hold various data types, and it supports 
 *               custom actions and comparisons.
 * 
******************************************************************************/
#include <stdlib.h> /* malloc, free  */
#include <assert.h> /* assert    :)  */

#include "dll.h"    /* Internal use */
/*****************************************************************************/
typedef struct dll_node
{
	void *data;
	struct dll_node *next;
	struct dll_node *prev;

} dll_node_t;

struct dll
{
	dll_node_t *head;
	dll_node_t *tail;
};

int Action(void *data, void *param);
static void DLLSwap(dll_iter_t iter1, dll_iter_t iter2);
/******************************************************************************
 * @brief     Creates a new doubly linked list.
 * @return    Pointer to the created list, or NULL if creation fails.
******************************************************************************/
dll_t *DLLCreate(void)
{
	dll_t *dll = (dll_t *)malloc(sizeof(dll_t));

	if(NULL == dll)
	{
		return (NULL);
	}

	/* Creating the first node to be a dummy */
	dll->head = (dll_node_t *)malloc(sizeof(dll_node_t));
	dll->tail = dll->head;

	if(NULL == dll->head)
	{
		free(dll);
		return (NULL);
	}

    /* Initializing values to NULL to mark the end of dll */
	dll->head->next = NULL;
	dll->head->prev = NULL;
	dll->head->data = &(dll->tail);

	return (dll);
}

/******************************************************************************
 * @brief     Destroys a doubly linked list and its nodes.
 * @param dll Pointer to the list to be destroyed.
******************************************************************************/
void DLLDestroy(dll_t *dll)
{
	/* Temporary nodes to point to dll nodes and free one by one */
	dll_node_t *next = NULL;

	assert(dll && "dll isn't valid. Can not be freed.");

	while(dll->head)
	{
		next = dll->head->next;
		free(dll->head);
		dll->head = next;
	}

	free(dll);
	dll = NULL;
}

/******************************************************************************
 * @brief          Inserts a new node with data after the given iterator.
 * @param iterator Iterator to the position after which the new node should be inserted.
 * @param data     Pointer to the data to be inserted.
 * @return         Iterator pointing to the inserted node, or end of the list if insertion fails.
******************************************************************************/
dll_iter_t DLLInsertAfter(dll_iter_t iterator, void *data)
{
	assert(iterator && "Iterator isn't valid.");
	return (DLLInsertBefore(iterator->next, data));
}

/******************************************************************************
 * @brief          Inserts a new node with data before the given iterator.
 * @param iterator Iterator to the position before which the new node should be inserted.
 * @param data     Pointer to the data to be inserted.
 * @return         Iterator pointing to the inserted node, or end of the list if insertion fails.
******************************************************************************/
dll_iter_t DLLInsertBefore(dll_iter_t iterator, void *data)
{
	dll_node_t *new_node = (dll_node_t *)malloc(sizeof(dll_node_t));
	assert(iterator && "Iterator isn't valid.");

	if(NULL == new_node)
	{
		while(iterator->next)
		{
			iterator = iterator->next;
		}

		return (iterator);
	}

	if(NULL == iterator->next)
	{
		*(dll_node_t **)(iterator->data) = new_node;
	}
	else
	{
		iterator->next->prev = new_node;
	}
	

	new_node->data = iterator->data;
	iterator->data = data;
	new_node->prev = iterator;
	new_node->next = iterator->next;
	iterator->next = new_node;

	return (iterator);
}

/******************************************************************************
 * @brief          Removes the node pointed to by the given iterator.
 * @param iterator Iterator pointing to the node to be removed.
 * @return         Iterator pointing to the next node after removal. Undefined behavior on end-of-list.
******************************************************************************/
dll_iter_t DLLRemove(dll_iter_t iterator)
{
	dll_iter_t tmp = iterator->next;
	assert(iterator && "Iterator isn't valid.");

	iterator->data = tmp->data;
	iterator->next = tmp->next;
	if(NULL == iterator->next)
	{
		*((dll_node_t **)tmp->data) = iterator;
	}
	else
	{
		iterator->next->prev = iterator;
	}

	free(tmp);
	return (iterator);
}

/******************************************************************************
 * @brief      Pushes data to the back of the doubly linked list.
 * @param dll  Pointer to the list.
 * @param data Pointer to the data to be pushed.
 * @return     Iterator pointing to the pushed node, or end of the list if push fails.
******************************************************************************/
dll_iter_t DLLPushBack(dll_t *dll, void *data)
{
	assert(dll && "dll isn't valid.");
	return (DLLInsertBefore(dll->tail, data)); 
}

/******************************************************************************
 * @brief      Pushes data to the front of the doubly linked list.
 * @param dll  Pointer to the list.
 * @param data Pointer to the data to be pushed.
 * @return     Iterator pointing to the pushed node, or end of the list if push fails.
******************************************************************************/
dll_iter_t DLLPushFront(dll_t *dll, void *data)
{
	assert(dll && "dll isn't valid.");
	return (DLLInsertBefore(dll->head, data));
}

/******************************************************************************
 * @brief     Pops data from the back of the doubly linked list.
 * @param dll Pointer to the list.
 * @return    Pointer to the popped data.
******************************************************************************/
void *DLLPopBack(dll_t *dll)
{
	void *data = dll->tail->prev->data;
	assert(dll && "dll isn't valid.");

	DLLRemove(dll->tail->prev);
	return (data);
}

/******************************************************************************
 * @brief     Pops data from the front of the doubly linked list.
 * @param dll Pointer to the list.
 * @return    Pointer to the popped data.
******************************************************************************/
void *DLLPopFront(dll_t *dll)
{
	void *data = dll->head->data;
	assert(dll && "dll isn't valid.");

	DLLRemove(dll->head);
	return (data);
}

/******************************************************************************
 * @brief          Sets data at a specific node pointed by the given iterator.
 * @param iterator Iterator pointing to the node.
 * @param data     Pointer to the new data to be set.
******************************************************************************/
void DLLSetData(dll_iter_t iterator, void *data)
{
	assert(iterator && "Iterator isn't valid.");
	iterator->data = data;
}

/******************************************************************************
 * @brief          Gets data from a specific node pointed by the given iterator.
 * @param position Iterator pointing to the node.
 * @return         Pointer to the data in the node.
******************************************************************************/
void *DLLGetData(const dll_iter_t position)
{
	assert(position && "Iterator isn't valid.");
	return (position->data);
}

/******************************************************************************
 * @brief     Returns an iterator pointing to the start of the list.
 * @param dll Pointer to the list.
 * @return    Iterator pointing to the start of the list.
******************************************************************************/
dll_iter_t DLLBegin(const dll_t *dll)
{
	assert(dll && "dll isn't valid.");
	return (dll->head);
}

/******************************************************************************
 * @brief     Returns an iterator pointing to the end of the list.
 * @param dll Pointer to the list.
 * @return    Iterator pointing to the end of the list.
******************************************************************************/
dll_iter_t DLLEnd(const dll_t *dll)
{
	assert(dll && "dll isn't valid.");
	return (dll->tail);
}

/******************************************************************************
 * @brief          Returns the next iterator.
 * @param iterator Iterator.
 * @return         Next iterator.
******************************************************************************/
dll_iter_t DLLNext(const dll_iter_t iterator)
{
	assert(iterator && "Iterator isn't valid.");
	return (iterator->next);
}

/******************************************************************************
 * @brief          Returns the previous iterator.
 * @param iterator Iterator.
 * @return         Previous iterator.
******************************************************************************/
dll_iter_t DLLPrev(const dll_iter_t iterator)
{
	assert(iterator && "Iterator isn't valid.");
	return (iterator->prev);
}

/******************************************************************************
 * @brief     Checks if the doubly linked list is empty.
 * @param dll Pointer to the list.
 * @return    1 if empty, 0 if not.
******************************************************************************/
int DLLIsEmpty(const dll_t *dll)
{
	assert(dll && "dll isn't valid.");
	return (DLLBegin(dll) == DLLEnd(dll));
}

/******************************************************************************
 * @brief       Checks if two iterators are equal.
 * @param iter1 Iterator.
 * @param iter2 Iterator.
 * @return      1 if equal, 0 if not.
******************************************************************************/
int DLLIterIsEqual(const dll_iter_t iter1, const dll_iter_t iter2)
{
	assert(iter1 && "First iterator isn't valid.");
	assert(iter2 && "Second iterator isn't valid.");
	return (iter1 == iter2);
}

/******************************************************************************
 * @brief     Counts the number of nodes in the list.
 * @param dll Pointer to the list.
 * @return    Number of nodes in the list.
******************************************************************************/
size_t DLLCount(const dll_t *dll)
{
	size_t count = 0;
	assert(dll && "dll isn't valid.");
	DLLForEach(dll->head, dll->tail, Action, &count);
	return (count);
}

/******************************************************************************
 * @brief       Iterates through the list and performs an action on each node's data.
 * @param from  Iterator pointing to the start of the range.
 * @param to    Iterator pointing to the end of the range (not included).
 * @param act   Action function to be performed on each data element.
 * @param param Parameter to be passed to the action function.
 * @return      0 on success, or the status returned by the action function.
******************************************************************************/
int DLLForEach(dll_iter_t from, const dll_iter_t to, dll_act_func_t act, void *param)
{
	int status = 0;
	assert(from && "From iterator isn't valid.");
	assert(to && "To iterator isn't valid.");

	while(from != to)
	{
		if((status = act(&from->data, param)))
		{
			return (status);
		}
		from = from->next;
	}

	return (0);
}

/******************************************************************************
 * @brief             Splices nodes from one list into another at a specified position.
 * @param dest        Iterator pointing to the destination position.
 * @param source_from Iterator pointing to the start of the source range.
 * @param source_to   Iterator pointing to the end of the source range (not included).
******************************************************************************/
void DLLSplice(dll_iter_t dest, dll_iter_t source_from, dll_iter_t source_to)
{
	void *tmp1 = source_from->data;
	dll_iter_t tmp_node = source_to->next;

	assert(dest && "Destination iterator isn't valid.");
	assert(source_from && "From iterator isn't valid.");
	assert(source_to && "To iterator isn't valid.");

	source_from->data = source_to->data;
	source_to->data = dest->data;
	dest->data = tmp1;

	source_to->next = dest->next;
	dest->next = source_from->next;
	source_from->next = tmp_node;
	dest->next->prev = dest;

	/* Setting dummy node again */
	if(NULL == source_from->next)
	{
		*(dll_node_t **)(source_from->data) = source_from;
	}
	else
	{
		source_from->next->prev = source_from;
	}

	if(NULL == source_to->next)
	{
		*(dll_node_t **)(source_to->data) = source_to;
	}
	else
	{
		source_to->next->prev = source_to;
	}
}

/******************************************************************************
 * @brief       Finds the first occurrence of an iterator pointing to a node with data
 *              that satisfies a comparison function.
 * @param from  Starting iterator.
 * @param to    Iterator pointing to the end of the range (not included).
 * @param cmp   Comparison function.
 * @param param Parameter to be passed to the comparison function.
 * @return Iterator pointing to the found node or the end iterator if not found.
******************************************************************************/
dll_iter_t DLLFind(const dll_iter_t from, const dll_iter_t to, dll_cmp_func_t cmp, void *param)
{
	dll_iter_t runner = from;

	assert(from && "From iterator isn't valid.");
	assert(to && "To iterator isn't valid.");

	for(; runner !=  to; runner = runner->next)
	{
		if(!cmp(runner->data, param))
		{
			return (runner);
		}
	}

	return (to);
}

/******************************************************************************
 * @brief       Finds all occurrences of iterators pointing to nodes with data that satisfies
 *              a comparison function and appends them to the destination list.
 *
 * @param from  Starting iterator.
 * @param to    Iterator pointing to the end of the range (not included).
 * @param cmp   Comparison function.
 * @param param Parameter to be passed to the comparison function.
 * @param dest  Destination list.
 * @return      The number of iterators found and appended, or -1 on failure.
******************************************************************************/
int DLLMultiFind(const dll_iter_t from, const dll_iter_t to, dll_cmp_func_t cmp, void *param, dll_t *dest)
{
	int status = 0;
	dll_iter_t found = from;
	assert(dest && "Destination isn't valid.");
	assert(from && "From iterator isn't valid.");
	assert(to && "To iterator isn't valid.");

	for(; found !=  to; found = found->next)
	{
		found = DLLFind(found, to, cmp, param);

		if(to != found)
		{
			if(NULL == DLLPushBack(dest, found)->next)
			{
				return (-1);
			}

			status++;
		}
	}

	return (status);
}

/******************************************************************************
 * @brief       Custom action function for DLLForEach. Increments a size_t parameter.
 * @param data  Pointer to data.
 * @param param Pointer to a size_t parameter to be incremented.
 * @return      Always returns 0.
******************************************************************************/
int Action(void *data, void *param)
{
	(void) data;
	++(*(size_t *)param);
	return (0);
}

/******************************************************************************
 * @brief       Arranges the elements in the list around a pivot value.
 * @param dll   Pointer to the list.
 * @param pivot Pointer to the pivot value.
******************************************************************************/
void DLLArrange(dll_t *dll, void *pivot)
{
    dll_iter_t left = DLLBegin(dll);
    dll_iter_t right = DLLPrev(DLLEnd(dll));
    int piv = *(int *)pivot;

    while (left != right && left != DLLNext(right))
    {
        while (left != right && *(int *)left->data < piv)
        {
            left = DLLNext(left);
        }

        while (left != right && *(int *)right->data > piv)
        {
            right = DLLPrev(right);
        }

        DLLSwap(left, right);
    }
}

/******************************************************************************
 * @brief       Swaps nodes in a doubly linked list.
 * @param iter1 iterator.
 * @param iter2 iterator.
 * Complexity   Time complexity: O(1), Space complexity: O(1).
******************************************************************************/
static void DLLSwap(dll_iter_t iter1, dll_iter_t iter2)
{
    void *tempData = NULL;
    if(DLLIterIsEqual(iter1, iter2))
	{
        return;
	}

    tempData = iter1->data;
    iter1->data = iter2->data;
    iter2->data = tempData;
}
/*****************************************************************************/