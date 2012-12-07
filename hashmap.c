#include "hashmap.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


size_t int_hash(const void *key) {
    return (size_t) key;
}


size_t str_hash(const void *key) {
    size_t hash = 0;
    const char *str = (const char *) key;
    if (!str) {
        return 0;
    }
    while (*str != '\0') {
        hash += *str;
        hash *= 31;
        ++str;
    }
    return hash;
}


bool int_compare(const void *k1, const void *k2) {
    return k1 == k2;
}


bool str_compare(const void *k1, const void *k2) {
    return strcmp(k1, k2) == 0;
}


size_t get_hash(const hash_map *map, const void *value) {
    assert(map);
    return map->hash_fxn(value) % map->bin_count;
}


hash_map *create_map(size_t initial_capacity, hash_function hash_fxn, compare_function compare_fxn) {
    hash_map *map;
    assert(initial_capacity && hash_fxn && compare_fxn);
    map = malloc(sizeof(hash_map));
    if (map) {
        map->entries = calloc(initial_capacity, sizeof(map_entry *));
        if (!map->entries) {
            free(map);
            return NULL;
        }
        map->bin_count = initial_capacity;
        map->item_count = 0;
        map->hash_fxn = hash_fxn;
        map->compare_fxn = compare_fxn;
    }
    return map;
}


void dispose_map(hash_map *map) {
    map_entry *entry, *last_entry;
    size_t i;
    assert(map);
    for (i = 0 ; i < map->bin_count ; ++i) {
        entry = map->entries[i];
        while (entry) {
            last_entry = entry;
            entry = entry->next;
            free(last_entry);
        }
    }
    free(map);
}


map_entry *create_entry(const void *key, const void *value) {
    map_entry *entry = malloc(sizeof(map_entry));
    if (entry) {
        entry->pair.key = key;
        entry->pair.value = value;
    }
    return entry;
}


bool map_expand_bins(hash_map *map, size_t nbins) {
    map_entry *entry, **old_entries;
    size_t i;
    size_t old_bin_count;
    bool success = true;
    assert(map && nbins);
    old_entries = map->entries;
    old_bin_count = map->bin_count;
    map->entries = calloc(nbins, sizeof(map_entry *));
    map->bin_count = nbins;
    if (!map->entries) {
        success = false;
        goto expansion_finished;
    }
    for (i = 0 ; i < old_bin_count ; ++i) {
        entry = old_entries[i];
        while (entry) {
            if (!map_insert(map, entry->pair.key, entry->pair.value)) {
                success = false;
                goto expansion_finished;
            }
            entry = entry->next;
        }
    }
expansion_finished:
    if (!success) {
        map->entries = old_entries;
        map->bin_count = old_bin_count;
    }
    return success;
}


bool map_insert(hash_map *map, const void *key, const void *value) {
    size_t hash_index;
    map_entry *new_entry, *parent_entry;
    bool success = false;
    assert(map);
    hash_index = get_hash(map, key);

    new_entry = create_entry(key, value);
    if (!new_entry) {
        return false;
    }

    parent_entry = map->entries[hash_index];
    if (parent_entry) {
        if (map->compare_fxn(parent_entry->pair.key, key)) {
            success = false;
            goto insert_finished;
        }
        while (parent_entry->next) {
            parent_entry = parent_entry->next;
            if (map->compare_fxn(parent_entry->pair.key, key)) {
                success = false;
                goto insert_finished;
            }
        }
        parent_entry->next = new_entry;
        success = true;
    } else {
        map->entries[hash_index] = new_entry;
        success = true;
    }
insert_finished:
    if (success) {
        ++map->item_count;
    } else {
        free(new_entry);
    }
    return success;
}


bool map_remove(hash_map *map, const void *key) {
    map_entry *entry, *parent_entry;
    size_t hash_index;
    assert(map);
    hash_index = get_hash(map, key);
    entry = map->entries[hash_index];
    parent_entry = NULL;
    while (entry) {
        if (map->compare_fxn(entry->pair.key, key)) {
            if (parent_entry) {
                parent_entry->next = entry->next;
            } else if (entry-> next) {
                map->entries[hash_index] = entry->next;
            } else {
                map->entries[hash_index] = NULL;
            }
            free(entry);
            --map->item_count;
            return true;
        }
        parent_entry = entry;
        entry = entry->next;
    }
    return false;
}


bool map_get_value(const hash_map *map, const void *key, const void **output) {
    map_entry *entry;
    size_t hash_index;
    assert(map);
    hash_index = get_hash(map, key);
    entry = map->entries[hash_index];
    while (entry) {
        if (map->compare_fxn(entry->pair.key, key)) {
            if (output) {
                *output = entry->pair.value;
            }
            return true;
        }
        entry = entry->next;
    }
    return false;
}


void display_map(const hash_map *map) {
    map_entry *entry;
    size_t i;
    assert(map);
    
    for (i = 0 ; i < map->bin_count ; ++i) {
        entry = map->entries[i];
        printf("Bin %i:\n", i);
        if (!entry) {
            printf("\t<EMPTY>\n");
        }
        while (entry) {
            printf("\t");
            display_entry(entry);
            printf("\n");
            entry = entry->next;
        }
    }
}


void display_entry(const map_entry *entry) {
    assert(entry);
    printf("%i: %i", entry->pair.key, entry->pair.value);
}
