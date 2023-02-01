#ifndef _STACK_H_

#define _STACK_H_

#include <stdio.h>
#include <stdbool.h>

typedef struct _node {
	int data;
	struct _node* next;
} Node;

typedef struct _stack {
	Node* top;
	int size;
} Stack;

Stack* init_stack();
int size_stack(Stack* stack);
bool is_empty(Stack* stack);
void print_stack(Stack* stack);
void push(Stack* stack, int data);
bool pop(Stack* stack, int** data_ptr);

#endif