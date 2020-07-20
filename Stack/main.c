#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "node.h"
#include "stack.h"


void push_stack_test(int n);
void pop_stack_test(int pops);
void check_balanced_parantheses(char *parantheses);
void print_stack_contents(struct Stack *s);

int main(void) {
    int num_to_generate = rand()%6+5; // between 5 and 10 randomly generated numbers
    srand(time(NULL));
    // test the stack's pushing feature
    // push_stack_test(s, num_to_generate);

    // test the stack's popping feature
    // pop_stack_test(s, rand()%(num_to_generate-2)+1); //between 1 and n-1 pops

    // test with a LeetCode problem
    check_balanced_parantheses("(())()");

    return 0;
}


void push_stack_test(int n) {
    printf("\nTESTING PUSH FUNCTIONALITY FOR %d ITEMS!\n", n);
    struct Stack *s = create_stack();
    for (int i=0; i<n; i++) {
        push_to_stack(s, rand()%100);
    }
    print_stack_contents(s);
    delete_stack(s);
}


void pop_stack_test(int pops) {
    printf("\nTESTING POPPING FUNCTIONALITY FOR %d ITEMS!\n", pops);
    struct Stack *s = create_stack();
    for (int i=0; i<pops; i++) {
        pop_from_stack(s);
    }
    print_stack_contents(s);
    delete_stack(s);
}


void check_balanced_parantheses(char *parantheses) {
    printf("\nTESTING BALANCED PARANTHESES PROBLEM!\nINPUT:%s\n\n", parantheses);
    struct Stack *s = create_stack();
    int n = strlen(parantheses);
    int balanced = 1;
    for (int i=0; i<n; i++) {
        if (parantheses[i] == ')') {
            if (is_empty(s)) {
                balanced = 0;
                break;
            }
            pop_from_stack(s);
        }
        else {
            push_to_stack(s, parantheses[i]);
        }
    }
    if (!(is_empty(s) && balanced)) {
        printf("The parantheses ARE NOT balanced!\n");
    }
    else {
        printf("The parantheses ARE balanced!\n");
    }
    delete_stack(s);
}


void print_stack_contents(struct Stack *s) {
    struct Node *iter = s->head;
    while (iter != NULL) {
        printf("value: %d\n", iter->value);
        iter = iter->next;
    }
}