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
	double = 2.6;

	stack_init(&stack);
	stack_push(stack, &d1);
	stack_push(stack, &d2);

	printf("Items in stack: %ld\n", stack_size(stack));

	node = stack_pop(stack);
	printf("Top node value: %f\n", *((double*)node->data));
	printf("Items in stack after pop: %ld\n", stack_size(stack));

	return 0;
}
