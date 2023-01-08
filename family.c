#include <stdlib.h>

#include "family.h"
#include "distance.h"
#include "double_hash_map.h"

FAMILY_MEMBER *create_family_members(DISTANCE *);

FAMILY_LIST families_create(DISTANCE *, const FAMILY_MEMBER *, DOUBLE_HASH_MAP *);

FAMILY_LIST family_list_add(FAMILY_LIST, FAMILY);

FAMILY family_create(const DISTANCE *, const FAMILY_MEMBER *, double, FAMILY_MEMBER *);

FAMILY family_attach(FAMILY, FAMILY_MEMBER *);

DOUBLE_HASH_MAP create_dmin_double_hash_map(DISTANCE, FAMILY_MEMBER *);


FAMILY_LIST family_list_create(DISTANCE distance) {
    FAMILY_MEMBER *family_members = create_family_members(&distance);
    DOUBLE_HASH_MAP map = create_dmin_double_hash_map(distance, family_members);
    return families_create(&distance, family_members, &map);
}

int distance_hash(const double *distance) {
    return (int) (*distance * 2);
}

double reverse_hash(const int index) {
    return (double) index / 2.0;
}

FAMILY_LIST families_create(DISTANCE *distance, const FAMILY_MEMBER *family_members, DOUBLE_HASH_MAP *map) {
    FAMILY_LIST families = NULL;
    for (int i = 0; i < (int) ((*distance).max_distance * 2); ++i) {
        double current_dmin = reverse_hash(i);
        SORTED_LINKED_LIST occurrence_list = get((*map), &current_dmin);
        while (!is_empty(occurrence_list)) {
            FAMILY_MEMBER *member = (FAMILY_MEMBER *) occurrence_list->item.value;
            if (member == NULL || member->family) {
                occurrence_list = next(occurrence_list);
                continue;
            }
            FAMILY new_family = family_create(distance, family_members, current_dmin, member);
            occurrence_list = next(occurrence_list);
            families = family_list_add(families, new_family);
        }
    }
    return families;
}

FAMILY family_create(const DISTANCE *distance, const FAMILY_MEMBER *family_members, double current_dmin, FAMILY_MEMBER *member) {
    FAMILY new_family = malloc(sizeof(struct FAMILY));
    new_family->next = NULL;
    new_family->family_member = member;
    member->family = new_family;
    for (int j = 0; j < (*distance).size; ++j) {
        FAMILY_MEMBER new_member = family_members[j];
        if (new_member.family) continue;
        if ((*distance).distances[j][member->id] == current_dmin) {
            new_family = family_attach(new_family, &new_member);
        }
    }
    return new_family;
}

FAMILY family_attach(FAMILY family, FAMILY_MEMBER *new_member) {
    FAMILY new_family_member = malloc(sizeof(struct FAMILY));
    new_family_member->family_member = new_member;
    new_family_member->next = family;
    family = new_family_member;
    (*new_member).family = family;
    return family;
}

FAMILY_LIST family_list_add(FAMILY_LIST families, FAMILY new_family) {
    FAMILY_LIST node = malloc(sizeof(struct FAMILY_NODE));
    node->family = new_family;
    node->next = families;
    return node;
}

FAMILY_MEMBER *create_family_members(DISTANCE *distance) {
    FAMILY_MEMBER *family_members = malloc((*distance).size);
    for (int i = 0; i < (*distance).size; ++i) {
        family_members[i].id = i;
        family_members[i].sequence = (*distance).sequences[i];
        family_members[i].family = NULL;
    }
    return family_members;
}

DOUBLE_HASH_MAP create_dmin_double_hash_map(DISTANCE distance, FAMILY_MEMBER *family_members) {
    DOUBLE_HASH_MAP map = double_hash_map_init((int)(distance.max_distance * 2), (int (*)(const void *)) distance_hash);
    for (int i = 0; i < distance.size; ++i) {
        for (int j = 0; j < i; ++j) {
            double d = distance_get_distance(distance, i, j);
            FAMILY_MEMBER first = family_members[i];
            FAMILY_MEMBER second = family_members[j];
            put(map, &d, &first, &second);
        }
    }
    return map;
}
