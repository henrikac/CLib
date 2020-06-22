# CLib


### Example: Stack

```
#include <stdio.h>

#include "stack.h"

int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	node_t *node = NULL;
	int d1 = 4;
	double d2 = 2.6;

	stack_init(&stack);
	stack_push(stack, &d1);
	stack_push(stack, &d2);

	printf("Items in stack: %ld\n", stack_size(stack));

	node = stack_pop(stack);
	printf("Top node value: %f\n", *((double*)node->data));
	printf("Items in stack after pop: %ld\n", stack_size(stack));

	node_destroy(node);
	stack_destroy(stack);

	return 0;
}

### Example: Vector
```
#include <stdio.h>

#include "vector.h"

int main(int argc, char **argv)
{
	vector_t *vec = NULL;

	vector_init(&vec);
	printf("Vector size: %ld\n", vector_size(vec));
	printf("Vector capacity: %ld\n", vector_capacity(vec));
	vector_destroy(&vec);

	if (vec == NULL)
		printf("Vector is NULL\n");

	/* vec == NULL */
	vector_destroy(&vec); /* nothing happens */

	printf("Vector size: %ld\n", vector_size(vec)); /* prints -1 */

	return 0;
}
```
