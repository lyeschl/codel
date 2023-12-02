#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void init_stack(stack *s, int size) {
    s->data = malloc(sizeof(char) * size);
    if (s->data == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    s->top = -1;
    s->size = size;
}

bool stackIsEmpty(stack *s) {
    return s->top == -1;
}

void push(stack *s, char c) {
    if (s->top == s->size - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->data[++s->top] = c;
}

char pop(stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top--];
}
