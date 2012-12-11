#include "hashmap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    size_t i;
    int key, value;
    hash_map *map;

    srand(time(NULL));
    map = int_map(10);
    for (i = 0 ; i <= 100 ; ++i) {
        key = rand() % 100;
        value =  rand () % 100;
        map_insert(map, &key, &value);
    }
    display_map(map);
    dispose_map(map);

    return 0;
}
