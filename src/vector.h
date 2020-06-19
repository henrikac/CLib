/*
 * Vector header file
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

#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>

#include "utils.h"

typedef struct vector_t
{
	size_t capacity;
	size_t size;
	void **items;
} vector_t;

void vector_init(vector_t **vec);
void vector_add(vector_t *vec, void *item);
void vector_reserve(vector_t *vec, size_t size);
void vector_trim(vector_t *vec);
size_t vector_size(vector_t *vec);
size_t vector_capacity(vector_t *vec);
void vector_destroy(vector_t **vec);

#endif
