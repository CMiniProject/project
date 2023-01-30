#ifndef _STACK_H_

#define _STACK_H_

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

Stack* stack_init();
int size(Stack* stack);
bool isempty(Stack* stack);
void print_stack(Stack* stack);
void push(Stack* stack, int data);
int pop(Stack* stack);

#endif