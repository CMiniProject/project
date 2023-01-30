#include <stdio.h>
#include <stdbool.h>

typedef struct _node {
	int data;
	struct _node* next;
}Node;

typedef struct _stack {
	Node* top;
	int size;
}Stack;

Stack* stack_init() {
	Stack* stack = malloc(sizeof(*stack));
	stack->top = NULL;
	stack->size = 0;
	return stack;
}

int size(Stack* stack) {
	return stack->size;
}

bool isempty(Stack* stack) {
	if (stack->top == NULL) {
		return true;
	}
	else {
		return false;
	}
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
	new_node->data = data;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

int pop(Stack* stack) {
	if (isempty(stack)) {
		printf("stack empty\n");
	}
	else {
		Node* current_node = stack->top;
		int data = current_node->data;
		Node* before_node = current_node->next;
		stack->top = before_node;
		free(current_node);
		return data;
	}
}

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