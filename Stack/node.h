#ifndef NODE_H
#define NODE_H

typedef struct Node {
    int value;
    struct Node *next;
} Node;

struct Node *create_node(int val);

void delete_node(struct Node *n);

#endif //NODE_H