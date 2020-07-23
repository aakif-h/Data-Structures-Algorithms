#ifndef NODE_H
#define NODE_H

typedef struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

Node *create_node(int val);

void delete_node(Node *n);

#endif //NODE_H