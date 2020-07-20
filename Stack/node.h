#ifndef NODE_H
#define NODE_H

typedef struct node {
    int value;
    struct node *prev;
    struct node *next;
} node;

typedef struct stack {
    struct node *head;
} stack;

int x(void);

#endif //NODE_H
