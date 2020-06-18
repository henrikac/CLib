#include "stack.h"

void stack_init(stack_t **stack)
{
	if (*stack != NULL)
	{
		fprintf(stderr, "The stack has already been initialized\n");
		return;
	}

	*stack = Malloc(sizeof(stack_t));
	(*stack)->top = NULL;
	(*stack)->size = EMPTY_STACK;
}

void stack_push(stack_t *stack, void *value)
{
	node_t *node = NULL;
	node_t *prev = stack->top;

	node_init(&node, value, NULL, prev);
	
	if (stack->top != NULL)
		stack->top->next = node;

	stack->top = node;
	stack->size++;
}

node_t *stack_pop(stack_t *stack)
{
	node_t *node = NULL;

	if (stack->size < 1)
	{
		fprintf(stderr, "The stack is empty\n");
		return node;
	}

	node = stack->top;
	stack->top = stack->top->prev;
	stack->size--;
	node->prev = NULL;

	return node;
}

size_t stack_size(stack_t *stack)
{
	return stack->size;
}

void stack_destroy(stack_t *stack)
{
	node_t *top = NULL;

	if (stack == NULL)
	{
		fprintf(stderr, "The stack has already been destroyed\n");
		return;
	}

	if (stack->size < 1)
	{
		Free(stack);
		return;
	}

	top = stack->top;

	while (top != NULL)
	{
		node_t *prev = top->prev;

		node_destroy(top);

		top = prev;
	}

	Free(stack);
}





