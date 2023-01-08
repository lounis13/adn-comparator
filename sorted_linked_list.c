#include <stdio.h>
#include <stdlib.h>

#include "sorted_linked_list.h"

SORTED_LINKED_LIST sorted_linked_list_organize_update(SORTED_LINKED_LIST list, SORTED_LINKED_LIST updated);

SORTED_LINKED_LIST sorted_linked_list_node(const void *value);

SORTED_LINKED_LIST sorted_linked_list_init() {
    return NULL;
}

SORTED_LINKED_LIST sorted_linked_list_add(SORTED_LINKED_LIST list, const void *value) {
    SORTED_LINKED_LIST temp = list;
    while (temp && temp->next && temp->item.value != value) {
        temp = temp->next;
    }

    if (temp && temp->item.value == value) {
        temp->item.occurrence++;
        return sorted_linked_list_organize_update(list, temp);
    }
    SORTED_LINKED_LIST new = sorted_linked_list_node(value);
    if (!temp) return new;
    temp->next = new;
    return list;
}

int is_empty(SORTED_LINKED_LIST list) {
    return !list;
}

SORTED_LINKED_LIST next(SORTED_LINKED_LIST list) {
    return list->next;
}

SORTED_LINKED_LIST sorted_linked_list_node(const void *value) {
    SORTED_LINKED_LIST new = malloc(sizeof(struct SORTED_LINKED_LIST));
    if(!new) {
        perror("error sorted_linked_list_node malloc");
        exit(EXIT_FAILURE);
    }
    new->item.value = value;
    new->item.occurrence = 0;
    new->next = NULL;
    return new;
}

SORTED_LINKED_LIST sorted_linked_list_organize_update(SORTED_LINKED_LIST list, SORTED_LINKED_LIST updated) {
    SORTED_LINKED_LIST updated_item = updated;
    updated = updated->pred;
    while (updated) {
        if (updated->item.occurrence < updated_item->item.occurrence) {
            OCCURRENCE_VALUE temp_item = updated->item;
            updated->item = updated_item->item;
            updated_item->item = temp_item;
            updated_item = updated;
            updated = updated->pred;
            continue;
        }
        break;
    }
    return list;
}