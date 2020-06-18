#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

#include "alloc.h"
#include "node.h"

#define EMPTY_STACK 0

typedef struct stack_t
{
	node_t *top;
	size_t size;
} stack_t;

void stack_init(stack_t **stack);
void stack_push(stack_t *stack, void *value);
node_t *stack_pop(stack_t *stack);
size_t stack_size(stack_t *stack);
void stack_destroy(stack_t *stack);

#endif
