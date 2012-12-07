#include "hashmap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void search_for_key(const hash_map *map, const void *key) {
    const void *value;
    if (map_get_value(map, key, &value)) {
        printf("Did not find value for key %i", key);
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
        key = (void *) (rand() % 1000);
        value = (void *) (rand () % 1000);
        map_insert(map, (void *) key, (void *) value);
    }
    display_map(map);

    /*for (i = 5 ; i <= 20 ; i += 5) {
        map_expand_bins(map, i);
        display_map(map);
    }*/
    display_map(map);
    dispose_map(map);

    return 0;
}
