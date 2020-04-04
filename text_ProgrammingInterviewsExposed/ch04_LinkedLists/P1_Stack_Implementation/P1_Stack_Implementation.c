#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
	struct Element *next;
	void *data;
} Element;


bool createStack(Element **stack) {
	*stack = NULL;
	return true;
}

bool deleteStack(Element **stack) {
	Element *next;
	while (*stack) {
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	return true;
}

void push(Element **stack, void *data) {
	Element *elem = malloc(sizeof(Element));
	if (!elem) 
		return false;

	elem->data = data;
	elem->next = *stack;
	*stack = elem;
	return true;
}

void *pop(Element **stack) {
	Element *elem;
	if (!(elem = *stack))
		return false;

	*data = elem->data;
	*stack = elem->next;
	free(elem);
	return true;
}







