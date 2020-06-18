#include "node.h"

void node_init(node_t **node, void *data, node_t *next, node_t *prev)
{
	if (*node != NULL)
	{
		fprintf(stderr, "The node has already been initialized\n");
		return;
	}

	*node = Malloc(sizeof(node_t));
	(*node)->data = data;
	(*node)->next = next;
	(*node)->prev = prev;
}

void node_destroy(node_t *node)
{
	Free(node);
}
