#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "double_hash_map.h"


DOUBLE_HASH_MAP double_hash_map_init(int capacity, int (*hash)(const void *)) {
    SORTED_LINKED_LIST *kvs = malloc(sizeof(SORTED_LINKED_LIST) * capacity);
    if (kvs == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < capacity; ++i) {
        kvs[i] = sorted_linked_list_init();
    }
    return (DOUBLE_HASH_MAP) {capacity, kvs, hash};
}

int put(DOUBLE_HASH_MAP map, void *key, const void *first, const void *second) {
    int index = map.hash(key);
    if (index >= map.capacity || index < 0) return false;
    map.keys_values[index] = sorted_linked_list_add(map.keys_values[index], first);
    map.keys_values[index] = sorted_linked_list_add(map.keys_values[index], second);
    return true;
}

SORTED_LINKED_LIST get(DOUBLE_HASH_MAP map, void *key) {
    int index = map.hash(key);
    return map.keys_values[index];
}