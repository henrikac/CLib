#ifndef NODE_H
#define NODE_H

#include <stdio.h>

#include "alloc.h"

typedef struct node_t
{
	void *data;
	struct node_t *next;
	struct node_t *prev;
} node_t;

void node_init(node_t **node, void* data, node_t *next, node_t *prev);
void node_destroy(node_t *node);

#endif
