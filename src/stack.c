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

void stack_init(stack_t **stack)
{
	exit_if_not_null(*stack, "The stack has already been initialized");

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

void stack_destroy(stack_t **stack)
{
	node_t *top = NULL;

	exit_if_null(*stack, "The stack has already been destroyed");

	if ((*stack)->size > 0)
	{
		top = (*stack)->top;

		while (top != NULL)
		{
			node_t *prev = top->prev;
			node_destroy(top);
			top = prev;
		}
	}

	free(*stack);
	*stack = NULL;
}
