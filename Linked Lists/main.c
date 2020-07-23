#include <stdio.h>
#include "node.h"
#include "list.h"

int main(void) {
    int example[] = {1,2,3,4,5};

    List *l = create_list();
    for (int i=0; i<sizeof(example)/sizeof(example[0]); i++) {
        append_to_list(l, example[i]);
    }
    
    printf("popped: %d\n", pop_from_list(l, -3)->value);
    Node *iter = l->head;
    while (iter != NULL) {
        printf("x: %d\n", iter->value);
        iter = iter->next;
    }
    return 0;
}


