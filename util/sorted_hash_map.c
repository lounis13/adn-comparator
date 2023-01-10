#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "sorted_hash_map.h"


SORTED_HASH_MAP *sorted_hash_map_init(int capacity, int (*hash)(const void *)) {
    SORTED_LINKED_LIST *kvs = malloc(sizeof(SORTED_LINKED_LIST) * (capacity + 1));
    if (kvs == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i <= capacity; ++i) {
        kvs[i] = sorted_linked_list_init();
    }
    SORTED_HASH_MAP *map = malloc(sizeof(SORTED_HASH_MAP));
    map->capacity = capacity;
    map->keys_values = kvs;
    map->hash = hash;
    return map;
}

void sorted_hash_map_free(SORTED_HASH_MAP *map) {
    for (int i = 0; i < map->capacity; ++i) {
        sorted_linked_list_free(map->keys_values[i]);
    }
    free(map->keys_values);
    free(map);
}


int put(SORTED_HASH_MAP *map, void *key, const OCCURRENCE_VALUE *item) {
    int index = map->hash(key);
    if (index >= map->capacity || index < 0) return false;
    map->keys_values[index] = sorted_linked_list_add(map->keys_values[index], item);
    return true;
}


SORTED_LINKED_LIST get(SORTED_HASH_MAP *map, void *key) {
    int index = map->hash(key);
    return map->keys_values[index];
}

void sorted_hash_map_print(SORTED_HASH_MAP *map) {
    for (int i = 0; i < map->capacity; ++i) {
        sorted_linked_list_print(map->keys_values[i]);
        puts("________________________________");
    }
}


