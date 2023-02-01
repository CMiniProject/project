#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

Stack* init_stack() {
	Stack* stack = malloc(sizeof(*stack));
	if (stack == NULL) {
		exit(1);
	}
	stack->top = NULL;
	stack->size = 0;
	return stack;
}

int size_stack(Stack* stack) {
	return stack->size;
}

bool is_empty(Stack* stack) {
	return (stack->top == NULL);
}

void print_stack(Stack* stack) {
	Node* current_node = stack->top;
	while (current_node != NULL) {
		printf("%d ->", current_node->data);
		current_node = current_node->next;
	}
	printf("NULL \n");
}

void push(Stack* stack, int data) {
	Node* new_node = malloc(sizeof(*new_node));
	if (new_node == NULL) {
		exit(1);
	}
	new_node->data = data;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

bool pop(Stack* stack, int** data_ptr) {
	if (is_empty(stack)) {
		printf("stack empty\n");
		*data_ptr = NULL;
		return 0;
	}
	else {
		if (*data_ptr != NULL) {
			free(*data_ptr);
		}
		*data_ptr = malloc(sizeof(**data_ptr));
		int* data = *data_ptr;
		Node* current_node = stack->top;
		*data = current_node->data;
		Node* before_node = current_node->next;
		stack->top = before_node;
		free(current_node);
		stack->size--;
		return 1;
	}
}

