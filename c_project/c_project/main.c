#include <stdio.h>
#include "stack.h"

int main() {
	Stack* stack = stack_init();
	print_stack(stack);
	push(stack, 3);
	print_stack(stack);
	push(stack, 5);
	print_stack(stack);
	pop(stack);
	print_stack(stack);
	pop(stack);
	print_stack(stack);
	pop(stack);
	//printf("Hello world!");
}