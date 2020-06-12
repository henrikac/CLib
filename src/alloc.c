#include "alloc.h"

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

/**
 * Deallocates the memory previously allocated by a call to Malloc or Calloc
 * @param[in] ptr Pointer to the memory block to be deallocated 
*/
void Free(void *ptr)
{
	if (ptr == NULL) return;

	free(ptr);
	ptr = NULL;
}
