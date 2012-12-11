#include "hashmap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    hash_map *map = typed_map(str, str, 10);
    const void *value;
    char *s;
    map_insert(map, "foo", "abc");
    map_insert(map, "bar", "def");

    s = malloc(4 * sizeof(char));
    strncpy(s, "foo", 4);
    map_get_value(map, s, &value);
    printf("%s\n", (const char*) value);

    display_map(map);
    dispose_map(map);
    free(s);
    return 0;
}
