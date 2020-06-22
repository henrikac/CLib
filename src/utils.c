/*
 * Contains different utility procedures
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

#include "utils.h"

/**
 * Allocates the requested memory and returns a pointer to it
 * @param[in] size Size of the memory block, in bytes
 * @return Pointer to the allocated memory
*/
void *Malloc(size_t size)
{
	void *m = malloc(size);

	if (m == NULL)
	{
		fprintf(stderr, "Couldn't allocate the requested memory.\n");
		exit(EXIT_FAILURE);
	}

	return m;
}

/**
 * Allocates the requested memory and returns a pointer to it
 * @param[in] nitems The number of items to be allocated
 * @param[in] size Size of the elements
 * @return Pointer to the allocated memory
*/
void *Calloc(size_t nitems, size_t size)
{
	void *c = calloc(nitems, size);

	if (c == NULL)
	{
		fprintf(stderr, "Couldn't allocate the requested memory.\n");
		exit(EXIT_FAILURE);
	}

	return c;
}
