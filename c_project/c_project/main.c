#include <stdio.h>
#include "stack.h"
#define MAX 50

void to_postfix(char* infix, char* postfix, Stack* stack, Data** data_ptr) {
	char operator;
	char* token = infix;
	while (*token != '\0') {
		switch (*token) {
		case '(':
			push(stack, '(');
			break;
		case ')':
			while (!is_empty(stack)) {
				operator = top(stack);
				if (operator == '(') {
					pop(stack, data_ptr);
					break;
				}
				pop(stack, data_ptr);
				*(postfix++) = **data_ptr;
				*(postfix++) = ' ';
			}
			break;
		case '*':
			while (!is_empty(stack)) {
				operator = top(stack);
				if (operator == '+' || operator == '-' || operator == '(') {
					break;
				}
				pop(stack, data_ptr); 
				*(postfix++) = **data_ptr;
				*(postfix++) = ' ';
			}
			push(stack, '*');
			break;
		case '/':
			while (!is_empty(stack)) {
				operator = top(stack);
				if (operator == '+' || operator == '-' || operator == '(') {
					break;
				}
				pop(stack, data_ptr);
				*(postfix++) = **data_ptr;
				*(postfix++) = ' ';
			}
			push(stack, '/');
			break;
		case '+':
			while (!is_empty(stack)) {
				operator = top(stack);
				if (operator == '(') {
					break;
				}
				pop(stack, data_ptr);
				*(postfix++) = **data_ptr;
				*(postfix++) = ' ';
			}
			push(stack, '+');
			break;
		case '-':
			while (!is_empty(stack)) {
				operator = top(stack);
				if (operator == '(') {
					break;
				}
				pop(stack, data_ptr);
				*(postfix++) = **data_ptr;
				*(postfix++) = ' ';
			}
			push(stack, '-');
			break;
		default:
			*(postfix++) = *token;
			*(postfix++) = ' ';
		}
		token++;
	}
	while (!is_empty(stack)) {
		pop(stack, data_ptr);
		*(postfix++) = **data_ptr;
		*(postfix++) = ' ';
	}
	*(postfix++) = '\0';
}

int main() {
	
	char infix[MAX];
	char postfix[MAX];
	Data* data = NULL;
	Stack* stack = init_stack();

	printf("������ �Է��ϼ���: ");
	if (scanf("%s", infix) != 1)
	{
		printf("�Է� ����\n");
		return 0;
	}
	to_postfix(infix, postfix, stack, &data);
	printf("����ǥ���: %s", postfix);
	

	/*
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
	*/
	if (data != NULL) {
		free(data);
	}
	free(stack);

	return 0;
}