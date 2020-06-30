/*
 * Contains procedures for working with stack
 * Copyright (C) 2020 Henrik Abel Christensen
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *		
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *						
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "stack.h"

/**
 * Initializes a stack
 * @param[in, out] stack Pointer to the stack to initialize
*/
void stack_init(stack_t **stack)
{
	exit_if_not_null(*stack, "The stack has already been initialized");

	*stack = Malloc(sizeof(stack_t));
	(*stack)->top = NULL;
	(*stack)->size = EMPTY_STACK;
}

/**
 * Adds an item to a stack
 * @param[in] stack Pointer to the stack to add an item to
 * @param[in] value Pointer to the item to add to the stack
*/
void stack_push(stack_t *stack, void *value)
{
	node_t *node = NULL;
	node_t *next = stack->top;

	node_init(&node, value, next);

	stack->top = node;
	stack->size++;
}

/**
 * Removes an item from a stack and returns a pointer the item
 * @param[in] stack Pointer to the stack to remove an item from
 * @return Pointer to the item removed from the stack
*/
node_t *stack_pop(stack_t *stack)
{
	node_t *node = NULL;

	if (stack->size < 1)
	{
		fprintf(stderr, "The stack is empty\n");
		return node;
	}

	node = stack->top;
	stack->top = stack->top->next;
	stack->size--;
	node->next = NULL;

	return node;
}

/**
 * Gets the number of items in a stack
 * @param[in] stack Pointer to the stack to get the size of
 * @return The number of items in a stack
*/
size_t stack_size(stack_t *stack)
{
	return stack->size;
}

/**
 * Destroys a stack and all items in it
 * @param[in, out] stack Pointer to the stack to destroy
*/
void stack_destroy(stack_t **stack)
{
	node_t *top = NULL;

	exit_if_null(*stack, "The stack has already been destroyed");

	if ((*stack)->size > 0)
	{
		top = (*stack)->top;

		while (top != NULL)
		{
			node_t *next = top->next;
			node_destroy(top);
			top = next;
		}
	}

	free(*stack);
	*stack = NULL;
}
