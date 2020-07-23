#ifndef LIST_H
#define LIST_H

#include "node.h"

typedef struct List {
    Node *head;
    Node *tail;
    int size;
} List;

List *create_list(void);

void append_to_list(List *l, int val);

void prepend_to_list(List *l, int val);

Node *pop_from_list(List *l, int index);

Node *get_from_list(List *l, int index);

void delete_list(List *l);

#endif //LIST_H