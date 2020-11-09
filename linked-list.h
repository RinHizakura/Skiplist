#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stdbool.h>

typedef struct __node {
    int value;
    struct __node *next;
} node_t;

void add_entry(node_t **head, int new_value);
bool find_entry(node_t *head, int value);
bool erase_entry(node_t **head, int value);
void delete_list(node_t **head);
void print_list(node_t *head);
#endif
