#include <stdio.h>
#include <stdlib.h>

#include "sorted_linked_list.h"
#include "../family/family.h"

SORTED_LINKED_LIST sorted_linked_list_node(const OCCURRENCE_VALUE *occurrence_value);

SORTED_LINKED_LIST sorted_linked_list_init() {
    return NULL;
}

void sorted_linked_list_free(SORTED_LINKED_LIST list) {
    while (list) {
        SORTED_LINKED_LIST node = list;
        list = next(list);
        free(node);
    }
}

SORTED_LINKED_LIST sorted_linked_list_add(SORTED_LINKED_LIST list, const OCCURRENCE_VALUE *occ_value) {
    SORTED_LINKED_LIST new = sorted_linked_list_node(occ_value);
    if (is_empty(list)) {
        return new;
    }
    SORTED_LINKED_LIST temp = list;
    while (temp->next && temp->item->occurrence > occ_value->occurrence) {
        temp = temp->next;
    }
    if (temp->item->occurrence >= occ_value->occurrence) {
        temp->next = new;
        new->pred = temp;
        return list;
    }
    if (temp->pred == NULL) {
        list = new;
    } else {
        new->pred = temp->pred;
    }
    temp->pred = new;
    new->next = temp;


    return list;
}

int is_empty(SORTED_LINKED_LIST list) {
    return !list;
}

SORTED_LINKED_LIST next(SORTED_LINKED_LIST list) {
    return list->next;
}

SORTED_LINKED_LIST sorted_linked_list_node(const OCCURRENCE_VALUE *occurrence_value) {
    SORTED_LINKED_LIST new = malloc(sizeof(struct SORTED_LINKED_LIST));
    if (!new) {
        perror("error sorted_linked_list_node malloc");
        exit(EXIT_FAILURE);
    }
    new->item = occurrence_value;
    new->next = NULL;
    new->pred = NULL;
    return new;
}

void sorted_linked_list_print(SORTED_LINKED_LIST list) {
    SORTED_LINKED_LIST node = list;
    while (node) {
        printf(" (%d, %d) ->", ((FAMILY_MEMBER *) node->item->value)->id, node->item->occurrence);
        node = node->next;
    }
    printf(" NULL\n");
}
