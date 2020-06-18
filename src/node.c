/*
 * Contains procedures for working with node
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
