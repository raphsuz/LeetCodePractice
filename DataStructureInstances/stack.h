#include <stdio.h>
#include <stdlib.h>

typedef struct stack stack_c;

struct stack {
    size_t size;
    size_t capacity;
    size_t top;
    int *elements;
};

stack_c * stack_new(void) {
    stack_c *s = malloc(sizeof(stack_c));
    if (!s) return s;

    s->size = 0;
    s->capacity = 2;
    s->top = 0;
    s->elements = malloc(s->capacity * sizeof(int));
    if (!(s->elements)) {
        stack_delete(s);
        s = NULL;
        return s;
    }
    return s;
}