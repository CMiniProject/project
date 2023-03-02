#include <stdio.h>
#include "stack.h"
#define MAX 50

void to_postfix(char* infix, char* postfix, Stack* stack, Data** data_ptr) {
	char operator;
	char* token = infix;
	int negative = 1;
	while (*token != '\0') {
		switch (*token) {
		case '(':
			push(stack, '(');
			negative = 1;
			token++;
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
			negative = 0;
			token++;
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
			negative = 1;
			token++;
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
			negative = 1;
			token++;
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
			negative = 1;
			token++;
			break;
		case '-':
			if (negative == 1) {
				*(postfix++) = *token;
				token++;
				break;
			}
			else {
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
				negative = 1;
				token++;
				break;
			}
		case ' ':
			token++;
			break;
		default:
			while (*token >= '0' && *token <= '9') {
				*(postfix++) = *token;
				token++;
			}
			*(postfix++) = ' ';
			negative = 0;
			break;
		}
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

	printf("수식을 입력하세요: ");
	if (scanf("%[^\n]", infix) != 1)
	{
		printf("입력 오류\n");
		return 0;
	}
	to_postfix(infix, postfix, stack, &data);
	printf("후위표기식: %s", postfix);
	
	if (data != NULL) {
		free(data);
	}
	free(stack);
	
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

	return 0;
}