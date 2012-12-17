#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    size_t count;
    size_t capacity;
    void **items;
} vector;

vector *create_vector(size_t capacity);
void vector_dispose(vector *v);
bool vector_append(vector *v, void *item);
bool vector_insert(vector *v, void *item, size_t position);
void vector_remove(vector *v, size_t position);
void vector_replace(vector *v, void *item, size_t position);
bool vector_expand(vector *v, size_t size);
#define vector_pack(v) vector_expand(v, v->count)
void *vector_nth(const vector *v, size_t n);
void vector_clear(vector *v);
void vector_display(const vector *v);

#endif /* #ifndef VECTOR_H */
