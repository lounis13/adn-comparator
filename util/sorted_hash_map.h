#ifndef ADN_COMPARATOR_SORTED_HASH_MAP_H
#define ADN_COMPARATOR_SORTED_HASH_MAP_H

#include "sorted_linked_list.h"

typedef struct SORTED_HASH_MAP {
    int capacity;
    SORTED_LINKED_LIST *keys_values;

    int (*hash)(const void *);
} SORTED_HASH_MAP;

SORTED_HASH_MAP *sorted_hash_map_init(int capacity, int (*hash)(const void *));

void sorted_hash_map_free(SORTED_HASH_MAP *map);

void sorted_hash_map_print(SORTED_HASH_MAP *map);

int put(SORTED_HASH_MAP *map, void *key, const OCCURRENCE_VALUE *occ_value);

SORTED_LINKED_LIST get(SORTED_HASH_MAP *map, void *key);


#endif //ADN_COMPARATOR_SORTED_HASH_MAP_H
