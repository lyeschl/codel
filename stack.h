#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct stack {
    char *data;
    int top;
    int size;
} stack;

void init_stack(stack *s, int size);
bool stackIsEmpty(stack *s);
void push(stack *s, char c);
char pop(stack *s);

#endif /* STACK_H */
