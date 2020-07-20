#ifndef STACK_H
#define STACK_H

#include "node.h"

typedef struct Stack {
    struct Node *head;
} Stack;

struct Stack *create_stack(void);

void push(struct Stack *s, int key);

int is_empty(struct Stack *s);

struct Node *pop(struct Stack *s);

#endif //STACK_H
