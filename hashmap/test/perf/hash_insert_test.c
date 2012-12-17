#include "../../hashmap.h"
#include <stdlib.h>
#include <stdio.h>
/*#include <time.h>*/

int main(int argc, char **argv) {
    hash_map *map;
    int capacity, element_count;
    size_t i;
    int key, value;

    if (argc < 3) {
        printf("you must specify a capacity for the map and a number of elements to insert\n");
        return 1;
    }

    capacity = atoi(argv[1]);
    element_count = atoi(argv[2]);

    if (!(capacity && element_count)) {
        printf("you must specify positive integer values for capacity and element count\n");
        return 2;
    }

    /* don't seed rand because we want consistent results
    srand(time(NULL)); */

    map = typed_map(int, int, capacity);
    for (i = 0 ; i < element_count ; ++i) {
        key = rand();
        value = rand();
        map_insert(map, &key, &value);
    }

    /*dispose_map(map);*/
    return 0;
}
