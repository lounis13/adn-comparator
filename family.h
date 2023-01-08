#ifndef ADN_COMPARATOR_FAMILY_H
#define ADN_COMPARATOR_FAMILY_H

#include "sequence.h"
#include "distance.h"


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

FAMILY_LIST family_list_create(DISTANCE distance);
#endif //ADN_COMPARATOR_FAMILY_H
