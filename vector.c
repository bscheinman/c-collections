#include "vector.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

vector *create_vector(size_t capacity) {
    vector *v = malloc(sizeof(vector));
    if (v) {
        v->count = 0;
        v->capacity = capacity;
        v->items = malloc(capacity * sizeof(void *));
        if (!v->items) {
            free(v);
        }
    }
    return v;
}


bool vector_append(vector *v, void *item) {
    assert(v);
    if (v->count == v->capacity && !vector_expand(v, v->capacity * 2)) {
        return false;
    }
    v->items[v->count++] = item;
    return true;
}


bool vector_expand(vector *v, size_t size) {
    void **old_items;
    assert(v);
    old_items = v->items;
    v->items = realloc(v->items, size * sizeof(void *));
    if (v->items) {
        v->capacity = size;
        return true;
    } else {
        v->items = old_items;
        return false;
    }
}


void *vector_nth(vector *v, size_t n) {
    assert(v && n < v->count);
    return v->items[n];
}


void vector_clear(vector *v) {
    assert(v);
    v->count = 0;
}


bool vector_insert(vector *v, void *item, size_t position) {
    size_t copy_size;
    assert(v && position <= v->count);
    if (v->count == v->capacity && !vector_expand(v, v->capacity * 2)) {
        return false;
    }
    if (position < v->count) {
        copy_size = (v->count - position) * sizeof(void *);
        memcpy(v->items + position + 1, v->items + position, copy_size);
        ++v->count;
    }
    v->items[position] = item;
    return true;
}


void vector_remove(vector *v, size_t position) {
    size_t copy_size;
    assert(v && position < v->count);
    copy_size = (v->count - (position + 1)) * sizeof(void *);
    if (copy_size > 0) {
        memcpy(v->items + position, v->items + position + 1, copy_size);
    }
    v->items[--v->count] = NULL;
}


void vector_replace(vector *v, void *item, size_t position) {
    assert(v && position < v->count);
    v->items[position] = item;
}

void vector_display(vector *v) {
    size_t index;
    assert(v);
    printf("%d items:\n", (int)v->count);
    for (index = 0 ; index < v->count ; ++index) {
        printf("\t%s\n", (char *)vector_nth(v, index));
    }
}
