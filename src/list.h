#ifndef SRC/LIST_H
#define SRC/LIST_H

#include <stddef.h>

typedef struct list_node
{
    struct list_node *next;
    struct list_node *prev;
}List;

#endif //SRC/LIST_H
