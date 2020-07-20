#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "node.h"
#include "stack.h"


void push_stack_test(struct Stack *s, int n);
void pop_stack_test(struct Stack *s, int pops);
void print_stack_contents(struct Stack *s);

int main(void) {
    struct Stack *s = create_stack();

    int num_to_generate = rand()%6+5; // between 5 and 10 randomly generated numbers
    srand(time(NULL));
    // test the stack's pushing feature
    push_stack_test(s, num_to_generate);
    print_stack_contents(s);

    // test the stack's popping feature
    pop_stack_test(s, rand()%(num_to_generate-2)+1); //between 1 and n-1 pops
    print_stack_contents(s);

    return 0;
}


void push_stack_test(struct Stack *s, int n) {
    printf("TESTING PUSH FUNCTIONALITY FOR %d ITEMS!\n", n);
    for (int i=0; i<n; i++) {
        push_to_stack(s, rand()%100);
    }
}


void pop_stack_test(struct Stack *s, int pops) {
    printf("\nTESTING POPPING FUNCTIONALITY FOR %d ITEMS!\n", pops);
    for (int i=0; i<pops; i++) {
        pop_from_stack(s);
    }
}


void print_stack_contents(struct Stack *s) {
    struct Node *iter = s->head;
    while (iter != NULL) {
        printf("value: %d\n", iter->value);
        iter = iter->next;
    }
}