#include "hashmap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    size_t i;
    int key, value;
    hash_map *map;

    srand(time(NULL));
    map = create_map(10);
    for (i = 0 ; i <= 100 ; ++i) {
        key = rand() % 1000;
        value = rand () % 1000;
        map_insert(map, key, value);
    }
    display_map(map);
    printf("Contains key 2?\t\t%s\n", map_contains_key(map, 2) ? "YES" : "NO");
    printf("Contains key 3?\t\t%s\n", map_contains_key(map, 3) ? "YES" : "NO");

    for (i = 5 ; i <= 20 ; i += 5) {
        map_expand_bins(map, i);
        display_map(map);
    }
    map_remove(map, 2);
    display_map(map);
    dispose_map(map);

    return 0;
}
