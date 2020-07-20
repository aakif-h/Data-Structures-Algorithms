#ifndef STACK_H
#define STACK_H

#include "node.h"

typedef struct Stack {
    struct Node *head;
} Stack;

struct Stack *create_stack(void);

void push_to_stack(struct Stack *s, int key);

int is_empty(struct Stack *s);

struct Node *pop_from_stack(struct Stack *s);

#endif //STACK_H
