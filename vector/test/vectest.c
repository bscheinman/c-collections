#include "../vector.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    vector *v = vector_init(2);
    vector_display(v);
    printf("appending foo, bar, and baz\n");
    vector_append(v, "foo");
    vector_append(v, "bar");
    vector_append(v, "baz");
    vector_display(v);
    printf("inserting blah at position 1\n");
    vector_insert(v, "blah", 1);
    vector_display(v);
    printf("replacing position 3 with asdf\n");
    vector_replace(v, "asdf", 3);
    vector_display(v);
    printf("removing from position 1\n");
    vector_remove(v, 1);
    vector_display(v);
    printf("removing from position 2\n");
    vector_remove(v, 2);
    vector_display(v);
    printf("clearing vector\n");
    vector_clear(v);
    vector_display(v);

    vector_dispose(v);
    return 0;
}
