#ifndef ALLOC_H
#define ALLOC_H

#include <stdio.h>
#include <stdlib.h>

void *Malloc(size_t size);
void *Calloc(size_t nitems, size_t size);
void Free(void *ptr);

#endif
