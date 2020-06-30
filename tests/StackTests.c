#include <stdlib.h>

#include "CuTest.h"

#include "node.h"
#include "stack.h"


void TestStackInit(CuTest *tc)
{
	stack_t *stack = NULL;
	size_t expected_size = EMPTY_STACK;
	size_t actual_size;

	stack_init(&stack);

	actual_size = stack->size;

	CuAssertPtrNotNull(tc, stack);
	CuAssertPtrEquals(tc, NULL, stack->top);
	CuAssertIntEquals(tc, expected_size, actual_size);

	stack_destroy(&stack);
}

void TestStackDestroy(CuTest *tc)
{
	stack_t *stack = NULL;

	stack_init(&stack);
	stack_destroy(&stack);

	CuAssertPtrEquals(tc, NULL, stack);
}

void TestStackPush(CuTest *tc)
{
	stack_t *stack = NULL;
	size_t expected_size = 3;
	size_t actual_size;
	int i;

	stack_init(&stack);

	for (i = 0; i < 3; i++)
		stack_push(stack, &i);

	actual_size = stack->size;

	CuAssertPtrNotNull(tc, stack);
	CuAssertPtrNotNull(tc, stack->top);
	CuAssertIntEquals(tc, expected_size, actual_size);

	stack_destroy(&stack);
}

void TestStackPop(CuTest *tc)
{
	stack_t *stack = NULL;
	node_t *node = NULL;
	size_t expected_size = 4;
	size_t actual_size;
	int i;

	stack_init(&stack);

	for (i = 0; i < 5; i++)
	{
		int tmp = i;
		stack_push(stack, &tmp);
	}

	node = stack_pop(stack);
	actual_size = stack->size;

	CuAssertPtrNotNull(tc, stack);
	CuAssertPtrNotNull(tc, stack->top);
	CuAssertIntEquals(tc, 4, *(int*)node->data);
	CuAssertIntEquals(tc, expected_size, actual_size);

	free(node);
	stack_destroy(&stack);
}

void TestStackSize(CuTest *tc)
{
	stack_t *stack = NULL;
	node_t *node = NULL;
	size_t expected_size = 2;
	size_t actual_size;
	int i;

	stack_init(&stack);

	for (i = 0; i < 5; i++)
		stack_push(stack, &i);

	node = stack_pop(stack);
	free(node);
	node = stack_pop(stack);
	free(node);
	node = stack_pop(stack);
	free(node);

	actual_size = stack_size(stack);

	CuAssertPtrNotNull(tc, stack);
	CuAssertIntEquals(tc, expected_size, actual_size);

	stack_destroy(&stack);
}

CuSuite *StackGetSuite()
{
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, TestStackInit);
	SUITE_ADD_TEST(suite, TestStackDestroy);
	SUITE_ADD_TEST(suite, TestStackPush);
	SUITE_ADD_TEST(suite, TestStackPop);
	SUITE_ADD_TEST(suite, TestStackSize);
	return suite;
}





