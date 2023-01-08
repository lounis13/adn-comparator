#ifndef ADN_COMPARATOR_DOUBLE_HASH_MAP_H
#define ADN_COMPARATOR_DOUBLE_HASH_MAP_H

#include "sorted_linked_list.h"

typedef struct DOUBLE_HASH_MAP {
    int capacity;
    SORTED_LINKED_LIST *keys_values;

    int (*hash)(const void *);
} DOUBLE_HASH_MAP;

DOUBLE_HASH_MAP double_hash_map_init(int capacity, int (*hash)(const void *));

int put(DOUBLE_HASH_MAP map, void *key, const void *first, const void *second);

const void *double_hash_map_most_occurrence(DOUBLE_HASH_MAP map, void *key);

SORTED_LINKED_LIST get(DOUBLE_HASH_MAP map, void *key);


#endif //ADN_COMPARATOR_DOUBLE_HASH_MAP_H
