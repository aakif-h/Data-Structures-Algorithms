#include <stdlib.h>
#include "stack.h"
#include "node.h"


struct Stack *create_stack(void) {
    struct Stack *s =  (struct Stack*)malloc(sizeof(struct Stack));
    s->head = NULL;
    return s;
}


void push_to_stack(struct Stack *s, int key) {
    struct Node *n = create_node(key);
    n->next = s->head;
    s->head = n;
}


int is_empty(struct Stack *s) {
    if (s->head == NULL) {
        return 1;
    }
    return 0;
}


struct Node *pop_from_stack(struct Stack *s) {
    if (is_empty(s)) {
        return NULL;
    }
    struct Node *n = s->head;
    struct Node *new_head = s->head->next;
    s->head = new_head;
    return n;
}


void delete_stack(struct Stack *s) {
    struct Node *iter = s->head;
    struct Node *delete;
    while (iter != NULL) {
        delete = iter;
        iter = iter->next;
        delete_node(delete);
    }
    free(s);
}