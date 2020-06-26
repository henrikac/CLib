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

/**
 * Initializes a vector
 * @param[in,out] vec The vector to initialize
*/
void vector_init(vector_t **vec)
{
	exit_if_not_null(*vec, "The vector has already been initialized");

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

	exit_if_null(vec, "Cannot add an item to an uninitialized vector");

	if (vec->size == vec->capacity)
		vector_reserve(vec, vec->capacity * 2);

	new_item = Malloc(sizeof(void*));
	memcpy(new_item, item, sizeof(void*));

	vec->items[vec->size++] = new_item;
}

/**
 * Removes the last item of a vector and returns a pointer to the item
 * @param[in] vec The vector to pop an item from
 * @return Pointer to the last item in the vector
*/
void *vector_pop(vector_t *vec)
{
	void *item = NULL;
	size_t idx;

	exit_if_null(vec, "Cannot pop items from an uninitialized vector");

	if (vec->size < 1)
	{
		fprintf(stderr, "Cannot pop items from an empty vector\n");
		exit(EXIT_FAILURE);
	}

	idx = vec->size - 1;

	item = Malloc(sizeof(void*));
	memcpy(item, vec->items[idx], sizeof(void*));
	free(vec->items[idx]);
	vec->items[idx] = NULL;
	vec->size--;

	return item;
}

/**
 * Reserves memory for the vector
 * @param[in] vec The vector to reserve memory for
 * @param[in] capacity The amount of bytes to reserve for the vector
*/
void vector_reserve(vector_t *vec, size_t capacity)
{
	void **new_mem = NULL;

	if (capacity < vec->size) return;

	new_mem = realloc(vec->items, capacity * sizeof(void*));

	if (new_mem == NULL)
		fprintf(stderr, "\nProblem occured reallocating memory\n");
	else
	{
		vec->capacity = capacity;
		vec->items = new_mem;
	}
}

/**
 * Removes excess memory by reducing the capacity of a vector
 * @param[in] vec The vector to trim
*/
void vector_trim(vector_t *vec)
{
	size_t capacity_diff;
	size_t trim_capacity;

	if (vec->capacity == vec->size || vec->size < 1) return;

	capacity_diff = vec->capacity - vec->size;
	trim_capacity = vec->capacity - capacity_diff;
	
	vector_reserve(vec, trim_capacity);
}

/**
 * Gets the numbers items in a vector
 * @param[in] vec The vector to get the size of
 * @return The number of items in a vector
*/
size_t vector_size(vector_t *vec)
{
	exit_if_null(vec, "Cannot get the size of an uninitialized vector");

	return vec->size;
}

/**
 * Gets the capacity of a vector
 * @param[in] vec The vector to get the capacity of
 * @return The capacity of a vector
*/
size_t vector_capacity(vector_t *vec)
{
	exit_if_null(vec, "Cannot get the capacity of an uninitialzed vector");

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

	exit_if_null(*vec, "The vector has already been destroyed");

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
