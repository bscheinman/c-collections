#include <stddef.h>

typedef struct {
    size_t count;
    size_t capacity;
    void **items;
} vector;

void vector_initialize(vector *v, size_t capacity);
void vector_dispose(vector *v);
void vector_append(vector *v, void *item);
void vector_insert(vector *v, void *item, size_t position);
void vector_remove(vector *v, size_t position);
void vector_replace(vector *v, void *item, size_t position);
void vector_expand(vector *v, size_t size);
void *vector_nth(vector *v, size_t n);
void vector_clear(vector *v);
void vector_display(vector *v);
