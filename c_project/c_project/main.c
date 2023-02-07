#include <stdio.h>
#include "stack.h"

int main() {
	Data* data = NULL;
	Stack* stack = init_stack();
	print_stack(stack);
	push(stack, 'a');
	print_stack(stack);
	push(stack, 'b');
	print_stack(stack);
	pop(stack, &data);
	print_stack(stack);
	pop(stack, &data);
	print_stack(stack);
	pop(stack, &data);
	
	if (data != NULL) {
		free(data);
	}
	free(stack);

	return 0;
}