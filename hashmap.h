#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    int key;
    int value;
} kv_pair;

typedef struct entry {
    kv_pair pair;
    struct entry *next;
} map_entry;

typedef struct {
    map_entry** entries;
    size_t bin_count;
    size_t item_count;
} hash_map;


int get_hash(const hash_map *map, int value);
hash_map *create_map(size_t initial_capacity);
void dispose_map(hash_map *map);
map_entry *create_entry(int key, int value);
bool map_expand_bins(hash_map *map, size_t nbins);

bool map_insert(hash_map *map, int key, int value);
bool map_remove(hash_map *map, int key);
bool map_get_value(const hash_map *map, int key, int *output);
#define map_contains_key(map, key) map_get_value(map, key, NULL)
void display_map(const hash_map *map);
void display_entry(const map_entry *entry);

#endif /* #ifndef HASHMAP_H */
