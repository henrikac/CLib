/*
 * Stack header file
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

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
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
void stack_destroy(stack_t **stack);

#endif
