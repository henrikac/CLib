/*
 * Contains procedures for working with vector
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

#include "vector.h"

#define VEC_EMPTY 0
#define VEC_INIT_CAP 4

void vector_init(vector_t **vec)
{
	if (*vec != NULL)
	{
		fprintf(stderr, "The vector has already been initialized\n");
		return;
	}

	*vec = Malloc(sizeof(vector_t));
	(*vec)->capacity = VEC_INIT_CAP;
	(*vec)->size = VEC_EMPTY;
	(*vec)->items = Malloc(sizeof(void*) * VEC_INIT_CAP);
}

void vector_destroy(vector_t **vec)
{
	size_t i;
	size_t vec_size;

	if (*vec == NULL)
	{
		fprintf(stderr, "The vector has already been destroyed\n");
		return;
	}

	vec_size = (*vec)->size;

	if (vec_size == VEC_EMPTY)
	{
		Free((*vec)->items);
		Free(*vec);
		return;
	}

	for (i = 0; i < vec_size; i++)
		Free((*vec)->items[i]);

	Free((*vec)->items);
	Free(*vec);
}
