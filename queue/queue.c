#include "queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

linked_list *list_init(void) {
    linked_list *list = malloc(sizeof(linked_list));
    if (!list) return NULL;
    list->head = NULL;
    list->tail = NULL;
    return list;
}


void list_dispose(linked_list *list) {
    list_item *item;
    list_item *old_item;
    assert(list);
    item = list->head;
    while (item) {
        old_item = item;
        item = item->next;
        free(old_item);
    }
    free(list);
}


list_item *create_item(void) {
    list_item *item = malloc(sizeof(list_item));
    if (item) {
        item->val = NULL;
        item->next = NULL;
    }
    return item;
}


void list_print(linked_list *list) {
    list_item *item;
    assert(list);
    item = list->head;
    printf("List contents:\n");
    while (item) {
        printf("%s\n", (char *)item->val);
        item = item->next;
    }
    printf("\n");
}


void list_clear(linked_list *list) {
    list_item *item;
    list_item *old_item;
    assert(list);
    item = list->head;
    while (item) {
        old_item = item;
        item = item->next;
        free(old_item);
    }
    list->head = NULL;
    list->tail = NULL;
}


bool list_empty(linked_list *list)
    { return list->head == NULL; }


void queue_push(linked_list *list, void *val) {
    list_item *item;
    assert(list);
    item = create_item();
    item->val = val;
    if (list->tail) {
        list->tail->next = item;
        list->tail = item;
    } else {
        list->head = item;
        list->tail = item;
    }
}


void *queue_pop(linked_list *list) {
    assert(list);
    if (list->head) {
        list_item *item = list->head;
        void *val = item->val;
        list->head = item->next;
        if (NULL == list->head) {
            list->tail = NULL;
        }
        free(item);
        return val;
    } else {
        return NULL;
    }
}


void stack_push(linked_list *list, void *val) {
    list_item *item;
    assert(list);
    item = create_item();
    item->val = val;
    item->next = list->head;
    list->head = item;
}


void *stack_pop(linked_list *list) {
    list_item *item;
    assert(list);
    item = list->head;
    if (item) {
        void *val = item->val;
        list->head = item->next;
        if (NULL == list->head) {
            list->tail = NULL;
        }
        free(item);
        return val;
    } else {
        return NULL;
    }
}
