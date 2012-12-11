#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    void *key;
    void *value;
} kv_pair;

typedef struct entry {
    kv_pair pair;
    struct entry *next;
} map_entry;

typedef size_t (*hash_function)(const void *);
typedef bool (*compare_function)(const void *, const void *);
typedef void *(*copy_function)(const void *);
typedef struct {
    hash_function hash_fxn;
    compare_function compare_fxn;
    copy_function copy_fxn;
    map_entry** entries;
    size_t bin_count;
    size_t item_count;
    bool free_elements;
} hash_map;


size_t int_hash(const void *key);
size_t str_hash(const void *key);

bool int_compare(const void *k1, const void *k2);
bool str_compare(const void *k1, const void *k2);

void *int_copy(const void *x);
void *str_copy(const void *x);

size_t get_hash(const hash_map *map, const void *value);
hash_map *create_map(
    size_t initial_capacity,
    hash_function hash_fxn, 
    compare_function compare_fxn,
    copy_function copy_fxn);
#define int_map(capacity) create_map(capacity, int_hash, int_compare, int_copy)
#define str_map(capacity) create_map(capacity, str_hash, str_compare, str_copy)
map_entry *create_entry(const hash_map *map, const void *key, const void *value);
void dispose_map(hash_map *map);
map_entry *dispose_entry(map_entry *entry);
bool map_expand_bins(hash_map *map, size_t nbins);

bool map_insert(hash_map *map, const void *key, const void *value);
bool map_remove(hash_map *map, const void *key);
bool map_get_value(const hash_map *map, const void *key, const void **output);
#define map_contains_key(map, key) map_get_value(map, key, NULL)
void map_clear(hash_map *map);
void display_map(const hash_map *map);
void display_entry(const map_entry *entry);

#endif /* #ifndef HASHMAP_H */
