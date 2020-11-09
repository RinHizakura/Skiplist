#include "linked-list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void add_entry(node_t **head, int new_value)
{
    node_t **indirect = head;

    node_t *new_node = malloc(sizeof(node_t));
    assert(new_node);
    new_node->value = new_value;
    new_node->next = NULL;

    while (*indirect && (*indirect)->value > new_value) {
        indirect = &(*indirect)->next;
    }

    node_t *cur = (*indirect);
    (*indirect) = new_node;
    new_node->next = cur;
}

bool find_entry(node_t *head, int value)
{
    if (!head)
        return NULL;

    node_t *current = head;
    for (; current && current->value != value; current = current->next)
        /* interate */;

    if (current != NULL)
        return true;

    return false;
}

bool erase_entry(node_t **head, int value)
{
    if (!head)
        return false;

    node_t **indirect = head;

    while ((*indirect) && (*indirect)->value > value)
        indirect = &(*indirect)->next;

    if (!(*indirect))
        return false;

    if ((*indirect)->value == value) {
        node_t *entry = (*indirect);
        *indirect = (*indirect)->next;
        free(entry);
        return true;
    } else {
        return false;
    }
}

void delete_list(node_t **head)
{
    while (*head) {
        node_t *next = (*head)->next;
        free(*head);
        *head = next;
    }
}

void print_list(node_t *head)
{
    for (node_t *current = head; current; current = current->next)
        printf("%d ", current->value);
    printf("\n");
}
