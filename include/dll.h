/******************************************************************************
 * @writer:      Tal Aharon
 * @date:        15.03.2023
 *
 * @description: This is the header for the doubly linked list implementation in C.
 *               It provides basic doubly linked list operations such as insertion,
 *               removal, iteration, and more. The list can hold various data types,
 *               and it supports custom actions and comparisons.
 ******************************************************************************/
#ifndef __DLL_H__
#define __DLL_H__


#include <stddef.h>   /* size_t, NULL */

typedef struct dll_node *dll_iter_t;

typedef struct dll dll_t;

typedef int (*dll_act_func_t) (void *data, void * param);
 
typedef int (*dll_cmp_func_t) (void *data, void *param);

/******************************************************************************
 * @brief     Creates a new doubly linked list.
 * @return    Pointer to the created list, or NULL if creation fails.
 * Complexity Time complexity: O(1), Space complexity: O(1).
******************************************************************************/
dll_t *DLLCreate(void);

/******************************************************************************
 * @brief     Destroys a doubly linked list and its nodes.
 * @param dll Pointer to the list to be destroyed.
 * Complexity Time complexity: O(n), Space complexity: O(1).
******************************************************************************/
void DLLDestroy(dll_t *dll);

/******************************************************************************
 * @brief          Inserts a new node with data after the given iterator.
 * @param iterator Iterator to the position after which the new node should be inserted.
 * @param data     Pointer to the data to be inserted.
 * @return         Iterator pointing to the inserted node, or end of the list if insertion fails.
 * Complexity      Time complexity: O(1), Space complexity: O(1).
******************************************************************************/
dll_iter_t DLLInsertAfter(dll_iter_t iterator, void *data);

/******************************************************************************
 * @brief          Inserts a new node with data before the given iterator.
 * @param iterator Iterator to the position before which the new node should be inserted.
 * @param data     Pointer to the data to be inserted.
 * @return         Iterator pointing to the inserted node, or end of the list if insertion fails.
 * Complexity      Time complexity: O(1), Space complexity: O(1).
******************************************************************************/
dll_iter_t DLLInsertBefore(dll_iter_t iterator, void *data);

/******************************************************************************
 * @brief          Removes the node pointed to by the given iterator.
 * @param iterator Iterator pointing to the node to be removed.
 * @return         Iterator pointing to the next node after removal. Undefined behavior on end-of-list.
 * Complexity      Time complexity: O(1), Space complexity: O(1).
******************************************************************************/
dll_iter_t DLLRemove(dll_iter_t iteretor);

/******************************************************************************
 * @brief      Pushes data to the back of the doubly linked list.
 * @param dll  Pointer to the list.
 * @param data Pointer to the data to be pushed.
 * @return     Iterator pointing to the pushed node, or end of the list if push fails.
 * Complexity  Time complexity: O(1), Space complexity: O(1).
******************************************************************************/
dll_iter_t DLLPushBack(dll_t *dll, void *data);

/******************************************************************************
 * @brief      Pushes data to the front of the doubly linked list.
 * @param dll  Pointer to the list.
 * @param data Pointer to the data to be pushed.
 * @return     Iterator pointing to the pushed node, or end of the list if push fails.
 * Complexity  Time complexity: O(1), Space complexity: O(1).
******************************************************************************/
dll_iter_t DLLPushFront(dll_t *dll, void *data);

/******************************************************************************
 * @brief     Pops data from the back of the doubly linked list.
 * @param dll Pointer to the list.
 * @return    Pointer to the popped data.
 * Complexity Time complexity: O(1), Space complexity: O(1).
******************************************************************************/
void *DLLPopBack(dll_t *dll);

/******************************************************************************
 * @brief     Pops data from the front of the doubly linked list.
 * @param dll Pointer to the list.
 * @return    Pointer to the popped data.
 * Complexity Time complexity: O(1), Space complexity: O(1).
******************************************************************************/
void *DLLPopFront(dll_t *dll);

/******************************************************************************
 * @brief          Sets data at a specific node pointed by the given iterator.
 * @param iterator Iterator pointing to the node.
 * @param data     Pointer to the new data to be set.
 * Complexity      Time complexity: O(1), Space complexity: O(1).
******************************************************************************/
void DLLSetData(dll_iter_t iterator, void *data);

/******************************************************************************
 * @brief          Gets data from a specific node pointed by the given iterator.
 * @param position Iterator pointing to the node.
 * @return         Pointer to the data in the node.
 * Complexity      Time complexity: O(1), Space complexity: O(1).
******************************************************************************/
void *DLLGetData(const dll_iter_t iterator);

/******************************************************************************
 * @brief     Returns an iterator pointing to the start of the list.
 * @param dll Pointer to the list.
 * @return    Iterator pointing to the start of the list.
 * Complexity Time complexity: O(1), Space complexity: O(1).
******************************************************************************/
dll_iter_t DLLBegin(const dll_t *dll);

/******************************************************************************
 * @brief     Returns an iterator pointing to the end of the list.
 * @param dll Pointer to the list.
 * @return    Iterator pointing to the end of the list.
 * Complexity Time complexity: O(1), Space complexity: O(1).
******************************************************************************/
dll_iter_t DLLEnd(const dll_t *dll);

/******************************************************************************
 * @brief          Returns the next iterator.
 * @param iterator Iterator.
 * @return         Next iterator.
 * Complexity      Time complexity: O(1), Space complexity: O(1).
******************************************************************************/
dll_iter_t DLLNext(const dll_iter_t iterator);

/******************************************************************************
 * @brief          Returns the previous iterator.
 * @param iterator Iterator.
 * @return         Previous iterator.
 * Complexity      Time complexity: O(1), Space complexity: O(1).
******************************************************************************/
dll_iter_t DLLPrev(const dll_iter_t iterator);

/******************************************************************************
 * @brief     Checks if the doubly linked list is empty.
 * @param dll Pointer to the list.
 * @return    1 if empty, 0 if not.
 * Complexity Time complexity: O(1), Space complexity: O(1).
******************************************************************************/
int DLLIsEmpty(const dll_t *dll);

/******************************************************************************
 * @brief       Checks if two iterators are equal.
 * @param iter1 Iterator.
 * @param iter2 Iterator.
 * @return      1 if equal, 0 if not.
 * Complexity   Time complexity: O(1), Space complexity: O(1).
******************************************************************************/
int DLLIterIsEqual(const dll_iter_t iter1, const dll_iter_t iter2);

/******************************************************************************
 * @brief     Counts the number of nodes in the list.
 * @param dll Pointer to the list.
 * @return    Number of nodes in the list.
 * Complexity Time complexity: O(n), Space complexity: O(1).
******************************************************************************/
size_t DLLCount(const dll_t *dll);

/******************************************************************************
 * @brief       Iterates through the list and performs an action on each node's data.
 * @param from  Iterator pointing to the start of the range.
 * @param to    Iterator pointing to the end of the range (not included).
 * @param act   Action function to be performed on each data element.
 * @param param Parameter to be passed to the action function.
 * @return      0 on success, or the status returned by the action function.
 * Complexity   Time complexity: O(n), Space complexity: O(1).
******************************************************************************/
int DLLForEach(dll_iter_t from, const dll_iter_t to, dll_act_func_t act, void *param);

/******************************************************************************
 * @brief             Splices nodes from one list into another at a specified position.
 * @param dest        Iterator pointing to the destination position.
 * @param source_from Iterator pointing to the start of the source range.
 * @param source_to   Iterator pointing to the end of the source range (not included).
 * Complexity         Time complexity: O(n), Space complexity: O(1).
******************************************************************************/
void DLLSplice(dll_iter_t dest, dll_iter_t source_from, dll_iter_t source_to);

/*****************************************************************************/

/******************************************************************************
 * @brief       Finds the first occurrence of an iterator pointing to a node with data
 *              that satisfies a comparison function.
 * @param from  Starting iterator.
 * @param to    Iterator pointing to the end of the range (not included).
 * @param cmp   Comparison function.
 * @param param Parameter to be passed to the comparison function.
 * @return Iterator pointing to the found node or the end iterator if not found.
 * Complexity Time complexity: O(n), Space complexity: O(1).
******************************************************************************/
dll_iter_t DLLFind(const dll_iter_t from, const dll_iter_t too, dll_cmp_func_t cmp, void *paramter);

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
 * Complexity   Time complexity: O(n), Space complexity: O(1).
******************************************************************************/
int DLLMultiFind(const dll_iter_t from, const dll_iter_t to, dll_cmp_func_t cmp, void *param, dll_t *dest);

/******************************************************************************
 * @brief       Arranges the elements in the list around a pivot value.
 * @param dll   Pointer to the list.
 * @param pivot Pointer to the pivot value.
 * Complexity   Time complexity: O(n), Space complexity: O(1).
******************************************************************************/
void DLLArrange(dll_t *dll, void *pivot);

#endif /* __DLL_H__ */
