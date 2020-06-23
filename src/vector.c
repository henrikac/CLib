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

/**
 * Initializes a vector
 * @param[in,out] vec The vector to initialize
*/
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

/**
 * Adds an item to the vector
 * @param[in] vec The vector to add an item to
 * @param[in] item The item to add to the vector
*/
void vector_add(vector_t *vec, void *item)
{
	void *new_item = NULL;

	if (vec == NULL)
	{
		fprintf(stderr, "Cannot add an item to an uninitialized vector\n");
		return;
	}

	if (vec->size == vec->capacity)
		vector_reserve(vec, vec->capacity * 2);

	new_item = Malloc(sizeof(void*));
	memcpy(new_item, item, sizeof(void*));

	vec->items[vec->size++] = new_item;
}

/**
 * Reserves memory for the vector
 * @param[in] vec The vector to reserve memory for
 * @param[in] capacity The amount of bytes to reserve for the vector
*/
void vector_reserve(vector_t *vec, size_t capacity)
{
	void **new_mem = NULL;

	if (capacity <= vec->capacity) return;

	new_mem = realloc(vec->items, capacity * sizeof(void*));

	if (new_mem == NULL)
		printf("\nCouldn't allocate more memory.");
	else
	{
		vec->capacity = capacity;
		vec->items = new_mem;
	}
}

/**
 * Gets the numbers items in a vector
 * @param[in] vec The vector to get the size of
 * @return The number of items in a vector if vector is not NULL; otherwise, -1
*/
size_t vector_size(vector_t *vec)
{
	if (vec == NULL)
	{
		fprintf(stderr, "Cannot get size of uninitialized vector\n");
		return -1;
	}

	return vec->size;
}

/**
 * Gets the capacity of a vector
 * @param[in] vec The vector to get the capacity of
 * @return The capacity of a vector if vector is not NULL; otherwise, -1
*/
size_t vector_capacity(vector_t *vec)
{
	if (vec == NULL)
	{
		fprintf(stderr, "Cannot get capacity of uninitialized vector\n");
		return -1;
	}

	return vec->capacity;
}

/**
 * Destroys a vector and all items in it
 * @param[in,out] vec The vector to destroy
*/
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

	if (vec_size != VEC_EMPTY)
	{
		for (i = 0; i < vec_size; i++)
		{
			if ((*vec)->items[i] == NULL) continue;
			free((*vec)->items[i]);
			(*vec)->items[i] = NULL;
		}
	}

	free((*vec)->items);
	free(*vec);
	*vec = NULL;
}
