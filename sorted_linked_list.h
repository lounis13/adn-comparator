#ifndef ADN_COMPARATOR_SORTED_LINKED_LIST_H
#define ADN_COMPARATOR_SORTED_LINKED_LIST_H

typedef struct OCCURRENCE_VALUE {
    const void *value;
    int occurrence;
} OCCURRENCE_VALUE;

typedef struct SORTED_LINKED_LIST {
    OCCURRENCE_VALUE item;
    struct SORTED_LINKED_LIST *next;
    struct SORTED_LINKED_LIST *pred;
} *SORTED_LINKED_LIST;

int is_empty(SORTED_LINKED_LIST);
SORTED_LINKED_LIST next(SORTED_LINKED_LIST);
SORTED_LINKED_LIST sorted_linked_list_init();
SORTED_LINKED_LIST sorted_linked_list_add(SORTED_LINKED_LIST list, const void *value);

#endif //ADN_COMPARATOR_SORTED_LINKED_LIST_H
