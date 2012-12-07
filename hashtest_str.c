#include "hashmap.h"
#include <stdio.h>


int main() {
    hash_map *map = str_map(10);
    const void *value;
    char *s;
    map_insert(map, "foo", 123);
    map_insert(map, "bar", 456);

    s = malloc(4 * sizeof(char));
    strncpy(s, "foo", 4);
    map_get_value(map, s, &value);
    printf("%i", value);

    display_map(map);
}
