#include "vector.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vector_initialize(vector *v, size_t capacity) {
    assert(v);
    v->count = 0;
    v->capacity = capacity;
    v->items = malloc(capacity * sizeof(void *));
}


void vector_dispose(vector *v) {
    void *item;
    int index;
    assert(v);
    for (index = 0 ; index < v->count ; ++index) {
        item = vector_nth(v, index);
        free(item);
    }
    vector_clear(v);
}


void vector_append(vector *v, void *item) {
    assert(v);
    if (v->count == v->capacity) {
        vector_expand(v, v->capacity * 2);
    }
    v->items[v->count++] = item;
}


void vector_expand(vector *v, size_t size) {
    assert(v);
    if (size <= v->count) {
        return;
    }
    v->items = realloc(v->items, size);
    v->capacity = size;
}


void *vector_nth(vector *v, size_t n) {
    assert(v && n < v->count);
    return v->items[n];
}


void vector_clear(vector *v) {
    assert(v);
    memset(v->items, 0, v->count);
    v->count = 0;
}


void vector_insert(vector *v, void *item, size_t position) {
    size_t copy_size;
    assert(v && position <= v->count);
    if (v->count == v->capacity) {
        vector_expand(v, (v->capacity * 3) / 2);
    }
    if (position < v->count) {
        copy_size = (v->count - position) * sizeof(void *);
        memcpy(v->items + position + 1, v->items + position, copy_size);
        ++v->count;
    }
    v->items[position] = item;
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
