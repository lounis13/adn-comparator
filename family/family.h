#ifndef ADN_COMPARATOR_FAMILY_H
#define ADN_COMPARATOR_FAMILY_H

#include "../sequence/sequence.h"
#include "../sequence/distance.h"


typedef struct FAMILY_MEMBER {
    int id;
    SEQUENCE sequence;
    struct FAMILY *family;
} FAMILY_MEMBER;

typedef struct FAMILY {
    FAMILY_MEMBER *family_member;
    struct FAMILY *next;
} *FAMILY;

typedef struct FAMILY_NODE {
    FAMILY family;
    struct FAMILY_NODE *next;
} *FAMILY_LIST, *FAMILY_NODE;

FAMILY_MEMBER *create_family_members(DISTANCE *);

FAMILY_LIST family_list_create(DISTANCE *distance, FAMILY_MEMBER *family_members);

void family_list_print(FAMILY_LIST families);

void family_list_free(FAMILY_LIST families);

#endif //ADN_COMPARATOR_FAMILY_H
