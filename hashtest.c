#include "hashmap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void search_for_key(const hash_map *map, const void *key) {
    const void *value;
    if (map_get_value(map, key, &value)) {
        printf("Did not find value for key %p", key);
    } else {

    }
}


int main() {
    size_t i;
    void *key, *value;
    hash_map *map;

    srand(time(NULL));
    map = int_map(10);
    for (i = 0 ; i <= 100 ; ++i) {
        key = (void *) (rand() % 100);
        value = (void *) (rand () % 100);
        map_insert(map, key, value);
    }
    display_map(map);
    dispose_map(map);

    return 0;
}
