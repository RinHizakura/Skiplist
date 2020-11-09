#ifndef _SKIPLIST_H
#define _SKIPLIST_H

#define MAX_HEIGHT 8
#include <stdbool.h>
#include <stdint.h>

typedef struct __list_node {
    uint8_t height;
    int val;
    int ref;
    struct __list_node *next[1];
} list_node_t;


typedef struct {
    uint8_t height;
    list_node_t *head;
} Skiplist;

Skiplist *skiplistCreate();
int _skiplistSearch(Skiplist *obj, int target, list_node_t **u);
bool skiplistSearch(Skiplist *obj, int target);
void skiplistAdd(Skiplist *obj, int num);
bool skiplistErase(Skiplist *obj, int num);
void skiplistFree(Skiplist *obj);

#endif
