/******************************************************************************
 * @writer:      Tal Aharon
 * @date:        30.03.2023
 * 
 * @description: This test file contains a set of test cases for the Priority 
 *               Queue implementation.
 * 
******************************************************************************/
#include <stdio.h>   /* printf, puts */
#include <assert.h>  /*   assert     */
#include <stdlib.h>  /*   system     */

#include "priority_queue.h"
/*****************************************************************************/
void PriorityQueueCreateTest(void);
void PriorityQueueEnqueueTest(void);
void PriorityQueueDequeueTest(void);
void PriorityQueuePeekTest(void);
void PriorityQueueIsEmptyTest(void);
void PriorityQueueSizeTest(void);
void PriorityQueueEraseTest(void);
void PriorityQueueClearTest(void);
/*****************************************************************************/
int main(void)
{
	PriorityQueueCreateTest();
	printf("\nPriorityQueueCreateTest(): Passed.");
	PriorityQueueEnqueueTest();
	printf("\nPriorityQueueEnqueueTest(): Passed.");
	PriorityQueueDequeueTest();
	printf("\nPriorityQueueDequeueTest(): Passed.");
	PriorityQueuePeekTest();
	printf("\nPriorityQueuePeekTest(): Passed.");
	PriorityQueueIsEmptyTest();
	printf("\nPriorityQueueIsEmptyTest(): Passed.");
	PriorityQueueSizeTest();
	printf("\nPriorityQueueSizeTest(): Passed.");
	PriorityQueueEraseTest();
	printf("\nPriorityQueueEraseTest(): Passed.");
	PriorityQueueClearTest();
	printf("\nPriorityQueueClearTest(): Passed.\n\n");
	return (0);
}
/*****************************************************************************/
int Match(void *data, void *parameter)
{
	return (size_t)parameter == (size_t)data;
}
/*****************************************************************************/
int Cmp(void *data, void *parameter)
{
	return ((size_t)parameter - (size_t)data);
}
/*****************************************************************************/
void PriorityQueueCreateTest(void)
{
	priority_queue_t *priority_queue = NULL;
	assert(NULL == priority_queue && "Creation failed");
	priority_queue = PriorityQueueCreate(Cmp);
	assert(priority_queue && "Creation failed");
	assert(1 == PriorityQueueIsEmpty(priority_queue));
	assert(0 == PriorityQueueSize(priority_queue));
	PriorityQueueDestroy(priority_queue);
}
/*****************************************************************************/
void PriorityQueueEnqueueTest(void)
{
	priority_queue_t *priority_queue = NULL;
	assert(NULL == priority_queue && "Creation failed");
	priority_queue = PriorityQueueCreate(Cmp);
	assert(priority_queue && "Creation failed");
	assert(1 == PriorityQueueIsEmpty(priority_queue));
	assert(0 == PriorityQueueSize(priority_queue));
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)9);
	PriorityQueueEnqueue(priority_queue, (void *)18);
	PriorityQueueEnqueue(priority_queue, (void *)167);
	PriorityQueueEnqueue(priority_queue, (void *)14);
	PriorityQueueEnqueue(priority_queue, (void *)12);
	PriorityQueueEnqueue(priority_queue, (void *)112);
	PriorityQueueEnqueue(priority_queue, (void *)14);
	PriorityQueueEnqueue(priority_queue, (void *)144444);
	PriorityQueueEnqueue(priority_queue, (void *)144);
	PriorityQueueEnqueue(priority_queue, (void *)11233);
	PriorityQueueEnqueue(priority_queue, (void *)11);
	PriorityQueueEnqueue(priority_queue, (void *)0);
	PriorityQueueEnqueue(priority_queue, (void *)9);
	PriorityQueueEnqueue(priority_queue, (void *)457);
	PriorityQueueEnqueue(priority_queue, (void *)7);
	PriorityQueueEnqueue(priority_queue, (void *)6);
	PriorityQueueEnqueue(priority_queue, (void *)5);
	PriorityQueueEnqueue(priority_queue, (void *)43613);
	PriorityQueueEnqueue(priority_queue, (void *)1346);
	PriorityQueueEnqueue(priority_queue, (void *)1346);
	PriorityQueueEnqueue(priority_queue, (void *)1346);
	PriorityQueueEnqueue(priority_queue, (void *)137);
	PriorityQueueEnqueue(priority_queue, (void *)1347);
	PriorityQueueEnqueue(priority_queue, (void *)137);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)13);
	PriorityQueueEnqueue(priority_queue, (void *)11375);
	PriorityQueueEnqueue(priority_queue, (void *)1357);
	PriorityQueueEnqueue(priority_queue, (void *)13571357);
	PriorityQueueEnqueue(priority_queue, (void *)1537);
	PriorityQueueEnqueue(priority_queue, (void *)13571357);
	PriorityQueueEnqueue(priority_queue, (void *)13513571);
	PriorityQueueEnqueue(priority_queue, (void *)46791);
	PriorityQueueEnqueue(priority_queue, (void *)1578);
	PriorityQueueEnqueue(priority_queue, (void *)15689);
	PriorityQueueEnqueue(priority_queue, (void *)14679);
	PriorityQueueEnqueue(priority_queue, (void *)4671);
	PriorityQueueEnqueue(priority_queue, (void *)2451);
	PriorityQueueEnqueue(priority_queue, (void *)24571);
	PriorityQueueEnqueue(priority_queue, (void *)24571);
	PriorityQueueEnqueue(priority_queue, (void *)24571);
	PriorityQueueEnqueue(priority_queue, (void *)2451);
	PriorityQueueEnqueue(priority_queue, (void *)1245);
	PriorityQueueEnqueue(priority_queue, (void *)245724571);
	PriorityQueueEnqueue(priority_queue, (void *)2451);
	PriorityQueueEnqueue(priority_queue, (void *)24571);
	PriorityQueueEnqueue(priority_queue, (void *)12457);
	PriorityQueueEnqueue(priority_queue, (void *)3461);
	PriorityQueueEnqueue(priority_queue, (void *)1457);
	PriorityQueueEnqueue(priority_queue, (void *)1457);
	PriorityQueueEnqueue(priority_queue, (void *)1457);
	PriorityQueueEnqueue(priority_queue, (void *)1457);
	PriorityQueueEnqueue(priority_queue, (void *)1457);
	PriorityQueueEnqueue(priority_queue, (void *)1457);
	PriorityQueueEnqueue(priority_queue, (void *)1457);
	PriorityQueueEnqueue(priority_queue, (void *)14574);
	PriorityQueueEnqueue(priority_queue, (void *)125);
	PriorityQueueEnqueue(priority_queue, (void *)1257);
	PriorityQueueEnqueue(priority_queue, (void *)12475);
	PriorityQueueEnqueue(priority_queue, (void *)135);
	PriorityQueueEnqueue(priority_queue, (void *)1357);
	PriorityQueueEnqueue(priority_queue, (void *)14679);
	PriorityQueueEnqueue(priority_queue, (void *)197);
	PriorityQueueEnqueue(priority_queue, (void *)1479);
	PriorityQueueEnqueue(priority_queue, (void *)14679);
	PriorityQueueEnqueue(priority_queue, (void *)1479);
	PriorityQueueEnqueue(priority_queue, (void *)14679);
	PriorityQueueEnqueue(priority_queue, (void *)14679);
	assert(78 == PriorityQueueSize(priority_queue));
	PriorityQueueDestroy(priority_queue);
}
/*****************************************************************************/
void PriorityQueueDequeueTest(void)
{
	size_t i = 77;
	priority_queue_t *priority_queue = NULL;
	assert(NULL == priority_queue && "Creation failed");
	priority_queue = PriorityQueueCreate(Cmp);
	assert(priority_queue && "Creation failed");
	assert(1 == PriorityQueueIsEmpty(priority_queue));
	assert(0 == PriorityQueueSize(priority_queue));

	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)9);
	PriorityQueueEnqueue(priority_queue, (void *)18);
	PriorityQueueEnqueue(priority_queue, (void *)167);
	PriorityQueueEnqueue(priority_queue, (void *)14);
	PriorityQueueEnqueue(priority_queue, (void *)12);
	PriorityQueueEnqueue(priority_queue, (void *)112);
	PriorityQueueEnqueue(priority_queue, (void *)14);
	PriorityQueueEnqueue(priority_queue, (void *)144444);
	PriorityQueueEnqueue(priority_queue, (void *)144);
	PriorityQueueEnqueue(priority_queue, (void *)11233);
	PriorityQueueEnqueue(priority_queue, (void *)11);
	PriorityQueueEnqueue(priority_queue, (void *)0);
	PriorityQueueEnqueue(priority_queue, (void *)9);
	PriorityQueueEnqueue(priority_queue, (void *)457);
	PriorityQueueEnqueue(priority_queue, (void *)7);
	PriorityQueueEnqueue(priority_queue, (void *)6);
	PriorityQueueEnqueue(priority_queue, (void *)5);
	PriorityQueueEnqueue(priority_queue, (void *)43613);
	PriorityQueueEnqueue(priority_queue, (void *)1346);
	PriorityQueueEnqueue(priority_queue, (void *)1346);
	PriorityQueueEnqueue(priority_queue, (void *)1346);
	PriorityQueueEnqueue(priority_queue, (void *)137);
	PriorityQueueEnqueue(priority_queue, (void *)1347);
	PriorityQueueEnqueue(priority_queue, (void *)137);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)13);
	PriorityQueueEnqueue(priority_queue, (void *)11375);
	PriorityQueueEnqueue(priority_queue, (void *)1357);
	PriorityQueueEnqueue(priority_queue, (void *)13571357);
	PriorityQueueEnqueue(priority_queue, (void *)1537);
	PriorityQueueEnqueue(priority_queue, (void *)13571357);
	PriorityQueueEnqueue(priority_queue, (void *)13513571);
	PriorityQueueEnqueue(priority_queue, (void *)46791);
	PriorityQueueEnqueue(priority_queue, (void *)1578);
	PriorityQueueEnqueue(priority_queue, (void *)15689);
	PriorityQueueEnqueue(priority_queue, (void *)14679);
	PriorityQueueEnqueue(priority_queue, (void *)4671);
	PriorityQueueEnqueue(priority_queue, (void *)2451);
	PriorityQueueEnqueue(priority_queue, (void *)24571);
	PriorityQueueEnqueue(priority_queue, (void *)24571);
	PriorityQueueEnqueue(priority_queue, (void *)24571);
	PriorityQueueEnqueue(priority_queue, (void *)2451);
	PriorityQueueEnqueue(priority_queue, (void *)1245);
	PriorityQueueEnqueue(priority_queue, (void *)245724571);
	PriorityQueueEnqueue(priority_queue, (void *)2451);
	PriorityQueueEnqueue(priority_queue, (void *)24571);
	PriorityQueueEnqueue(priority_queue, (void *)12457);
	PriorityQueueEnqueue(priority_queue, (void *)3461);
	PriorityQueueEnqueue(priority_queue, (void *)1457);
	PriorityQueueEnqueue(priority_queue, (void *)1457);
	PriorityQueueEnqueue(priority_queue, (void *)1457);
	PriorityQueueEnqueue(priority_queue, (void *)1457);
	PriorityQueueEnqueue(priority_queue, (void *)1457);
	PriorityQueueEnqueue(priority_queue, (void *)1457);
	PriorityQueueEnqueue(priority_queue, (void *)1457);
	PriorityQueueEnqueue(priority_queue, (void *)14574);
	PriorityQueueEnqueue(priority_queue, (void *)125);
	PriorityQueueEnqueue(priority_queue, (void *)1257);
	PriorityQueueEnqueue(priority_queue, (void *)12475);
	PriorityQueueEnqueue(priority_queue, (void *)135);
	PriorityQueueEnqueue(priority_queue, (void *)1357);
	PriorityQueueEnqueue(priority_queue, (void *)14679);
	PriorityQueueEnqueue(priority_queue, (void *)197);
	PriorityQueueEnqueue(priority_queue, (void *)1479);
	PriorityQueueEnqueue(priority_queue, (void *)14679);
	PriorityQueueEnqueue(priority_queue, (void *)1479);
	PriorityQueueEnqueue(priority_queue, (void *)14679);
	PriorityQueueEnqueue(priority_queue, (void *)14679);

	for(;i > 0; --i)
	{
		PriorityQueueDequeue(priority_queue);
		assert(i == PriorityQueueSize(priority_queue));
	}
	PriorityQueueDequeue(priority_queue);
	assert(1 == PriorityQueueIsEmpty(priority_queue));
	PriorityQueueDestroy(priority_queue);
}
/*****************************************************************************/
void PriorityQueuePeekTest(void)
{
	priority_queue_t *priority_queue = NULL;
	assert(NULL == priority_queue && "Creation failed");
	priority_queue = PriorityQueueCreate(Cmp);
	assert(priority_queue && "Creation failed");
	assert(1 == PriorityQueueIsEmpty(priority_queue));
	assert(0 == PriorityQueueSize(priority_queue));
	PriorityQueueEnqueue(priority_queue, (void *)1257);
	assert((void *)1257 == PriorityQueuePeek(priority_queue));
	PriorityQueueEnqueue(priority_queue, (void *)12475);
	assert((void *)12475 == PriorityQueuePeek(priority_queue));
	PriorityQueueEnqueue(priority_queue, (void *)135);
	assert((void *)12475 == PriorityQueuePeek(priority_queue));
	PriorityQueueEnqueue(priority_queue, (void *)1357);
	assert((void *)12475 == PriorityQueuePeek(priority_queue));
	PriorityQueueEnqueue(priority_queue, (void *)14679);
	assert((void *)14679 == PriorityQueuePeek(priority_queue));
	PriorityQueueEnqueue(priority_queue, (void *)197);
	assert((void *)14679 == PriorityQueuePeek(priority_queue));
	PriorityQueueEnqueue(priority_queue, (void *)1479);
	assert((void *)14679 == PriorityQueuePeek(priority_queue));
	PriorityQueueEnqueue(priority_queue, (void *)14670009);
	assert((void *)14670009 == PriorityQueuePeek(priority_queue));
	PriorityQueueEnqueue(priority_queue, (void *)1479);
	assert((void *)14670009 == PriorityQueuePeek(priority_queue));
	PriorityQueueEnqueue(priority_queue, (void *)14679);
	assert((void *)14670009 == PriorityQueuePeek(priority_queue));
	PriorityQueueEnqueue(priority_queue, (void *)14679);
	assert((void *)14670009 == PriorityQueuePeek(priority_queue));
	PriorityQueueDestroy(priority_queue);
}
/*****************************************************************************/
void PriorityQueueIsEmptyTest(void)
{
	priority_queue_t *priority_queue = NULL;
	assert(NULL == priority_queue && "Destroy failed");
	priority_queue = PriorityQueueCreate(Cmp);
	assert(priority_queue && "Destroy failed");
	assert(1 == PriorityQueueIsEmpty(priority_queue));
	PriorityQueueEnqueue(priority_queue, (void *)1257);
	assert(0 == PriorityQueueIsEmpty(priority_queue));
	PriorityQueueDestroy(priority_queue);
}
/*****************************************************************************/
void PriorityQueueSizeTest(void)
{
	size_t i = 0;
	priority_queue_t *priority_queue = NULL;
	assert(NULL == priority_queue && "Destroy failed");
	priority_queue = PriorityQueueCreate(Cmp);
	assert(priority_queue && "Destroy failed");
	assert(0 == PriorityQueueSize(priority_queue));
	for(;i < 500000; i++)
	{
		PriorityQueueEnqueue(priority_queue, (void *)14679);
	}
	assert(500000 == PriorityQueueSize(priority_queue));
	PriorityQueueDestroy(priority_queue);
}
/*****************************************************************************/
void PriorityQueueEraseTest(void)
{
	priority_queue_t *priority_queue = NULL;
	assert(NULL == priority_queue && "Destroy failed");
	priority_queue = PriorityQueueCreate(Cmp);
	assert(priority_queue && "Destroy failed");
	assert(1 == PriorityQueueIsEmpty(priority_queue));
	assert(0 == PriorityQueueSize(priority_queue));
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)9);
	PriorityQueueEnqueue(priority_queue, (void *)18);
	assert(0 == PriorityQueueIsEmpty(priority_queue));
	assert(0 != PriorityQueueSize(priority_queue));
	assert((void *)1 == PriorityQueueErase(priority_queue, Match, (void *)1));
	assert((void *)9 == PriorityQueueErase(priority_queue, Match, (void *)9));
	assert((void *)priority_queue == PriorityQueueErase(priority_queue, Match, (void *)99));
	assert((void *)18 == PriorityQueueErase(priority_queue, Match, (void *)18));
	assert(1 == PriorityQueueIsEmpty(priority_queue));
	assert(0 == PriorityQueueSize(priority_queue));
	PriorityQueueDestroy(priority_queue);
}
/*****************************************************************************/
void PriorityQueueClearTest(void)
{
	priority_queue_t *priority_queue = NULL;
	assert(NULL == priority_queue && "Creation failed");
	priority_queue = PriorityQueueCreate(Cmp);
	assert(priority_queue && "Creation failed");
	assert(1 == PriorityQueueIsEmpty(priority_queue));
	assert(0 == PriorityQueueSize(priority_queue));

	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)9);
	PriorityQueueEnqueue(priority_queue, (void *)18);
	PriorityQueueEnqueue(priority_queue, (void *)167);
	PriorityQueueEnqueue(priority_queue, (void *)14);
	PriorityQueueEnqueue(priority_queue, (void *)12);
	PriorityQueueEnqueue(priority_queue, (void *)112);
	PriorityQueueEnqueue(priority_queue, (void *)14);
	PriorityQueueEnqueue(priority_queue, (void *)144444);
	PriorityQueueEnqueue(priority_queue, (void *)144);
	PriorityQueueEnqueue(priority_queue, (void *)11233);
	PriorityQueueEnqueue(priority_queue, (void *)11);
	PriorityQueueEnqueue(priority_queue, (void *)0);
	PriorityQueueEnqueue(priority_queue, (void *)9);
	PriorityQueueEnqueue(priority_queue, (void *)457);
	PriorityQueueEnqueue(priority_queue, (void *)7);
	PriorityQueueEnqueue(priority_queue, (void *)6);
	PriorityQueueEnqueue(priority_queue, (void *)5);
	PriorityQueueEnqueue(priority_queue, (void *)43613);
	PriorityQueueEnqueue(priority_queue, (void *)1346);
	PriorityQueueEnqueue(priority_queue, (void *)1346);
	PriorityQueueEnqueue(priority_queue, (void *)1346);
	PriorityQueueEnqueue(priority_queue, (void *)137);
	PriorityQueueEnqueue(priority_queue, (void *)1347);
	PriorityQueueEnqueue(priority_queue, (void *)137);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)1);
	PriorityQueueEnqueue(priority_queue, (void *)13);
	PriorityQueueEnqueue(priority_queue, (void *)11375);
	PriorityQueueEnqueue(priority_queue, (void *)1357);
	PriorityQueueEnqueue(priority_queue, (void *)13571357);
	PriorityQueueEnqueue(priority_queue, (void *)1537);
	PriorityQueueEnqueue(priority_queue, (void *)13571357);
	PriorityQueueEnqueue(priority_queue, (void *)13513571);
	PriorityQueueEnqueue(priority_queue, (void *)46791);
	PriorityQueueEnqueue(priority_queue, (void *)1578);
	PriorityQueueEnqueue(priority_queue, (void *)15689);
	PriorityQueueEnqueue(priority_queue, (void *)14679);
	PriorityQueueEnqueue(priority_queue, (void *)4671);
	PriorityQueueEnqueue(priority_queue, (void *)2451);
	PriorityQueueEnqueue(priority_queue, (void *)24571);
	PriorityQueueEnqueue(priority_queue, (void *)24571);
	PriorityQueueEnqueue(priority_queue, (void *)24571);
	PriorityQueueEnqueue(priority_queue, (void *)2451);
	PriorityQueueEnqueue(priority_queue, (void *)1245);
	PriorityQueueEnqueue(priority_queue, (void *)245724571);
	PriorityQueueEnqueue(priority_queue, (void *)2451);
	PriorityQueueEnqueue(priority_queue, (void *)24571);
	PriorityQueueEnqueue(priority_queue, (void *)12457);
	PriorityQueueEnqueue(priority_queue, (void *)3461);
	PriorityQueueEnqueue(priority_queue, (void *)1457);
	PriorityQueueEnqueue(priority_queue, (void *)1457);
	PriorityQueueEnqueue(priority_queue, (void *)1457);
	PriorityQueueEnqueue(priority_queue, (void *)1457);
	PriorityQueueEnqueue(priority_queue, (void *)1457);
	PriorityQueueEnqueue(priority_queue, (void *)1457);
	PriorityQueueEnqueue(priority_queue, (void *)1457);
	PriorityQueueEnqueue(priority_queue, (void *)14574);
	PriorityQueueEnqueue(priority_queue, (void *)125);
	PriorityQueueEnqueue(priority_queue, (void *)1257);
	PriorityQueueEnqueue(priority_queue, (void *)12475);
	PriorityQueueEnqueue(priority_queue, (void *)135);
	PriorityQueueEnqueue(priority_queue, (void *)1357);
	PriorityQueueEnqueue(priority_queue, (void *)14679);
	PriorityQueueEnqueue(priority_queue, (void *)197);
	PriorityQueueEnqueue(priority_queue, (void *)1479);
	PriorityQueueEnqueue(priority_queue, (void *)14679);
	PriorityQueueEnqueue(priority_queue, (void *)1479);
	PriorityQueueEnqueue(priority_queue, (void *)14679);
	PriorityQueueEnqueue(priority_queue, (void *)14679);

	assert(0 == PriorityQueueIsEmpty(priority_queue));
	assert(0 != PriorityQueueSize(priority_queue));
	PriorityQueueClear(priority_queue);
	PriorityQueueClear(priority_queue);
	assert(1 == PriorityQueueIsEmpty(priority_queue));
	assert(0 == PriorityQueueSize(priority_queue));
	PriorityQueueDestroy(priority_queue);
}
/*****************************************************************************/
