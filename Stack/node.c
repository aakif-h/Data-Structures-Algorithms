#include <stdlib.h>
#include "node.h"

struct Node *create_node(int val) {
    struct Node *n =  (struct Node*)malloc(sizeof(struct Node));
    n->value = val;
    n->next = NULL;
}

void delete_node(struct Node *n) {
    n->next = NULL;
    free(n);
}