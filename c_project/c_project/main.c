#include <stdio.h>
#include "stack.h"

int main() {
	int* data = malloc(sizeof(data));
	Stack* stack = init_stack();
	print_stack(stack);
	push(stack, 3);
	print_stack(stack);
	push(stack, 5);
	print_stack(stack);
	pop(stack, data);
	print_stack(stack);
	pop(stack, data);
	print_stack(stack);
	pop(stack, data);
	printf("Hello world!");
	
	free(data);
	free(stack);
	return 0;
}