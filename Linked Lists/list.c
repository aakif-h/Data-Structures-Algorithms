#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "node.h"

List *create_list(void) {
    List *l = (List *)malloc(sizeof(List));
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    return l;
}

void append_to_list(List *l, int val) {
    assert(l != NULL);
    if (l->size == 0) {
        l->head = create_node(val);
        l->tail = l->head;
    }
    else {
        Node *temp = l->tail;
        l->tail = create_node(val);
        l->tail->prev = temp;
        temp->next = l->tail;
    }
    l->size = l->size + 1;
}

void prepend_to_list(List *l, int val) {
    assert(l != NULL);
    if (l->size == 0) {
        l->head = create_node(val);
        l->tail = l->head;
    }
    else {
        Node *temp = l->head;
        l->head = create_node(val);
        l->head->next = temp;
        temp->prev = l->head;
    }
    l->size = l->size + 1;
}

Node *pop_from_list(List *l, int index) {
    assert(l != NULL);
    assert(l->size > 0);

    Node *iter, *temp;
    int count;
    if (index >= 0) {
        iter = l->head;
        if (index == 0) {
            temp = iter->next;
            l->head = temp;
            temp->prev = NULL;
            return iter;
        }

        count = 0;
        while (count < index) {
            iter = iter->next;
            count++;
        }
        temp = iter->prev;
        temp->next = iter->next;
        iter->next = temp;
    }
    else {
        iter = l->tail;
        if (index == -1) {
            temp = iter->prev;
            l->tail = temp;
            temp->next = NULL;
            return iter;
        }
        
        count = -1;
        while (count > index) {
            iter = iter->prev;
            count--;
        }
        temp = iter->next;
        temp->prev = iter->prev;
        iter->prev = temp;
        printf("%d %d %d\n", temp->prev->value, iter->value, temp->value);
    }
    l->size = l->size - 1;
    return iter;
}

Node *get_from_list(List *l, int index) {
    assert(l->size > 0);
    
    Node *iter;
    int count;
    if (index >= 0) {
        count = 0;
        iter = l->head;
        while (count < index) {
            iter = iter->next;
            count++;
        }
    }
    else {
        count = -1;
        iter = l->tail;
        while (count > index) {
            iter = iter->prev;
            count--;
        }
    }
    return iter;
}

void delete_list(List *l) {
    Node *iter = l->head;
    while (iter != NULL) {

        iter = iter->next;
    }

    free(l);
}