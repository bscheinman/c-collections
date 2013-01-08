#include "../queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    linked_list *list = list_init();
    void *val;
    
    printf("pushing \"foo\", \"bar\", \"baz\", and \"asdf\" into a queue\n");
    queue_push(list, (void *)"foo");
    queue_push(list, (void *)"bar");
    queue_push(list, (void *)"baz");
    queue_push(list, (void *)"asdf");
    list_print(list);
    printf("popping from queue: ");
    val = queue_pop(list);
    printf("%s\n", (char *)val);
    list_print(list);
    printf("popping from queue: ");
    val = queue_pop(list);
    printf("%s\n", (char *)val);
    list_print(list);

    printf("clearing list\n");
    list_clear(list);
    list_print(list);

    printf("pushing \"abc\", \"123\", and \"qwerty\" onto the stack\n");
    stack_push(list, (void *)"abc");
    stack_push(list, (void *)"123");
    stack_push(list, (void *)"qwerty");
    list_print(list);
    printf("popping from stack: ");
    val = stack_pop(list);
    printf("%s\n", (char *)val);
    list_print(list);
    printf("popping from stack: ");
    val = stack_pop(list);
    printf("%s\n", (char *)val);
    list_print(list);

    list_dispose(list);
    return 0;
}
