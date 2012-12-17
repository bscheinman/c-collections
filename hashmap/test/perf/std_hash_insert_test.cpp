#include <unordered_map>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv) {
    int key, value;
    int i;

    if (argc < 3) {
        cout << "you must specify a capacity for the map and a number of elements to insert\n";
        return 1;
    }

    int capacity = atoi(argv[1]);
    int element_count = atoi(argv[2]);

    if (!(capacity && element_count)) {
        cout << "you must specify positive integer values for capacity and element count\n";
        return 2;
    }

    /* don't seed rand because we want consistent results
    srand(time(NULL)); */

    unordered_map<int, int> map;
    map.rehash(capacity);
    for (i = 0 ; i < element_count ; ++i) {
        key = rand();
        value = rand();
        map[key] = value;
    }

    return 0;
}
