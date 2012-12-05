#include <stddef.h>

typedef struct list_item {
    void *val;
    struct list_item *next;
} list_item;

typedef struct {
    list_item *head;
    list_item *tail;
} linked_list;


void list_initialize(linked_list *list);
void list_dispose(linked_list *list);
void list_print(linked_list *list);
void list_clear(linked_list *list);
void queue_push(linked_list *list, void* item);
void *queue_pop(linked_list *list);
void stack_push(linked_list *list, void *item);
void *stack_pop(linked_list *list);
