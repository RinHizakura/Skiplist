#include <stdio.h>
#include <string.h>
#include "linked-list.h"
#include "skiplist.h"

int main()
{
    char *cmd[] = {
        "Skiplist", "add",    "add",    "add",    "add",    "add",    "add",
        "add",      "add",    "add",    "erase",  "search", "add",    "erase",
        "erase",    "erase",  "add",    "search", "search", "search", "erase",
        "search",   "add",    "add",    "add",    "erase",  "search", "add",
        "search",   "erase",  "search", "search", "erase",  "erase",  "add",
        "erase",    "search", "erase",  "erase",  "search", "add",    "add",
        "erase",    "erase",  "erase",  "add",    "erase",  "add",    "erase",
        "erase",    "add",    "add",    "add",    "search", "search", "add",
        "erase",    "search", "add",    "add",    "search", "add",    "search",
        "erase",    "erase",  "search", "search", "erase",  "search", "add",
        "erase",    "search", "erase",  "search", "erase",  "erase",  "search",
        "search",   "add",    "add",    "add",    "add",    "search", "search",
        "search",   "search", "search", "search", "search", "search", "search"};

    int param[] = {0,  16, 5,  14, 13, 0,  3,  12, 9,  12, 3,  6,  7,
                   0,  1,  10, 5,  12, 7,  16, 7,  0,  9,  16, 3,  2,
                   17, 2,  17, 0,  9,  14, 1,  6,  1,  16, 9,  10, 9,
                   2,  3,  16, 15, 12, 7,  4,  3,  2,  1,  14, 13, 12,
                   3,  6,  17, 2,  3,  14, 11, 0,  13, 2,  1,  10, 17,
                   0,  5,  8,  9,  8,  11, 10, 11, 10, 9,  8,  15, 14,
                   1,  6,  17, 16, 13, 4,  5,  4,  17, 16, 7,  14, 1};

    char *out[] = {
        "null",  "null",  "null",  "null",  "null",  "null",  "null",  "null",
        "null",  "null",  "true",  "false", "null",  "true",  "false", "false",
        "null",  "true",  "true",  "true",  "true",  "false", "null",  "null",
        "null",  "false", "false", "null",  "false", "false", "true",  "true",
        "false", "false", "null",  "true",  "true",  "false", "true",  "true",
        "null",  "null",  "false", "true",  "false", "null",  "true",  "null",
        "true",  "true",  "null",  "null",  "null",  "false", "false", "null",
        "true",  "false", "null",  "null",  "true",  "null",  "false", "false",
        "false", "true",  "true",  "false", "true",  "null",  "true",  "false",
        "false", "false", "true",  "true",  "false", "false", "null",  "null",
        "null",  "null",  "true",  "true",  "true",  "true",  "true",  "true",
        "false", "false", "true"};

    Skiplist *obj;
    node_t *head = NULL;
    for (int i = 0; i < 91; i++) {
        if (strcmp(cmd[i], "Skiplist") == 0) {
            obj = skiplistCreate();

            /* do nothing for linked-list */

            if (strcmp(out[i], "null") != 0)
                printf("error at cmd number %d\n", i);

        } else if (strcmp(cmd[i], "add") == 0) {
            skiplistAdd(obj, param[i]);

            add_entry(&head, param[i]);

            if (strcmp(out[i], "null") != 0)
                printf("error at cmd number %d\n", i);

        } else if (strcmp(cmd[i], "erase") == 0) {
            bool p = skiplistErase(obj, param[i]);
            bool p2 = erase_entry(&head, param[i]);

            char *str = p ? "true" : "false";
            if (strcmp(str, out[i]) != 0)
                printf("error at cmd number %d\n", i);

            char *str2 = p2 ? "true" : "false";
            if (strcmp(str2, out[i]) != 0)
                printf("error at cmd number %d\n", i);
        } else if (strcmp(cmd[i], "search") == 0) {
            bool p = skiplistSearch(obj, param[i]);
            bool p2 = find_entry(head, param[i]);

            char *str = p ? "true" : "false";
            if (strcmp(str, out[i]) != 0)
                printf("error at cmd number %d\n", i);

            char *str2 = p2 ? "true" : "false";
            if (strcmp(str2, out[i]) != 0)
                printf("error at cmd number %d\n", i);
        }
    }
    printf("\n");

    skiplistFree(obj);
    return 0;
}
