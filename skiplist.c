#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "skiplist.h"
Skiplist *skiplistCreate()
{
    Skiplist *l = malloc(sizeof(Skiplist));
    l->height = 0;

    int s = sizeof(list_node_t) + ((sizeof(list_node_t *)) * (MAX_HEIGHT));
    list_node_t *n = malloc(s);
    memset(n, 0, s);
    n->val = -1;

    l->head = n;

    return l;
}

int _skiplistSearch(Skiplist *obj, int target, list_node_t **u)
{
    list_node_t *iterator = obj->head, **ud = u;
    for (int i = obj->height - 1; i >= 0; --i) {
        while (iterator->next[i] && iterator->next[i]->val < target)
            iterator = iterator->next[i];
        if (ud)
            ud[i] = iterator;
    }

    list_node_t *n = iterator->next[0];

    if (!n)
        return -1;

    if (n->val == target) {
        return target;
    }

    return -1;
}


bool skiplistSearch(Skiplist *obj, int target)
{
    if (_skiplistSearch(obj, target, NULL) >= 0)
        return true;

    return false;
}

void skiplistAdd(Skiplist *obj, int num)
{
    list_node_t *u[MAX_HEIGHT];
    int search = _skiplistSearch(obj, num, u);

    if (search != -1) {
        u[0]->next[0]->ref++;
        return;
    }

    // random height
    int h = random() % (MAX_HEIGHT) + 1;

    if (h > obj->height) {
        h = ++(obj->height);
        u[h - 1] = obj->head;
    }

    list_node_t *n;
    n = malloc(sizeof(list_node_t) + ((sizeof(list_node_t *)) * h));
    n->height = h;
    n->val = num;
    n->ref = 1;

    while (--h >= 0) {
        n->next[h] = u[h]->next[h];
        u[h]->next[h] = n;
    }
}

bool skiplistErase(Skiplist *obj, int num)
{
    list_node_t *u[MAX_HEIGHT];
    int search = _skiplistSearch(obj, num, u);

    if (search == -1)
        return false;

    list_node_t *tmp = u[0]->next[0];
    if (tmp->ref > 1) {
        tmp->ref--;
        return true;
    }

    for (int i = obj->height - 1; i >= 0; --i) {
        if (u[i]->next[i] == tmp) {
            u[i]->next[i] = u[i]->next[i]->next[i];
        }
    }

    free(tmp);
    return true;
}

void skiplistFree(Skiplist *obj)
{
    list_node_t *iterator = obj->head;

    if (iterator->next[0])
        iterator = iterator->next[0];
    else
        goto FREE;
    while (iterator) {
        list_node_t *tmp = iterator->next[0];
        free(iterator);
        iterator = tmp;
    }

FREE:
    free(obj->head);
    free(obj);
}
